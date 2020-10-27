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

	if (!(oldpwd = ft_strdup(ft_getenv("PWD"))))
		return ;
	set_env_var("OLDPWD", oldpwd);
	set_env_var("PWD", pwd);
}



char		*relativ_to_absolute(char *pwd)
{
	char	*current;
	char	*str;
	char	*temp;

	if (*pwd == '~' || *pwd == '/')
		return (pwd);
	current = ft_getenv("PWD");
	temp = ft_strjoin(current, "/");
	str = ft_strjoin(temp, pwd);
	return (str);
}

/*
char		*get_parent_directory(char *pwd)
{
	char	*parent;
	int		len;

	len = 0;
	if (!pwd)
		return (NULL);
	while (pwd[len])
		len++;
	len--;
	while (pwd[len] != '/' && pwd[len] && len > 1)
		len--;
	parent = ft_substr(pwd, 0, len);
	return (parent);
}

char		*replace_dots(char *str)
{
	char	**temp;
	int		i;

	temp = ft_split(str, '/');
	i = 0;
	while (temp[i])
		printf("%s\n", temp[i]);
}
*/
char		*get_new_pwd(char *arg)
{
	char	*new_pwd;
	char	*pwd;

	pwd = ft_getenv("PWD");
	new_pwd = NULL;
	if (!ft_strcmp("-", arg))
		new_pwd = ft_strdup(ft_getenv("OLDPWD"));
	else
		new_pwd = relativ_to_absolute(arg);
	return (new_pwd);
}

void		ft_cd(char **args)
{
	char	*new_pwd;
	int		size;

	size = get_array_size(args) - 1;
	if (size > 1)
	{
		ft_putstr_fd("bash: cd: too many arguments\n", 0);
		return ;
	}
	if (size && ft_strcmp("~", args[size]))
		new_pwd = get_new_pwd(args[size]);
	else
		new_pwd = ft_strdup(ft_getenv("HOME"));
	//printf("pwd %s\n", new_pwd);
	if (chdir(new_pwd) == -1)
		ft_putstr_fd("chdir fail, errno non rempli\n", 0);
	else
		manage_env_path(new_pwd);
	//printf ("CD       : %s\nPWD    : %s\nOLDPWD : %s\n",
	//					new_pwd, ft_getenv("PWD"), ft_getenv("OLDPWD"));
}
