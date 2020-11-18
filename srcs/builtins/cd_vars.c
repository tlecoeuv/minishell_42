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

char		*get_path_from_env(char car_path)
{
	char	*path_from_env;
	char	*path_name;

	if (car_path == '-')
		path_name = "OLDPWD";
	else if (car_path == '~')
		path_name = "HOME";
	else
		return (NULL);
	if (!(path_from_env = ft_getenv(path_name)))
	{
		ft_putstr_fd("minishell: cd: ", STDERR_FILENO);
		ft_putstr_fd(path_name, STDERR_FILENO);
		ft_putstr_fd(" not set\n", STDERR_FILENO);
		return (NULL);
	}
	if (!(path_from_env = ft_strdup(path_from_env)))
		return (NULL);
	return (path_from_env);
}

void		set_path_in_env(char *new_pwd, char **oldpwd, char **pwd)
{
	char	*temp;

	*oldpwd = ft_strdup(ft_getenv("PWD"));
	*pwd = getcwd(NULL, 0);
	if (!*oldpwd || !*pwd)
		return ;
	if (!ft_strncmp("//", new_pwd, 2) && ft_strncmp("///", new_pwd, 3))
	{
		temp = *pwd;
		*pwd = ft_strjoin("/", temp);
		free(temp);
	}
}
