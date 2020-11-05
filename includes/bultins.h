/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bultins.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlecoeuv <tlecoeuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 14:21:51 by tlecoeuv          #+#    #+#             */
/*   Updated: 2020/10/30 13:14:26 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

#include "minishell.h"

void		ft_cd(char **args);
void		ft_exit(char **args);
void		ft_pwd(char **args);
void		ft_env(char **args);
void		ft_export(char **args);
void		ft_unset(char **args);
int			is_builtin(char	*str);
void 		exec_builtin(t_cmd *cmd);
int			get_len_name(char *env_var);
int			error_identifier(char *name);

#endif
