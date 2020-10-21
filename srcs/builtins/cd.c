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

void		manage_env_path(char *pwd)
{
	char	*oldpwd;

	if (!(oldpwd = getcwd(NULL, 0)))
		return ;
	set_env_var("OLDPWD", oldpwd);
	set_env_var("PWD", pwd);
}

void		ft_cd(char **args)
{
	char	*str;
	int		size;

	size = get_array_size(args) - 1;
	if (size && ft_strcmp("~", args[size]))
			str = args[1];
	else
		if (!(str = ft_getenv("HOME")))
			return ;
	manage_env_path(str);
	chdir(str);
}
