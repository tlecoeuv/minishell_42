/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlecoeuv <tlecoeuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 15:46:08 by tlecoeuv          #+#    #+#             */
/*   Updated: 2020/11/19 18:21:50 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int			get_exec_path(char **cmd_name)
{
	char	**path_split;
	char	*bin;

	if (ft_strchr(*cmd_name, '/') != -1 || ft_strncmp(*cmd_name, "./", 2) == 0)
		return (is_executable(*cmd_name));
	if ((path_split = get_path_split()) == NULL)
		return (error_cmd_not_found(*cmd_name));
	bin = test_all_path(path_split, *cmd_name);
	free_array(path_split);
	if (!bin)
		return (0);
	free(*cmd_name);
	*cmd_name = bin;
	return (1);
}

char		*test_all_path(char **paths, char *cmd_name)
{
	int		i;
	int		result_test;
	char	*first_error;
	char	*bin;

	i = 0;
	result_test = -1;
	bin = NULL;
	first_error = NULL;
	while (paths[i] && result_test != 0)
	{
		bin = ft_strjoin_sep(paths[i], cmd_name, '/');
		result_test = test_bin(bin);
		if (result_test != 0)
		{
			if (result_test == 2 && first_error == NULL)
				first_error = ft_strdup(bin);
			free(bin);
			bin = NULL;
		}
		i++;
	}
	if (first_error)
	{
		is_executable(first_error);
		free(first_error);
	}
	else if (!bin)
		error_cmd_not_found(cmd_name);
	return (bin);
}
