/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:42:56 by tanguy            #+#    #+#             */
/*   Updated: 2020/11/13 11:40:20 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	init_shell(char **envp)
{
	init_env(envp);
	g_sh.cwd = getcwd(NULL, 0);
	g_sh.status = 0;
	g_sh.running = 1;
}

void	init_env(char **envp)
{
	int		size;
	int		i;

	i = 0;
	size = get_array_size(envp);
	if (!(g_sh.env = malloc(sizeof(char *) * (size + 1))))
		return ;
	while (i < size)
	{
		g_sh.env[i] = ft_strdup(envp[i]);
		i++;
	}
	g_sh.env[i] = NULL;
}
