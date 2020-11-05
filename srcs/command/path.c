/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlecoeuv <tlecoeuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 15:46:08 by tlecoeuv          #+#    #+#             */
/*   Updated: 2020/11/04 11:10:58 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		get_absolute_path(char **args)
{
	char	*path;
	char	**path_split;
	char	*bin;
	int		i;

	i = 0;
	if (**args == '/' || ft_strncmp(*args, "./", 2) == 0)
		return (1);
	path = ft_strdup(ft_getenv("PATH"));
	path_split = ft_split(path, ':');
	free(path);
	while (path_split[i] && !test_file(bin))
	{
		bin = ft_strjoin_sep(path_split[i], *args, '/');
		if (!test_file(bin))
		{
			free(bin);
			bin = NULL;
		}
		i++;
	}
	free_array(path_split);
	if (!bin)
		return (0);
	free(*args);
	*args = bin;
	return (1);
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
