/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   REDIR_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 15:13:01 by vimafra-          #+#    #+#             */
/*   Updated: 2025/08/19 16:13:57 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

char *join_lines(char *doc, char *new)
{
    char *result;
    char *linebreak;
    char *temp;
    
    linebreak = "\n";
    if (!doc)
        return (ft_strdup(new));
    result = ft_strjoin(doc, linebreak);
    if (!result)
        return (NULL);
    if (!new)
        return (result);
    temp = result;
    result = ft_strjoin(result, new);
    if (!result)
        return (NULL);
    free(temp);
    return (result);
}

int reset_and_free(char **src, char **new)
{
    char *temp;
    
    temp = NULL;
    temp = *src;
    *src = join_lines(*src, *new);
    if (!(*src))
        return (-1);
    if (temp)
    {
        free(temp);
        temp = NULL;
    }
    if (*new)
    {
        free(*new);
        *new = NULL;
    }
    return (0);
}

int temp_and_switch(char *input)
{
    int fd;
    int temp_stdin;
    int write_status;

    temp_stdin = dup(STDIN_FILENO);
    fd = open("/tmp/minishell_heredoc.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0)
        return (-1);
    write_status =  write(fd, input, ft_strlen(input));
    if (write_status < 0)
        return (-1);
    dup2(fd, STDIN_FILENO);
    close(fd);
    return (temp_stdin);
}

int redirect_heredoc(char **info)
{
    char *line;
    char *doc;
    char *temp;
    int temp_stdin;
    
    doc = NULL;
    line = NULL;
    temp = NULL;
    while (1)
    {
        line = readline(">");
        if (!line)
        {
			printf("minishell: warning: here-document delimited by end-of-file\n");
            break ;
        }
        if (ft_strcmp(line, info[1]) == 0)
            break ;
        reset_and_free(&doc, &line);
    }
    if (!doc)
        return (-1);
    temp = doc;
    doc = join_lines(doc, NULL);
    free(temp);
    temp_stdin = temp_and_switch(doc);
    free(doc);
    return (temp_stdin);
}

int heredoc_input(char ***input)
{
    char **new_input;
    char *path_from_fd;

    path_from_fd = NULL;
    new_input = (char**)malloc(3 * sizeof(char *));
    if (!new_input)
        return (-1);
    new_input[0] = ft_strdup(((*input)[0]));
    if (!new_input[0])
        return (-1);
    path_from_fd = ft_strjoin("/proc/self/fd/", ft_itoa(STDIN_FILENO));
    if (!path_from_fd)
        return (-1);
    new_input[1] = ft_strdup(path_from_fd);
    new_input[2] = NULL;
    free_array((*input));
    free(path_from_fd);
    *input = new_input;
    return (0);    
}

