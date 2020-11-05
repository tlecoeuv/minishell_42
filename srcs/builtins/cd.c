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

char		*get_new_pwd(char *arg)
{
	char	*from_home;
	char	*path;
	char	*result;

	from_home = NULL;
	if (*arg == '~')
	{
		if (!(from_home = get_path_from_env('~')))
			return (NULL);
		arg++;
	}
	if (!(path = ft_strdup(arg)))
		return (NULL);
	if (from_home)
	{
		if (!(result = ft_strjoin_sep(from_home, path, '/')))
			return (NULL);
		free(from_home);
		free(path);
	}
	else
		result = path;
	return (result);
}

void		change_directory(char *new_pwd, char *arg)
{
	char	*oldpwd;
	char	*pwd;

	if (chdir(new_pwd) == -1)
	{
		g_sh.status = 1;
		error("cd", arg);
	}
	else
	{
		g_sh.status = 0;
		if (!(oldpwd = ft_strdup(ft_getenv("PWD"))))
			return ;
		if (!(pwd = getcwd(NULL, 0)))
			return ;
		set_env_var("OLDPWD", oldpwd);
		set_env_var("PWD", pwd);
		free(oldpwd);
		free(pwd);
	}
}

void		ft_cd(char **args)
{
	char	*new_pwd;
	int		size;

	size = get_array_size(args) - 1;
	if (size > 1)
		ft_putstr_fd("minishell: cd: too many arguments\n", STDERR_FILENO);
	else
	{
		if (!ft_strcmp("-", args[size]))
		{
			if ((new_pwd = get_path_from_env('-')))
			{
				ft_putstr_fd(ft_getenv("OLDPWD"), STDOUT_FILENO);
				ft_putstr_fd("\n", STDOUT_FILENO);
			}
		}
		else if (size)
			new_pwd = get_new_pwd(args[size]);
		else
			new_pwd = get_path_from_env('~');
		if (!new_pwd)
			return ;
		change_directory(new_pwd, args[size]);
		free(new_pwd);
	}
}
