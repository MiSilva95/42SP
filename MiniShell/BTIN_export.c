/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BTIN_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:00:43 by vimafra-          #+#    #+#             */
/*   Updated: 2025/07/30 11:25:32 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

t_var_node	*new_usr_var(char *input)
{
	t_var_node	*new_node;
    char *my_input;
    int  separator_index;

	my_input = ft_strdup(input);
    separator_index = 0;
    new_node = (t_var_node *)malloc(sizeof(t_var_node));
	if (!new_node)
		return (NULL);
    while (input[separator_index] != '=')
        separator_index++;
    new_node->name = split_and_substr(my_input, '=', 0);
	new_node->content = dup_from_index(&my_input, (separator_index + 1));
    if (!new_node->name || !new_node->content)
    {
        free(new_node);
        return (NULL);
    }
    new_node->set_status = 1;
    new_node->next = NULL;
	return (new_node);
}

int add_var(t_var_node **list, t_var_node *new)
{
	t_var_node *ptr;
    
    if (!list || !new)
        return (1);
    if (!*list)
		*list = new;
    else
    {
        ptr = *list;
        while(ptr->next)
            ptr = ptr->next;
        ptr->next = new;
    }
    return (0);
}

int ft_export(char **input, t_var_list **structure)
{
    t_var_list  *head;
    t_var_node	*new_node;

    head = *structure;
    new_node = new_usr_var(input[1]);
    if (!new_node)
        return (1);
    return (add_var(&head->usr_var_list, new_node));
}