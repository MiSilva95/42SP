/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mida-sil <mida-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 13:00:33 by mida-sil          #+#    #+#             */
/*   Updated: 2025/08/22 18:17:38 by mida-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

static void execute_cmd(char **cmd, t_var_list **vars, char *env_path)
{
    int ret = is_built_in(cmd, vars);
    if (ret == 2)
        exec_external(cmd, env_path);
    exit(ret);
}

static void exec_pipe_recursive(char **tokens, t_var_list **vars, char *env_path, int is_parent)
{
    t_parsed_pipe parsed;
    int fd[2];
    pid_t pid;

    parsed = parse_pipe(tokens);
    if (!parsed.has_pipe)
    {
        if (is_parent)
            execute_cmd(tokens, vars, env_path);
        return;
    }
    if (pipe(fd) == -1)
    {
        perror("pipe");
        return;
    }
    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        return;
    }
    if (pid == 0)
    {
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);
        exec_pipe_recursive(parsed.left_cmd, vars, env_path, 1);
        exit(1);
    }
    close(fd[1]);
    pid_t pid2 = fork();
    if (pid2 == 0)
    {
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);
        exec_pipe_recursive(parsed.right_cmd, vars, env_path, 1);
        exit(1);
    }
    close(fd[0]);
    waitpid(pid, NULL, 0);
    waitpid(pid2, NULL, 0);
    free_array(parsed.left_cmd);
    free_array(parsed.right_cmd);
}

void handle_command(char **tokens, t_var_list **variables_list, char **envp, char *env_path)
{
    t_parsed_pipe parsed;

    parsed = parse_pipe(tokens);
	(void)envp;
    if (parsed.has_pipe)
    {
        exec_pipe_recursive(tokens, variables_list, env_path, 0);
        free_array(tokens);
        return;
    }
    int builtin_ret = is_built_in(tokens, variables_list);
    if (builtin_ret == 2)
        exec_external(tokens, env_path);
    free_array(tokens);
}
