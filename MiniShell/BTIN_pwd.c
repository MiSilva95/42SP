/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BTIN_pwd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 19:43:33 by vimafra-          #+#    #+#             */
/*   Updated: 2025/07/30 11:25:53 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int ft_pwd(void)
{
    char *output;
    
    output = getcwd(NULL, 0);
    if (!output)
        return (1);
    printf("%s\n", output);
    string_slayer(1, &output);
    return (0);
}