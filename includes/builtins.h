/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bultins.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlecoeuv <tlecoeuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 14:21:51 by tlecoeuv          #+#    #+#             */
/*   Updated: 2020/11/12 11:10:08 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

int			ft_cd(char **args);
int			ft_exit(char **args);
int			is_valid_number(char *str);
int			is_not_to_big(int sign, char *str);
int			ft_pwd(char **args);
int			ft_env(char **args);
int			ft_export(char **args);
int			ft_unset(char **args);
int			ft_echo(char **args);
int			is_builtin(char *str);
void		exec_builtin(t_cmd *cmd);
int			get_len_name(char *env_var);
int			error_identifier(char *builtin, char *name);
void		set_path_in_env(char *new_pwd, char **oldpwd, char **pwd);
char		*get_path_from_env(char car_path);

#endif
