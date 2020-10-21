/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:42:29 by tanguy            #+#    #+#             */
/*   Updated: 2020/10/21 09:30:13 by tlecoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

void			init_shell(char **envp);
void			init_env(char **envp);
char			*ft_getenv(char *var);
char			*ft_getfullenv(char *var);
void			remove_env_var(char *var_name);
void			add_env_var(char *var);
void			set_env_var(char *var_name, char *value);

#endif
