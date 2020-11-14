/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlecoeuv <tlecoeuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 14:12:41 by tlecoeuv          #+#    #+#             */
/*   Updated: 2020/10/21 17:40:23 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		ft_echo(char **args)
{
	int		i;
	int		new_line;
	int		size;

	i = -1;
	new_line = 1;
	size = get_array_size(args);
	if (size > 1)
	{
		i++;
		while (++i < size)
		{
			if (!ft_strcmp(args[i], "-n") && i == 1)
				new_line = 0;
			else
			{
				ft_putstr_fd(args[i], STDOUT_FILENO);
				if (i != size - 1)
					ft_putstr_fd(" ", STDOUT_FILENO);
			}
		}
	}
	if (new_line)
		ft_putstr_fd("\n", STDOUT_FILENO);
	return (STATUS_SUCCESS);
}
