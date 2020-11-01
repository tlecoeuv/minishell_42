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

void		replace_dots(char **cd_array)
{
	int		i;
	int		j;

	i = -1;
	while (cd_array[++i])
		if (*cd_array[i] == '.')
		{
			j = i;
			if (!ft_strncmp(cd_array[i], "..", 2))
			{
				while (--j)
				{
					if (ft_strlen(cd_array[j]))
					{
						if (cd_array[j])
							free(cd_array[j]);
						cd_array[j] = ft_strdup("");
						j = 1;
					}
				}
			}
			if (cd_array[i])
				free(cd_array[i]);
			cd_array[i] = ft_strdup("");
		}
}

char		*merge_cd_array(char **cd_array)
{
	char	*temp;
	char	*merged;
	int		i;

	i = 0;
	if (!(merged = ft_strdup("")))
		return (NULL);
	while (cd_array[i])
	{
		temp = merged;
		if (ft_strlen(cd_array[i]))
		{
			merged = ft_strjoin_sep(merged, cd_array[i], '/');
			free(temp);
		}
		if (!merged)
			return (NULL);
		i++;
	}
	return (merged);
}

char		*transform_pwd(char *prefix, char *arg)
{
	char	*new_pwd;
	char	**cd_array;
	int		size_before;
	int		size_after;

	if (!(new_pwd = ft_strjoin_sep(prefix, arg, '/')))
		return (NULL);
	cd_array = ft_split(new_pwd, '/');
	free(new_pwd);
	if (!cd_array)
		return (NULL);
	size_before = get_array_size(cd_array);
	replace_dots(cd_array);
	if ((size_after = get_array_size(cd_array)) != size_before)
	{
		while (size_before--)
			if (cd_array[size_before])
				free(cd_array[size_before]);
		free(cd_array);
		return (NULL);
	}
	new_pwd = merge_cd_array(cd_array);
	free_array(cd_array);
	return (new_pwd);
}

char		*get_new_pwd(char *arg)
{
	char	*new_pwd;
	char	*prefix;

	if (*arg == '/')
		prefix = "";
	else if (*arg == '~')
	{
		prefix = ft_getenv("HOME");
		arg++;
	}
	else
		prefix = ft_getenv("PWD");
	if (!(new_pwd = transform_pwd(prefix, arg)))
		return (NULL);
	if (!*new_pwd)
	{
		free(new_pwd);
		new_pwd = ft_strdup("/");
	}
	return (new_pwd);
}

void		ft_cd(char **args)
{
	char	*new_pwd;
	int		size;

	size = get_array_size(args) - 1;
	if (size > 1)
	{
		ft_putstr_fd("minishell: cd: too many arguments\n", STDERR_FILENO);
		return ;
	}
	if (size)
		new_pwd = get_new_pwd(args[size]);
	else
		new_pwd = ft_strdup(ft_getenv("HOME"));
	if (!new_pwd)
		return ;
	if (chdir(new_pwd) == -1)
	{
		g_sh.status = 1;
		error("cd", args[size]);
	}
	else
	{
		g_sh.status = 0;
		manage_env_path();
	}
}
