/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 18:03:34 by tanguy            #+#    #+#             */
/*   Updated: 2020/11/20 11:30:43 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char		**get_path_split(void)
{
	char	**path_split;
	char	*path;

	path = ft_strdup(ft_getenv("PATH"));
	path_split = ft_split(path, ':');
	free(path);
	return (path_split);
}

int			is_executable(char *file)
{
	struct stat	stats;

	if (stat(file, &stats) == -1)
	{
		error(file, NULL);
		g_sh.status = STATUS_CMD_NOT_FOUND;
	}
	else if (S_ISREG(stats.st_mode) == 0)
		error_not_executable(file, 1);
	else if ((stats.st_mode & S_IXUSR) == 0 || (stats.st_mode & S_IRUSR) == 0)
		error_not_executable(file, 2);
	else
		return (1);
	return (0);
}

int			test_bin(char *bin)
{
	struct stat	stats;

	if (stat(bin, &stats) == -1)
		return (1);
	else if (S_ISREG(stats.st_mode) == 0)
		return (2);
	else if ((stats.st_mode & S_IXUSR) == 0)
		return (2);
	else
		return (0);
}
