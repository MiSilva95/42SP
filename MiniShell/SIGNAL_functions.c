/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SIGNAL_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 14:00:06 by vimafra-          #+#    #+#             */
/*   Updated: 2025/08/19 16:10:55 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _POSIX_C_SOURCE 200809L
#include "includes/minishell.h"

void sigint_handler(int signal)
{
    (void)signal;
    rl_replace_line("", 0);
    write(STDOUT_FILENO, "\n", 1);
    rl_on_new_line();
    rl_redisplay();
}

void signal_handler(void)
{
    struct sigaction sa;

    sa.sa_handler = sigint_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sa, NULL);
}
