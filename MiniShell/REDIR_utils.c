/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   REDIR_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mida-sil <mida-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 14:47:18 by vimafra-          #+#    #+#             */
/*   Updated: 2025/08/22 18:18:20 by mida-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void input_or_output(char **info, int **result)
{
    if (ft_strcmp(info[0], ">") == 0 ||\
        ft_strcmp(info[0], ">>") == 0)
    {
        (*result)[0] = 1;
        (*result)[1] = redirect_output(info);
    }
    else if (ft_strcmp(info[0], "<") == 0)
    {
        (*result)[0] = 2;
        (*result)[1] = redirect_input(info);
    }
    else if (ft_strcmp(info[0], "<<") == 0)
    {
        (*result)[0] = 3;
        (*result)[1] = redirect_heredoc(info);
    }
    if ((*result[1] == -1))
        (*result)[0] = -1;        
}

void reset_std(int *info)
{
    if (info[0])
    {
        if (info[0] == 1)
            dup2(info[1], STDOUT_FILENO);
        else if (info[0] == 2 || info[0] == 3)
            dup2(info[1], STDIN_FILENO);
        close(info[1]);
        if (info[0] == 3)
            unlink("/tmp/minishell_heredoc.txt");
    }
    free(info);
}
