/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mida-sil <mida-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 09:50:57 by mida-sil          #+#    #+#             */
/*   Updated: 2025/06/04 20:55:11 by mida-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	complete_and_reset_char(char **str, char *c, int *bit_c, siginfo_t *info)
{
	char	*temp;

	if (*c == 0)
	{
		ft_printf("%s\n", *str);
		free(*str);
		*c = 0;
		*bit_c = 0;
		*str = NULL;
		kill(info->si_pid, SIGUSR2);
		return (0);
	}
	temp = ft_strjoin(*str, c);
	free(*str);
	*str = temp;
	*c = 0;
	*bit_c = 0;
	return (1);
}

void	build_char_from_signal(int signal, siginfo_t *info, void *context)
{
	static char		c = 0;
	static char		*str = NULL;
	static int		bit_count = 0;

	(void)context;
	c <<= 1;
	if (signal == SIGUSR2)
		c |= 1;
	if (str == NULL)
		str = ft_strdup("");
	bit_count++;
	if (bit_count == 8)
	{
		if (complete_and_reset_char(&str, &c, &bit_count, info) == 0)
			return ;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	s_sigaction;

	ft_printf("Server PID: %d\n", getpid());
	s_sigaction.sa_flags = SA_SIGINFO;
	s_sigaction.sa_sigaction = build_char_from_signal;
	sigaction(SIGUSR1, &s_sigaction, NULL);
	sigaction(SIGUSR2, &s_sigaction, NULL);
	while (1)
		pause();
	return (0);
}
