/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mida-sil <mida-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:23:14 by mida-sil          #+#    #+#             */
/*   Updated: 2025/08/22 14:47:35 by mida-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include "../libft/libft.h"
#include <fcntl.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

typedef struct s_node
{
	char			*name;
    char			*content;
    int             set_status;
	struct s_node	*next;
}	t_var_node;

typedef struct s_env {
    t_var_node *system_var_list;
    t_var_node *usr_var_list;
    int exit_code;
}   t_var_list;

typedef struct s_parsed_pipe
{
	char	**left_cmd;
	char	**right_cmd;
	int		has_pipe;
}	t_parsed_pipe;

//tokenizer
int     count_tokens(const char *str);
char	**tokenize_input(char *str);
char	*build_normal_token(const char *str, int *i_ptr);

//tokenizer_operator
int	is_operator(char c);
int	is_double_operator(const char *str);
char	*get_full_token(const char *str, int *i_ptr);
int	is_operator_token(const char *str, int i);

//executor
void execute_external(char **tokens, char **envp);

//external_comms
char    *find_executable(char *path, int path_len, char *command);
int exec_external(char **input, char *path);

//ft_pwd
int ft_pwd(void);

//ft_cd
int root_or_absolute(char **curr_input, char **curr_path);
char *remove_last_dir(char *path, int path_len);
int set_new_path(char *curr_input, char *curr_path, char **dir, char **new_path);
int check_access_dir(char *dir, char **curr_path, char *new_path, char *working_dir);
int update_input(char **dir, char **curr_input, char **new_path);
int ft_change_dir(char **input);

//ft_env
int ft_env(t_var_list **structure);

//BTIN_export
t_var_node	*new_usr_var(char *input);
int add_var(t_var_node **list, t_var_node *new);
int ft_export(char **input, t_var_list **structure);

//BTIN_unset
int set_to_null(char *input, t_var_node **list);
int ft_unset(char **input, t_var_list **structure);

//BTIN_system_variables
t_var_node *new_system_var(char *input);
char **system_var_array(void);
int set_system_var(t_var_node **list);

//BTIN_echo
t_var_node *search_list(t_var_node *ptr, char *name);
int print_var(t_var_list **structure, char *input);
int ft_echo(char **input, t_var_list **structure);

//BTIN_exit
int ft_exit(char **input, t_var_list **structure, long long n);

//REDIR_functions
int is_redir(char **input);
char **get_info(char ***input, int index);
int redirect_output(char **redir_info);
int redirect_input(char **redir_info);
int *ft_redir(char ***input);

//REDIR_heredoc
char *join_lines(char *doc, char *new);
int temp_and_switch(char *input);
int redirect_heredoc(char **info);
int heredoc_input(char ***input);

//REDIR utils
char *input_or_output(char **info, int **result);
void reset_std(int *info);

//SIGNAL functions
void sigint_handler(int signal);
void signal_handler(void);

//minishell_utils
void	free_array(char **arr);
void string_slayer(int num, ...);
int count_char(char *path, char c);
char    *split_and_substr(char *str, char c, int i);
char    *append_path(char *path, char *str, int i, int j);
char *dup_from_index(char **str, int index);
void free_linked_list(t_var_list **structure);

//pipe_parser
int				find_pipe(char **tokens);
char			**extract_left(char **tokens, int pipe_index);
char			**extract_right(char **tokens, int pipe_index);
t_parsed_pipe	parse_pipe(char **tokens);

//pipe_exec
void	exec_with_pipe(t_parsed_pipe parsed, char **envp, char *env_path);
void	handle_command(char **tokens, t_var_list **variables_list, char **envp, char *env_path);

#endif