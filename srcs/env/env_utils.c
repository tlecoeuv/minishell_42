/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlecoeuv <tlecoeuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 15:54:02 by tlecoeuv          #+#    #+#             */
/*   Updated: 2020/10/09 16:08:14 by tlecoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_getenv(char *var)
{
	int		var_size;
	int		i;
	int		j;

	j = 0;
	i = 0;
	var_size = ft_strlen(var);
	while (g_env[i])
	{
		if (ft_strlen(g_env[i]) > var_size
							&& ft_strncmp(var, g_env[i], var_size) == 0
							&& g_env[i][var_size] == '=')
			return (&g_env[i][ft_strchr(g_env[i], '=') + 1]);
		i++;
	}
	return (NULL);
}
