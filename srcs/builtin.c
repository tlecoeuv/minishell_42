/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlecoeuv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 21:40:54 by tlecoeuv          #+#    #+#             */
/*   Updated: 2020/06/15 23:14:09 by tlecoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_cd(char **args)
{
	if (args[1] == NULL)
		printf("pas encore implementer le path home\n");
	else
		if (chdir(args[1]) != 0)
			printf("gerer error\n");
	return (1);
}

int		ft_exit(char **args)
{
	(void) args;
	return (0);
}

