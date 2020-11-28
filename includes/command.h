/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlecoeuv <tlecoeuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 16:04:09 by tlecoeuv          #+#    #+#             */
/*   Updated: 2020/11/28 11:01:20 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# define READ_END	0
# define WRITE_END	1

typedef struct	s_cmd
{
	char		*bin_path;
	char		**args;
	int			out_fd;
	int			in_fd;
}				t_cmd;

int				test_bin(char *bin);
char			*test_all_path(char **paths, char *args);
char			*norme_all_path(char *path, char *cmd, char **error, int *res);
char			**get_path_split();
int				get_exec_path(char **args);
int				is_executable(char *file);
void			handle_tokens(t_token *lst_token);
t_cmd			**get_commands(t_token **lst_token, int *nb_cmds);
int				get_nb_commands(t_token *lst_token);
void			handle_commands_pipe(t_cmd **cmds, int nb_cmds);
void			spawn_process(int in, int out, t_cmd **cmd, int i);
void			handle_one_command(t_cmd *cmd);
void			handle_command_no_pipe(t_cmd *cmd);
int				get_size_args(t_token *lst_token);
char			**create_cmd_args(t_token **lst_token);
void			exec_cmd(t_cmd *cmd);
void			interpret_v_env(t_token *lst_token);
void			replace_v_env(t_token *lst_token);
void			first_v_env(t_token **lst_token, t_token **previous, int t);
void			one_v_env(t_token **lst_token, t_token **previous, int t);
void			delete_cmd_spaces(t_token *lst_token);
void			free_commands(t_cmd **cmds);

#endif
