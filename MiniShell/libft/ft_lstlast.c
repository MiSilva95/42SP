/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:50:40 by vimafra-          #+#    #+#             */
/*   Updated: 2024/11/09 14:06:37 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*ptr;
	int		list_size;
	int		counter;

	counter = 1;
	list_size = ft_lstsize(lst);
	if (!lst)
		return (NULL);
	if (list_size == 1)
		return (lst);
	ptr = lst;
	while (counter < list_size)
	{
		ptr = ptr->next;
		counter++;
	}
	return (ptr);
}
