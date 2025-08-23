/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mida-sil <mida-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 18:52:17 by vimafra-          #+#    #+#             */
/*   Updated: 2025/08/23 10:01:48 by mida-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int is_built_in(char **input, t_var_list **structure)
{
    if (ft_strcmp(input[0], "pwd") == 0)
        return (ft_pwd());
    else if (ft_strcmp(input[0], "cd") == 0)
        return (ft_change_dir(input));
    else if (ft_strcmp(input[0], "env") == 0)
        return (ft_env(structure));
    else if (ft_strcmp(input[0], "export") == 0)
        return (ft_export(input, structure));
    else if (ft_strcmp(input[0], "unset") == 0)
        return (ft_unset(input, structure));
    else if (ft_strcmp(input[0], "echo") == 0)
        return (ft_echo(input, structure));
    else if (ft_strcmp(input[0], "exit") == 0)
        return (ft_exit(input, structure, 0));
    else
        return (2);
}

int main(int argc, char **argv, char **envp)
{
    t_var_list  *variables_list;
    char        *line;
    char        **tokens;
    int         *redir_status;

    (void)argc;
    (void)argv;
    (void)envp;
    variables_list = malloc(sizeof(t_var_list));
    if (!variables_list)
    {
        printf("Erro: malloc de variables_list falhou\n");
        return (1);
    }
    variables_list->system_var_list = NULL;
    variables_list->usr_var_list = NULL;
    if (set_system_var(&variables_list->system_var_list) == -1)
    {
        free(variables_list);
        printf("Erro: set_system_var falhou\n");
        return (1);
    }
    // seta tratamento de SIGINT (CTRL + C)
    signal_handler();
    while (1)
    {
        line = readline("minishell> ");
        if (!line) // CTRL+D
        {
            printf("exit\n");
            free_linked_list(&variables_list);
            exit(0);
        }
        if (*line)
            add_history(line);

        tokens = tokenize_input(line);
        free(line);

        if (!tokens)
        {
            printf("Erro: tokenize_input retornou NULL\n");
            continue;
        }
        if (!tokens[0])
        {
            // printf("Aviso: tokens[0] é NULL\n");
            free(tokens);
            continue;
        }

        // tratamento de redirecionamentos
        redir_status = ft_redir(&tokens);

        // chama handle_command
        handle_command(tokens, &variables_list, NULL, getenv("PATH"));

        // reseta STDOUT se houve redirecionamento
        if (redir_status)
            reset_std(redir_status);
    }
    free_linked_list(&variables_list);
    return (0);
}

// <<<<<<< fork_execve
//     char *input[] = {"mkdir", "TESTE01", NULL};
//     t_var_list *variables_list;
//     int command_type;
    
//     command_type = 0;
//     variables_list = (t_var_list *)malloc(sizeof(t_var_list));
//     if (!variables_list)
//         return (1);
//     variables_list->system_var_list = NULL;
//     variables_list->usr_var_list = NULL;
//     variables_list->exit_code = 0;
//     if (set_system_var(&variables_list->system_var_list) == -1)
//         return (1);
//     command_type = is_built_in(input, &variables_list);
//     if (command_type == 0 || command_type == 1)
//         variables_list->exit_code = command_type;
//     else
//         variables_list->exit_code = exec_external(input, getenv("PATH"));
//     free_linked_list(&variables_list);
//     return (0);
// }
