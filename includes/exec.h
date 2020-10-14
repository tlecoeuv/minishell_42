/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlecoeuv <tlecoeuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 16:04:09 by tlecoeuv          #+#    #+#             */
/*   Updated: 2020/10/14 19:15:12 by tlecoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

typedef enum	e_redir_type
{
				redir_in,
				redir_out,
				redir_append_out,
				redir_none
}				t_redir_type;

typedef struct		s_cmd
{
	char			**args;
	t_type			redir_type;
	int				redir_fd;
}					t_cmd;

int			test_file(char *file_name);
void		get_absolute_path(char **cmd);
void		handle_tokens(t_token *lst_token);
t_cmd		*get_cmd_from_tok(t_token **lst_token);
int			get_size_cmd(t_token *lst_token);
char		**create_cmd_args(t_token **lst_token, int size);
void		exec_cmd(char **cmd);
void 		get_redir_and_fd(t_token **lst_token, t_cmd *cmd);
int			get_redir_fd(t_token **lst_token, t_type redir_type);

#endif
