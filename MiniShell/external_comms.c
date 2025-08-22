/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external_comms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 20:34:31 by vimafra-          #+#    #+#             */
/*   Updated: 2025/08/02 16:14:30 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char *find_executable(char *path, int path_len, char *command)
{
	char *partial_path;
	int partial_len;
	char *test_path;

	test_path = NULL;
	partial_path = split_and_substr(path, ':', 0);
	partial_len = ft_strlen(partial_path) + 1;
	while (partial_len < path_len)
	{
		test_path = append_path(partial_path, command, -1, -1);
		if (access(test_path, F_OK) == 0)
		{
			free(partial_path);
			return (test_path);
		}
		path = path + (ft_strlen(partial_path) + 1);
		string_slayer(1, &partial_path);
		partial_path = split_and_substr(path, ':', 0);
		partial_len += ft_strlen(partial_path) + 1;
		string_slayer(1, &test_path);
	}
	return(NULL);
}

int exec_external(char **input, char *env_path)
{
	int id;
	int status;
	char *path;

	id = fork();
	path = find_executable(env_path, ft_strlen(env_path), input[0]);
	if (id == -1)
		return (1);
	if (id != 0)
		wait(&status);
	else{
		if (execv(path, input) == -1)
			exit(1);
	}
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else
		return (1);
}