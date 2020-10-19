/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlecoeuv <tlecoeuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 14:12:41 by tlecoeuv          #+#    #+#             */
/*   Updated: 2020/10/19 14:28:07 by tlecoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void		ft_cd(char **args)
{
	if (args[1] == NULL)
		printf("pas encore implementer le path home\n");
	else
		if (chdir(args[1]) != 0)
			printf("gerer error\n");
}

void		ft_exit(char **args)
{
	(void) args;
	exit(EXIT_SUCCESS);
}
