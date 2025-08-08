/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mida-sil <mida-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 14:09:12 by mida-sil          #+#    #+#             */
/*   Updated: 2025/08/02 14:51:54 by mida-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_operator(char c)
{
	return (c == '<' || c == '>' || c == '|');
}

int	is_double_operator(const char *str)
{
	return ((str[0] == '<' && str[1] == '<') || (str[0] == '>' && str[1] == '>'));
}

int	is_operator_token(const char *str, int i)
{
	if (is_double_operator(&str[i]))
		return (2);
	else if (is_operator(str[i]))
		return (1);
	return (0);
}

char	*get_full_token(const char *str, int *i_ptr)
{
	char	*token;
	int		i;
	int		op_len;

	i = *i_ptr;
	op_len = is_operator_token(str, i);
	if (op_len > 0)
	{
		token = ft_substr(str, i, op_len);
		*i_ptr = i + op_len;
		return (token);
	}
	token = build_normal_token(str, &i);
	*i_ptr = i;
	return (token);
}
