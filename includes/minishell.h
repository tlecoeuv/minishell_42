/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlecoeuv <tlecoeuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 13:51:10 by tlecoeuv          #+#    #+#             */
/*   Updated: 2020/06/16 11:25:53 by tlecoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "get_next_line.h"
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>

void	big_loop(void);

// parsing
//
void 	parse_command(char ***args, char ***argspiped);

//exec
//
int		exec_args(char **args);
int		exec_argspiped(char **args, char **argspiped);
int		ft_cd(char **args);
int		ft_exit(char **args);
int		launch_process(char **argd);

// utils
//
char	**ft_split(char const *s, char c);
int		ft_strcmp(char *s1, const char *s2);

#endif
