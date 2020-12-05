/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlecoeuv <tlecoeuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 15:46:08 by tlecoeuv          #+#    #+#             */
/*   Updated: 2020/12/05 10:55:12 by tanguy           ###   ########.fr       */
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
		return (is_executable(*cmd_name));
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
		bin = norme_all_path(paths[i], cmd_name, &first_error, &result_test);
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

char		*norme_all_path(char *path, char *cmd, char **error, int *res)
{
	char	*ret_bin;

	ret_bin = ft_strjoin_sep(path, cmd, '/');
	*res = test_bin(ret_bin);
	if (*res != 0)
	{
		if (*res == 2 && *error == NULL)
			*error = ft_strdup(ret_bin);
		free(ret_bin);
		ret_bin = NULL;
	}
	return (ret_bin);
}
