/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 10:07:00 by tanguy            #+#    #+#             */
/*   Updated: 2020/10/30 14:56:52 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTION_H
# define REDIRECTION_H

void 	get_redir_and_fd(t_token **lst_token, t_cmd *cmd);
void	get_redir_fd(char *file, t_cmd *cmd, t_type redir_type);
void	do_redir(int in_fd, int out_fd);
void 	skip_redir(t_token **lst_token);
void	builtin_redir(int in_fd, int out_fd, int *save_stdin, int *save_stdout);
void	restore_savefd(int in_fd, int out_fd, int save_stdin, int save_stdout);

#endif
