/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mida-sil <mida-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 16:51:30 by mida-sil          #+#    #+#             */
/*   Updated: 2025/08/22 18:17:27 by mida-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int find_pipe(char **tokens)
{
    int i;
	
	i = 0;
    while (tokens[i])
    {
        if (ft_strcmp(tokens[i], "|") == 0)
            return i;
        i++;
    }
    return (-1);
}

char **extract_left(char **tokens, int pipe_index)
{
    char **left;
    int i;

	i = 0;
    left = malloc(sizeof(char *) * (pipe_index + 1));
    if (!left)
        return NULL;
    while (i < pipe_index)
    {
        left[i] = ft_strdup(tokens[i]);
        i++;
    }
    left[i] = NULL;
    return (left);
}

char **extract_right(char **tokens, int pipe_index)
{
    char **right;
    int i;
    int j;
    int count;

	i = pipe_index + 1;
	j = 0;
	count = 0;
    while (tokens[i + count])
        count++;
    right = malloc(sizeof(char *) * (count + 1));
    if (!right)
        return NULL;
    while (tokens[i])
        right[j++] = ft_strdup(tokens[i++]);
    right[j] = NULL;
    return (right);
}

t_parsed_pipe parse_pipe(char **tokens)
{
    t_parsed_pipe parsed;
    int pipe_index;

    pipe_index = find_pipe(tokens);
    parsed.has_pipe = (pipe_index != -1);
    parsed.left_cmd = NULL;
    parsed.right_cmd = NULL;
    if (parsed.has_pipe)
    {
        parsed.left_cmd = extract_left(tokens, pipe_index);
        parsed.right_cmd = extract_right(tokens, pipe_index);
    }
    return (parsed);
}
