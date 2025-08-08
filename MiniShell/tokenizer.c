/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mida-sil <mida-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 20:29:33 by mida-sil          #+#    #+#             */
/*   Updated: 2025/08/02 14:50:58 by mida-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	skip_quote(const char *str, int i, char quote)
{
	i++;
	while (str[i] && str[i] != quote)
		i++;
	if (str[i] == quote)
		i++;
	return (i);
}

int	count_tokens(const char *str)
{
	int	i;
	int	count;
	int	op_len; 

	i = 0;
	count = 0;
	while (str[i])
	{
		while (ft_isspace(str[i]))
			i++;
		if (!str[i])
			break ;
		op_len = is_operator_token(str, i);
		if (op_len > 0)
		{
			i += op_len;
			count++;
		}
		else if (str[i] == '\'' || str[i] == '\"')
		{
			i = skip_quote(str, i, str[i]);
			count++;
		}
		else
		{
			while (str[i] && !ft_isspace(str[i]) && !is_operator(str[i])
				&& str[i] != '\'' && str[i] != '\"')
				i++;
			count++;
		}
	}
	return (count);
}

static char	*extract_token_chunk(const char *str, int *i)
{
	int		start;
	char	quote;
	char	*chunk;

	start = *i;
	if (str[*i] == '\'' || str[*i] == '\"')
	{
		quote = str[*i];
		(*i)++;
		start = *i;
		while (str[*i] && str[*i] != quote)
			(*i)++;
		chunk = ft_substr(str, start, *i - start);
		if (str[*i] == quote)
			(*i)++;
	}
	else
	{
		while (str[*i] && !ft_isspace(str[*i]) && str[*i] != '\'' && str[*i] != '\"')
			(*i)++;
		chunk = ft_substr(str, start, *i - start);
	}
	return (chunk);
}

char	*build_normal_token(const char *str, int *i_ptr)
{
	char	*token;
	char	*part;
	char	*tmp;
	int		i;

	i = *i_ptr;
	token = NULL;
	while (str[i] && !ft_isspace(str[i]) && !is_operator(str[i]))
	{
		part = extract_token_chunk(str, &i);
		if (!part)
			return (NULL);
		if (!token)
			token = part;
		else
		{
			tmp = ft_strjoin(token, part);
			free(token);
			free(part);
			token = tmp;
		}
	}
	*i_ptr = i;
	return (token);
}

char	**tokenize_input(char *str)
{
	int		i;
	int		tok_i;
	int		num_tokens;
	char	**tokens;

	i = 0;
	tok_i = 0;
	num_tokens = count_tokens(str);
	tokens = malloc(sizeof(char *) * (num_tokens + 1));
	if (!tokens)
		return (NULL);
	while (str[i])
	{
		while (ft_isspace(str[i]))
			i++;
		if (!str[i])
			break ;
		tokens[tok_i] = get_full_token(str, &i);
		if (!tokens[tok_i])
			return (NULL);
		tok_i++;
	}
	tokens[tok_i] = NULL;
	return (tokens);
}
