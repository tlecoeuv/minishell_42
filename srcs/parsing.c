/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 16:07:35 by tanguy            #+#    #+#             */
/*   Updated: 2020/06/16 10:40:57 by tlecoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void parse_command(char ***args, char ***argspiped)
{
	char *line;
	char **str_args;

	get_next_line(0, &line);
	str_args = ft_split(line, '|');
	*args = ft_split(str_args[0], ' ');
	if (str_args[1])
		*argspiped = ft_split(str_args[1], ' ');
	free(str_args);
	free(line);
}
