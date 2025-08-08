/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BTIN_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:11:50 by vimafra-          #+#    #+#             */
/*   Updated: 2025/07/30 11:26:54 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int set_to_null(char *input, t_var_node **list)
{
    t_var_node *ptr;

    ptr = *list;
    while (ptr)
    {
        if (ft_strcmp(ptr->name, input) == 0)
        {
            string_slayer(1, &ptr->content);
            ptr->set_status = 0;
            return (0);
        }
        ptr = ptr->next;
    }
    return (-1);
}

int ft_unset(char **input, t_var_list **structure)
{
    t_var_list *head;
    
    head = *structure;
    if (set_to_null(input[1], &head->system_var_list) == 0)
        return (0);
    else if (set_to_null(input[1], &head->usr_var_list) == 0)
        return (0);
    return (1);
}