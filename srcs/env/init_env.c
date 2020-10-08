/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:42:56 by tanguy            #+#    #+#             */
/*   Updated: 2020/10/07 22:10:25 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	init_env(char **envp)
{
	int		size;
	int		i;

	i = 0;
	size = get_array_size(envp);
	if (!(g_env = malloc(sizeof(char *) * (size + 1))))
		return ;
	while(i < size)
	{
		g_env[i] = ft_strdup(envp[i]);
		i++;
	}
	g_env[i] = NULL;
}
