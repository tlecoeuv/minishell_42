/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlecoeuv <tlecoeuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 13:51:10 by tlecoeuv          #+#    #+#             */
/*   Updated: 2020/06/12 18:12:18 by tlecoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "get_next_line.h"
# include "unistd.h"
# include "stdio.h"

void	big_loop(void);
void 	parse_command(char ***args);
void	execute_command(char **args);
char	**ft_split(char const *s, char c);

#endif
