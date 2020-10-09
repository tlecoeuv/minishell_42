/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlecoeuv <tlecoeuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 15:46:08 by tlecoeuv          #+#    #+#             */
/*   Updated: 2020/10/09 15:55:09 by tlecoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
