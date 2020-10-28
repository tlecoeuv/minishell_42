/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bultins.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlecoeuv <tlecoeuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 14:21:51 by tlecoeuv          #+#    #+#             */
/*   Updated: 2020/10/28 16:23:59 by tlecoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

#include "minishell.h"

void		ft_cd(char **args);
void		ft_exit(char **args);
void		ft_pwd(char **args);
int			is_builtin(char	*str);
void 		exec_builtin(t_cmd *cmd);
void		do_builtin_redir(t_type redir_type, int fd, int *savefd);
void		restore_savefd(t_type redir_type, int redir_fd, int savefd);

#endif
