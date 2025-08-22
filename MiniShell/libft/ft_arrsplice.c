/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrsplice.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 18:52:17 by vimafra-          #+#    #+#             */
/*   Updated: 2025/08/02 16:52:04 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void free_strarr(char ***str)
{
    int i;

    i = 0;
    while ((*str)[i] != NULL)
    {
        free((*str)[i]);
        (*str)[i] = NULL;
        i++;
    }
    free(*str);
}

int ft_arrsplice(char ***str, int index, int num)
{
    char **result;
    int len;
    int i;

    i = -1;
    len = 0;
    while((*str)[len] != NULL)
        len++;
    result = (char **)malloc((len - num + 1) * sizeof(char *));
    if (!result)
        return (-1);
    while (++i < index)
        result[i] = ft_strdup((*str)[i]);
    while (i < (len - num))
    {
        result[i] = ft_strdup((*str)[index + num]);
        i++;
        index++;
    }
    result[i] = NULL;
    free_strarr(str);
    *str = result;   
    return (0);
}