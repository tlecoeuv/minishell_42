/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlecoeuv <tlecoeuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 15:46:08 by tlecoeuv          #+#    #+#             */
/*   Updated: 2020/11/13 11:37:16 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int			get_exec_path(char **args)
{
	char	**path_split;
	char	*bin;
	int		i;

	i = 0;
	if (**args == '/' || ft_strncmp(*args, "./", 2) == 0)
		return (is_executable(*args));
	if ((path_split = get_path_split()) == NULL)
		return (error_cmd_not_found(*args));
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
		return (error_cmd_not_found(*args));
	free(*args);
	*args = bin;
	return (1);
}

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
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(file, STDERR_FILENO);
		ft_putstr_fd(": Is a directory\n", STDERR_FILENO);
		g_sh.status = STATUS_NOT_EXECUTABLE;
	}
	else if ((stats.st_mode & S_IXUSR) == 0)
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(file, STDERR_FILENO);
		ft_putstr_fd(": Permission denied\n", STDERR_FILENO);
		g_sh.status = STATUS_NOT_EXECUTABLE;
	}
	else
		return (1);
	return (0);
}

int			test_file(char *file_name)
{
	struct stat	buffer;
	int			exist;

	exist = stat(file_name, &buffer);
	if (exist == 0)
		return (1);
	else
		return (0);
}
