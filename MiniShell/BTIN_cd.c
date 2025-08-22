/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BTIN_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 19:19:31 by vimafra-          #+#    #+#             */
/*   Updated: 2025/07/30 11:23:42 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int root_or_absolute(char **curr_input, char **curr_path)
{
    if ((*curr_input)[0] != '/' && (*curr_input)[0] != '~' && (*curr_input)[0] != '\0')
        return (0);
    if ((*curr_input)[0] == '/')
        chdir("/");
    else if ((*curr_input)[0] == '~' || (*curr_input)[0] == '\0')
        chdir(getenv("HOME"));
    if ((*curr_input)[1] != '\0')
    {
        string_slayer(1, curr_path);
        *curr_path = getcwd(NULL, 0);
        if (!(*curr_path))
            return (-1);
    }
    *curr_input = dup_from_index(curr_input, 1);
    if (!(*curr_input))
        return (-1);
    return (0);
}

int input_and_path(char **input, char **working_dir, char **curr_input, char **curr_path)
{  
    if (input[1])
        *curr_input = ft_strdup(input[1]);
    else
        *curr_input = ft_strdup("");
    if (!(*curr_input))
        return (-1);
    while ((*curr_input)[0] == '.' && (*curr_input)[1] == '/')
    {
        *curr_input = dup_from_index(curr_input, 2);
        if (!(*curr_input))
            return (-1);
    }
    if (root_or_absolute(curr_input, curr_path) == -1)
    {
        string_slayer(3, &working_dir, &curr_input, &curr_path);
        return (-1);
    }
    return (0);
}

char *remove_last_dir(char *path, int path_len)
{
    char *result;
    int i;
    int index;

    i = path_len - 1;
    while (path[i] != '/')
        i--;
    index = i;
    result = (char *)malloc((index + 1)* sizeof(char));
    if (!result)
        return (NULL);
    i = -1;
    while (++i < index)
        result[i] = path[i];
    result[i] = '\0';
    return(result);
}

int set_new_path(char *curr_input, char *curr_path, char **dir, char **new_path)
{
    if (*new_path != NULL)
        string_slayer(1, new_path);
    *dir = split_and_substr(curr_input, '/', 0);
    if (ft_strcmp(*dir, ".") == 0)
        *new_path = ft_strdup(curr_path);
    else if (ft_strcmp(*dir, "..") == 0)
        *new_path = remove_last_dir(curr_path, ft_strlen(curr_path));
    else
        *new_path = append_path(curr_path, *dir, -1, -1);
    if (!(*new_path))
        return (-1);
    return (0);
}

int check_access_dir(char *dir, char **curr_path, char *new_path, char *working_dir)
{
    if (access(new_path, F_OK) == -1)
    {
        printf("minishell: cd: %s: No such file or directory\n", dir);
        chdir(working_dir);
        return (-1);  
    }
    chdir(new_path);
    string_slayer(1, curr_path);
    *curr_path = ft_strdup(new_path);
    return (0);
}

int update_input(char **dir, char **curr_input, char **new_path)
{
    if (count_char(*curr_input, '/') == 0)
        *curr_input = dup_from_index(curr_input, ft_strlen(*dir));
    else
        *curr_input = dup_from_index(curr_input, (ft_strlen(*dir) + 1));
    if (!(*curr_input))
        return (-1);
    string_slayer(2, dir, new_path);
    return (0);
}

int ft_change_dir(char **input)
{
    char *working_dir;
    char *dir;
    char *curr_path;
    char *new_path;
    char *curr_input;

    dir = NULL;
    new_path = NULL;
    curr_input = NULL;
    working_dir = getcwd(NULL, 0);
    curr_path = ft_strdup(working_dir);
    if (input_and_path(input, &working_dir ,&curr_input, &curr_path) == -1)
        return (1);
    while (curr_input[0] != '\0')
    {
        if (set_new_path(curr_input, curr_path, &dir, &new_path) == -1 \
            || check_access_dir(dir, &curr_path, new_path, working_dir) == -1 \
            || update_input(&dir, &curr_input, &new_path) == -1)
        {
            string_slayer(4, &dir, &curr_input, &curr_path, &new_path);
            return (1);
        }
    }
    string_slayer(3, &working_dir, &curr_input, &curr_path);
    return (0);
}