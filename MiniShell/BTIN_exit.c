/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BTIN_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 10:27:36 by vimafra-          #+#    #+#             */
/*   Updated: 2025/07/30 14:50:02 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int input_args(char **input)
{
    int i;

    i = 0;
    while (input[i])
        i++;
    return (i);
}

int set_exit_code(char *input, long long n)
{
    int result;
    unsigned long long ull_exit_code;

    result = 0;
    if (ft_atoi(input, &n) == NULL)
    {
        {
            printf("minishell: exit: a numeric argument required\n");
            result = 2;
        }
    }
    else if (n < 0)
    {
        ull_exit_code = (unsigned long long)n;
        ull_exit_code = ull_exit_code % 256;
        result = (int)ull_exit_code;
    }
    else
    {
        n = n % 256;
        result = (int)n;
    }
    return (result);
}

int ft_exit(char **input, t_var_list **structure, long long n)
{
    t_var_list *head;
    int exit_code;

    head = *structure;
    if (input_args(input) > 2)
    {
        printf("minishell: exit: too many arguments\n");
        return (1);
    }
    else
    {
        printf("exit\n");
        if (input[1])
            exit_code = set_exit_code(input[1], n);
        else
            exit_code = head->exit_code;
        free_linked_list(structure);
        exit(exit_code);
    }
    return (1);
}