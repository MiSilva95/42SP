/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   REDIR_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 16:24:45 by vimafra-          #+#    #+#             */
/*   Updated: 2025/08/19 16:17:40 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int is_redir(char **input)
{
    int index;

    index = 0;
    while (input[index] != NULL)
    {
        if (ft_strcmp(input[index], ">") == 0 || ft_strcmp(input[index], "<") == 0\
            || ft_strcmp(input[index], ">>") == 0 || ft_strcmp(input[index], "<<") == 0)
            break ;
        index++;
    }
    if (!input[index])
        return (0);
    return (index);
}

char **get_info(char ***input, int index)
{
    char **redir_info;

    if (!(*input)[index + 1])
    {
        printf("minishell: parse error near \\n \n");
        return (NULL);
    }
    redir_info = (char **)malloc(3 * sizeof(char *));
    if (!redir_info)
        return (NULL);
    redir_info = ft_substrarr(*input, index, 2);
    ft_arrsplice(input, index, 2);
    if (!redir_info)
        return (NULL);
    return (redir_info);
}

int redirect_output(char **redir_info)
{
    int fd;
    int temp_stdout;
    
    temp_stdout = dup(STDOUT_FILENO);
    if (ft_strcmp(redir_info[0], ">") == 0)
        fd = open(redir_info[1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
    else if (ft_strcmp(redir_info[0], ">>") == 0)
        fd = open(redir_info[1], O_CREAT | O_WRONLY | O_APPEND, 0644);
    if (fd == -1)
        return (-1);
    dup2(fd, STDOUT_FILENO);
    close(fd);
    return (temp_stdout);
}

int redirect_input(char **redir_info)
{
    int fd;
    int temp_stdin;
    char *path;
    char *file_path;

    temp_stdin = dup(STDIN_FILENO); 
    file_path = NULL;
    path = getcwd(NULL, 0);
    if (!path)
        return (-1);
    file_path = ft_strjoin(path, "/");
    string_slayer(1, &path);
    path = file_path;
    file_path = ft_strjoin(path, redir_info[1]);
    string_slayer(1, &path);
    if (access(file_path, F_OK) != 0)
        return (-1);
    fd = open(redir_info[1], O_RDONLY, 0444);
    if (fd == -1)
        return (-1);
    dup2(fd, STDIN_FILENO);
    close(fd);
    return (temp_stdin);
}

int *ft_redir(char ***input)
{
    int index;
    char **redir_info;
    int *result;

    redir_info = NULL;
    index = is_redir(*input);
    if (index == 0)
        return (NULL);
    redir_info = get_info(input, index);
    result = (int *)malloc(2 * sizeof(int));
    if (!redir_info || !result)
    {   
        if (result) 
            free(result);
        return (NULL);
    }
    input_or_output(redir_info, &result);
    if (result[0] == 3 && !(*input)[1])
        heredoc_input(input);
    if (result[0] == -1)
    {
        free(result);
        return (NULL);
    }
    free_array(redir_info);
    return (result);
}