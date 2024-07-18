/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:53:36 by jteissie          #+#    #+#             */
/*   Updated: 2024/07/18 12:55:40 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H
# include <errno.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include "minishell.h"
# define PATH_ERROR 127
# define EXIT_FAILURE 1
# define CHILD 0
# define PARENT 1

typedef struct s_varlist		t_varlist;

void	trash(char **array);
void	handle_error(char *message, int code);
void	execute_cmd(char *cmd, t_data *data, t_parser *parser);
char	**build_env(t_varlist *vars);

int		process_files(t_parser *table);
int		get_redirections(t_parser *roaming, char *redirection[]);
void	check_pipes(t_parser *table, int pipe_status[]);

int		execute_data(t_data *data);
int		execute_commands(t_data *data, int std_fds[]);
int		process_command(t_parser *p, t_data *data, int std_fd[]);
int		redir_child(t_parser *p, int p_fd[], int has_pipe[], int std_fd[]);

#endif
