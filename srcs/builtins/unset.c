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

void		ft_unset(char **args)
{
	int		size;
	int		i;

	size = get_array_size(args);
	i = 0;
	while (++i < size)
	{
		if (!error_identifier(args[i]))
			return ;
		remove_env_var(args[i]);
	}
}
