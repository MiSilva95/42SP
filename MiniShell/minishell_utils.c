/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mida-sil <mida-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 18:21:40 by vimafra-          #+#    #+#             */
/*   Updated: 2025/08/22 17:15:43 by mida-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	free_array(char **arr)
{
	int i = 0;
	if (!arr)
		return;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void string_slayer(int num, ...)
{
	va_list args;
	char **str;
	int i;

	i = 0;
	va_start(args, num);
	while (i < num)
	{
		str = va_arg(args, char **);
		if (str && *str)
		{
			free(*str);
			*str = NULL;
		}
		i++;
	}
	va_end(args);
}

int count_char(char *path, char c)
{
    int i;
    int counter;

    i = -1;
    counter = 0;
    while (path[++i] != '\0')
    {
        if (path[i] == c)
            counter++;
    }
    return (counter);
}

char *split_and_substr(char *str, char c, int i)
{
	char *result;
	int index;
	
	result = NULL;
    if (str[0] == '\0')
		return (str);
	while (str[i] != c && str[i] != '\0')
		i++;
	result = (char *)malloc((i + 1) * sizeof(char));
	if (!result)
		return (NULL);
	index = i;
	i = -1;
	while (++i < index)
		result[i] = str[i];
	result[i] = '\0';
	return (result);		
}

char *append_path(char *path, char *str, int i, int j)
{
	int len_path;
	int len_str;
	char *result;

	len_path = ft_strlen(path);
	len_str = ft_strlen(str);
	result = (char *)malloc((len_path + len_str + 2) * sizeof(char));
	if (!result)
		return (NULL);
	while (i < len_path)
		result[++j] = path[++i];
	i = -1;
	if (result[j - 1] != '/')
		result[j] = '/';
	else
		j--;
	while (i < len_str)
		result[++j] = str[++i];
	result[j] = '\0';
	return(result);
}

char *dup_from_index(char **str, int index)
{
	int i;
	char *result;

	i = 0;
	result = (char *)malloc(((ft_strlen(*str) - index) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while ((*str)[index] != '\0')
	{
		result[i] = (*str)[index];
		i++;
		index++;
	}
	result[i] = '\0';
	string_slayer(1, str);
	return (result);
}

void free_linked_list(t_var_list **structure)
{
	t_var_list *head;
    t_var_node *ptr;
	t_var_node *aux;

	if (!structure || !*structure)
        return;
	head = *structure;
	ptr = head->system_var_list;
	while (ptr)
	{
		string_slayer(2, &ptr->name, &ptr->content);
		aux = ptr->next;
		free(ptr);
		ptr = aux;
	}
	ptr = head->usr_var_list;
	while (ptr)
	{
		string_slayer(2, &ptr->name, &ptr->content);
		aux = ptr->next;
		free(ptr);
		ptr = aux;
	}
	free(head);
	*structure = NULL;
}

t_var_list	*init_variables(void)
{
	t_var_list	*variables_list;

	variables_list = malloc(sizeof(t_var_list));
	if (!variables_list)
	{
		printf("Erro: malloc de variables_list falhou\n");
		return (NULL);
	}
	variables_list->system_var_list = NULL;
	variables_list->usr_var_list = NULL;
	if (set_system_var(&variables_list->system_var_list) == -1)
	{
		printf("Erro: set_system_var falhou\n");
		free(variables_list);
		return (NULL);
	}
	return (variables_list);
}

char	*prompt_line(void)
{
	char	*line;

	line = readline("minishell> ");
	if (!line)
		return (NULL);
	if (*line)
		add_history(line);
	return (line);
}