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

int			get_len_name(char *env_var)
{
	int		len;

	len = 0;
	while (env_var[len] && env_var[len] != '=')
		len++;
	return (len);
}

void		get_ascii_order(int size, int *order)
{
	int		i;
	int		temp;
	int		len_a;
	int		len_b;

	i = -1;
	while (++i < size)
		order[i] = i;
	i = -1;
	while (++i + 1 < size)
	{
		len_a = get_len_name(g_sh.env[order[i]]);
		len_b = get_len_name(g_sh.env[order[i + 1]]);
		if (len_a > len_b)
			len_a = len_b;
		if (ft_strncmp(g_sh.env[order[i]], g_sh.env[order[i + 1]], len_a + 1)
																			> 0)
		{
			temp = order[i];
			order[i] = order[i + 1];
			order[i + 1] = temp;
			i = -1;
		}
	}
}

void		print_export_env(void)
{
	int		i;
	int		len;
	int		size;
	int		*order;

	size = get_array_size(g_sh.env);
	if (!(order = ft_calloc(sizeof(int), size)))
		return ;
	get_ascii_order(size, order);
	i = -1;
	while (++i < size)
	{
		len = get_len_name(g_sh.env[order[i]]);
		ft_putstr_fd("declare -x ", STDOUT_FILENO);
		write(STDOUT_FILENO, g_sh.env[order[i]], len + 1);
		if (g_sh.env[order[i]][len] == '=')
		{
			ft_putstr_fd("\"", STDOUT_FILENO);
			ft_putstr_fd(&g_sh.env[order[i]][len + 1], STDOUT_FILENO);
			ft_putstr_fd("\"", STDOUT_FILENO);
		}
		ft_putstr_fd("\n", STDOUT_FILENO);
	}
	free(order);
}

void		manage_var(char *var)
{
	int		i;
	int		len;
	char	*new;

	i = -1;
	len = get_len_name(var);
	while (g_sh.env[++i])
		if (!ft_strncmp(var, g_sh.env[i], len))
		{
			if (g_sh.env[i][len] != '=' || var[len] == '=')
			{
				if (!(new = ft_strdup(var)))
					return ;
				free(g_sh.env[i]);
				g_sh.env[i] = new;
				return ;
			}
		}
	add_env_var(var);
}

int			ft_export(char **args)
{
	int		size;
	int		i;
	int		status;

	status = 0;
	size = get_array_size(args);
	if (size == 1)
		print_export_env();
	else
	{
		i = 0;
		while (++i < size)
			if (error_identifier("export", args[i]))
				manage_var(args[i]);
			else
				status += 1;
	}
	if (status)
		return (STATUS_FAILURE);
	return (STATUS_SUCCESS);
}
