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

int			change_directory(char *new_pwd, char *arg)
{
	char	*oldpwd;
	char	*pwd;
	int		status;

	if (chdir(new_pwd) == -1)
	{
		error("cd", arg);
		return (STATUS_FAILURE);
	}
	set_path_in_env(new_pwd, &oldpwd, &pwd);
	status = STATUS_SUCCESS;
	if (oldpwd && pwd)
	{
		set_env_var("OLDPWD", oldpwd);
		set_env_var("PWD", pwd);
	}
	else
		status = STATUS_FAILURE;
	if (oldpwd)
		free(oldpwd);
	if (pwd)
		free(pwd);
	return (status);
}

int			manage_cd(char *arg, int size)
{
	char	*new_pwd;
	int		status;

	if (!size)
		new_pwd = get_path_from_env('~');
	else if (!ft_strcmp("-", arg))
	{
		if ((new_pwd = get_path_from_env('-')))
		{
			ft_putstr_fd(ft_getenv("OLDPWD"), STDOUT_FILENO);
			ft_putstr_fd("\n", STDOUT_FILENO);
		}
	}
	else
		new_pwd = get_new_pwd(arg);
	if (!new_pwd)
		return (STATUS_FAILURE);
	status = change_directory(new_pwd, arg);
	free(new_pwd);
	return (status);
}

int			ft_cd(char **args)
{
	int		size;
	int		status;

	size = get_array_size(args) - 1;
	if (size > 1)
	{
		status = error_from_builtin("cd:", " too many arguments\n",
													STATUS_FAILURE);
		return (status);
	}
	if (size)
		if (!ft_strlen(args[1]))
			return (STATUS_SUCCESS);
	return (manage_cd(args[size], size));
}
