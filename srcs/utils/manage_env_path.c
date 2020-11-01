/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_env_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 11:51:45 by tlecoeuv          #+#    #+#             */
/*   Updated: 2020/10/08 19:11:30 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void		manage_env_path()
{
	char	*oldpwd;
	char	*pwd;

	if (!(oldpwd = ft_strdup(ft_getenv("PWD"))))
		return ;
	if (!(pwd = getcwd(NULL, 0)))
		return ;
	set_env_var("OLDPWD", oldpwd);
	set_env_var("PWD", pwd);
}
