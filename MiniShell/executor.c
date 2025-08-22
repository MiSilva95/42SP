/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:15:37 by marvin            #+#    #+#             */
/*   Updated: 2025/07/26 19:15:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void execute_external(char **tokens, char **envp)
{
    char *path = getenv("PATH");
    char **dirs = ft_split(path, ':');
    char *full_path = NULL;
    int i = 0;

    if (!dirs || !tokens[0])
        return;

    while (dirs[i])
    {
        full_path = append_path(dirs[i], tokens[0], -1, -1);
        if (access(full_path, X_OK) == 0)
        {
            execve(full_path, tokens, envp);
            perror("execve failed");
            exit(1);
        }
        free(full_path);
        i++;
    }
    printf("minishell: command not found: %s\n", tokens[0]);
    exit(127);
}