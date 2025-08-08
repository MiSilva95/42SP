/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BTIN_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 10:52:30 by vimafra-          #+#    #+#             */
/*   Updated: 2025/07/30 11:24:50 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int ft_env(t_var_list **structure)
{
    t_var_list *head;
    t_var_node *ptr_sys;
    t_var_node *ptr_usr;

    head = *structure;
    ptr_sys = head->system_var_list;
    ptr_usr = head->usr_var_list;
    if (!head || !ptr_sys)
        return (1);
    while(ptr_sys)
    {
        if (ptr_sys->set_status)
            printf("%s=%s\n", ptr_sys->name, ptr_sys->content);
        ptr_sys = ptr_sys->next;
    }
    if (ptr_usr)
    {
        while(ptr_usr)
        {
            if (ptr_usr->set_status)
                printf("%s=%s\n", ptr_usr->name, ptr_usr->content);
            ptr_usr = ptr_usr->next; 
        }
    }
    return (0);
}