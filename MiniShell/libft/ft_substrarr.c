/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplice.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 11:54:59 by vimafra-          #+#    #+#             */
/*   Updated: 2025/08/13 12:19:21 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// checa se os argumentos passados são válidos
// se forem, retorna o tamanho da array passada
static int get_len(char **str, int index, int num)
{
    int arr_len;

    arr_len = 0;
    if (!str || index < 0 || num < 0)
        return (-1);
    while (str[arr_len] != NULL)
        arr_len++;
    if (index >= arr_len || index + (num - 1) >= arr_len)
        return (-1);
    return (arr_len);
}

char **ft_substrarr(char **str, int index, int num)
{
    char **result;
    int arr_len;
    int i;

    i = 0;
    arr_len = get_len(str, index, num);
    if (arr_len == -1)
        return (NULL);
    result = (char **)malloc((num + 1) * sizeof(char *));
    while (i < num)
    {
        result[i] = ft_strdup(str[index]);
        if (!result[i])
            return (NULL);
        i++;
        index++;
    }
    result[i] = NULL;
    return (result);
}