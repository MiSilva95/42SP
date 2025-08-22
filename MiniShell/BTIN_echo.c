/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BTIN_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 17:40:49 by vimafra-          #+#    #+#             */
/*   Updated: 2025/08/02 17:12:35 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

t_var_node *search_list(t_var_node *ptr, char *name)
{
    while(ptr)
    {
        if (ft_strcmp(ptr->name, name) == 0 && ptr->set_status)
            return (ptr);
        ptr = ptr->next;
    }
    return (ptr);
}

int print_var(t_var_list **structure, char *input)
{
    t_var_list *head;
    t_var_node *ptr;
    char *name;

    head = *structure;
    ptr = head->system_var_list;
    name = ft_strdup(input);
    name = dup_from_index(&name, 1);
    ptr = search_list(ptr, name);
    if (!ptr)
    {
        if (head->usr_var_list)
        {
            ptr = head->usr_var_list;
            ptr = search_list(ptr, name);
        }
    }
    free(name);
    if (!ptr)
        return (-1);
    printf("%s", ptr->content);
    return (0);
}

void arg_type(char **input, int index, t_var_list **structure)
{
    if (input[index][0] == '$')
    {
        if (print_var(structure, input[index]) == 0)
        {
            if (input[index + 1])
            printf(" ");
        }
    }
    else
    {
        printf("%s", input[index]);
        if (input[index + 1])
            printf(" ");
    }
}

int ft_echo(char **input, t_var_list **structure)
{
    int i;
    int args_index;
    t_var_list *head;

    args_index = 1;
    head = *structure;
    if (input[1] && ft_strcmp(input[1], "-n") == 0)
        args_index = 2;
    i = args_index;
    if (ft_strcmp(input[i], "$?") == 0)
        printf("%d",head->exit_code);
    else
    {
        while (input[i] != NULL)
        {
            arg_type(input, i, structure);
            i++;
        } 
    }
    if (args_index == 1)
        printf("\n");
    return (0);
}