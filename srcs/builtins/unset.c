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

void		is_env(char *var, int *index)
{
	int		i;

	i = -1;
	while (g_sh.env[++i])
		if (!(ft_strncmp(var, g_sh.env[i], ft_strlen(var))))
		{
			*index = i;
			return ;
		}
	*index = -1;
}

void		*remove_index_of_env(int index)
{
	int		size;
	char	**new_env;
	int		i;
	int		j;

	size = get_array_size(g_sh.env);
	if (!(new_env = malloc(sizeof(char *) * size)))
		return (NULL);
	i = -1;
	j = 0;
	while (g_sh.env[++i])
	{
		if (i != index)
			new_env[j++] = g_sh.env[i];
		else
		{
			free(g_sh.env[i]);
			g_sh.env[i] = NULL;
		}
	}
	new_env[j] = NULL;
	free(g_sh.env);
	g_sh.env = new_env;
	return (new_env);
}

int			ft_unset(char **args)
{
	int		size;
	int		i;
	int		index;
	int		status;

	status = 0;
	index = -1;
	size = get_array_size(args);
	i = 0;
	while (++i < size)
	{
		if (error_identifier("unset", args[i]))
		{
			is_env(args[i], &index);
			if ((index != -1))
				if (!remove_index_of_env(index))
					return (STATUS_FAILURE);
		}
		else
			status += 1;
	}
	if (status)
		return (STATUS_FAILURE);
	return (STATUS_SUCCESS);
}
