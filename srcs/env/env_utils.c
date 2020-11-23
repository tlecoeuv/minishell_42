/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlecoeuv <tlecoeuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 15:54:02 by tlecoeuv          #+#    #+#             */
/*   Updated: 2020/11/23 12:32:55 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_getenv(char *var)
{
	int		var_size;
	int		i;

	i = 0;
	var_size = ft_strlen(var);
	if (var_size == 1 && var[0] == '?')
		return (ft_itoa(g_sh.status));
	while (g_sh.env[i])
	{
		if (ft_strlen(g_sh.env[i]) > var_size
							&& ft_strncmp(var, g_sh.env[i], var_size) == 0
							&& g_sh.env[i][var_size] == '=')
			return (&(g_sh.env[i][ft_strchr(g_sh.env[i], '=') + 1]));
		i++;
	}
	return (NULL);
}

void	add_env_var(char *var)
{
	char	**new_env;
	int		i;

	i = 0;
	if (!(new_env = malloc((get_array_size(g_sh.env) + 2) * sizeof(char *))))
		return ;
	while (g_sh.env[i])
	{
		new_env[i] = g_sh.env[i];
		i++;
	}
	new_env[i++] = ft_strdup(var);
	new_env[i] = NULL;
	free(g_sh.env);
	g_sh.env = new_env;
}

void	set_env_var(char *var_name, char *value)
{
	int		i;
	char	*to_add;
	int		var_size;

	var_size = ft_strlen(var_name);
	i = 0;
	to_add = ft_strjoin_sep(var_name, value, '=');
	if (!ft_getenv(var_name))
	{
		add_env_var(to_add);
		free(to_add);
	}
	else
		while (g_sh.env[i])
		{
			if (ft_strlen(g_sh.env[i]) > var_size
							&& ft_strncmp(var_name, g_sh.env[i], var_size) == 0
							&& g_sh.env[i][var_size] == '=')
			{
				free(g_sh.env[i]);
				g_sh.env[i] = to_add;
				return ;
			}
			i++;
		}
}
