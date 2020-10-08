/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlecoeuv <tlecoeuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 15:46:08 by tlecoeuv          #+#    #+#             */
/*   Updated: 2020/10/08 17:50:54 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_getenv(char *var)
{
	int		var_size;
	int		i;

	i = 0;
	var_size = ft_strlen(var);
	while (g_env[i])
	{
		if (ft_strlen(g_env[i]) > var_size
							&& ft_strncmp(var, g_env[i], var_size) == 0
							&& g_env[i][var_size] == '=')
			return (g_env[i]);
		i++;
	}
	return (NULL);
}

void	get_absolute_path(char **cmd)
{
	char	*path;
	char	**path_split;
	char	*bin;
	int		i;

	i = 0;
	if (**cmd == '/' || ft_strncmp(*cmd, "./", 2) == 0)
		return ;
	path = ft_strdup(ft_getenv("PATH"));
	path_split = ft_split(path, ':');
	free(path);
	while (path_split[i] && !test_file(bin))
	{
		bin = ft_strjoin_sep(path_split[i], *cmd, '/');
		if (!test_file(bin))
		{
			free(bin);
			bin = NULL;
		}
		i++;
	}
	free_array(path_split);
	free(*cmd);
	*cmd = bin;
}

int		test_file(char *file_name)
{
	struct stat	buffer;
	int			exist;

	exist = stat(file_name, &buffer);
	if (exist == 0)
		return (1);
	else
		return (0);
}
