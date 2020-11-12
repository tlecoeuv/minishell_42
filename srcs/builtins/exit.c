/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlecoeuv <tlecoeuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 14:12:41 by tlecoeuv          #+#    #+#             */
/*   Updated: 2020/11/12 11:19:07 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int			is_not_to_big(char *str)
{
	int					i;
	int					sign;
	unsigned long int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while(str[i])
		res = res * 10 + str[i++] - '0';
	if (sign == 1 && res > (unsigned long int)LONG_MAX)
		return (0);
	if (sign == -1 && res > (unsigned long int)LONG_MAX + 1)
		return (0);
	return (1);
}

int			is_valid_number(char *str)
{
	int		i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] =='-')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] != '\0')
		return (0);
	return (is_not_to_big(str));
}

void		ft_exit(char **args)
{
	g_sh.running = 0;
	if (get_array_size(args) < 2)
		return(g_sh.status);
	if (!is_valid_number(args[1]))
	{
		ft_putstr_fd("minishell: exit: numeric argument required\n",
																STDERR_FILENO);
		return (STATUS_FAILURE_BUILTIN);
	}
	if (get_array_size(args) > 2)
	{
		g_sh.running = 1;
		ft_putstr_fd("minishell: exit: too many arguments\n", STDERR_FILENO);
	}
	return(ft_atoi(args[1]));
}
