/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mida-sil <mida-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 13:00:33 by mida-sil          #+#    #+#             */
/*   Updated: 2025/08/22 14:48:38 by mida-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	child_left(t_parsed_pipe parsed, int fd[2], char *env_path)
{
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	exec_external(parsed.left_cmd, env_path);
	exit(1);
}

static void	child_right(t_parsed_pipe parsed, int fd[2], char *env_path)
{
	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);
	close(fd[0]);
	exec_external(parsed.right_cmd, env_path);
	exit(1);
}

void	exec_with_pipe(t_parsed_pipe parsed, char **envp, char *env_path)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;

	(void)envp;
	if (pipe(fd) == -1)
	{
		perror("pipe");
		return;
	}
	pid1 = fork();
	if (pid1 == 0)
		child_left(parsed, fd, env_path);
	pid2 = fork();
	if (pid2 == 0)
		child_right(parsed, fd, env_path);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

void	handle_command(char **tokens, t_var_list **variables_list, char **envp, char *env_path)
{
	t_parsed_pipe	parsed;
	int				builtin_ret;

	parsed = parse_pipe(tokens);
	if (parsed.has_pipe)
	{
		exec_with_pipe(parsed, envp, env_path);
		free_array(parsed.left_cmd);
		free_array(parsed.right_cmd);
		free_array(tokens);
		return;
	}
	builtin_ret = is_built_in(tokens, variables_list);
	if (builtin_ret == 2)
		exec_external(tokens, env_path);
	free_array(tokens);
}