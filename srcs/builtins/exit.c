/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlecoeuv <tlecoeuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 14:12:41 by tlecoeuv          #+#    #+#             */
/*   Updated: 2020/11/23 12:31:39 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int						get_unity_index(int i, char *str)
{
	if (i < 0)
		return (0);
	return (str[i] - '0');
}

int						is_not_to_big(int sign, char *str)
{
	unsigned long int	diff_res;
	unsigned long int	old_res;
	unsigned long int	res;
	int					i;

	i = -1;
	res = 0;
	old_res = 0;
	while (ft_isdigit(str[++i]))
	{
		diff_res = 10 * (res - old_res) +
						get_unity_index(i, str) - get_unity_index(i - 1, str);
		if (diff_res > (unsigned long int)LONG_MAX - res + sign)
			return (0);
		old_res = res;
		res += diff_res;
	}
	return (1);
}

int						is_valid_number(char *str)
{
	int					i;
	int					sign;
	int					start;

	i = 0;
	sign = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		sign = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	start = i;
	while (ft_isdigit(str[i]))
		i++;
	while (ft_isspace(str[i]) && str[i] != '\r')
		i++;
	if (str[i] != '\0')
		return (0);
	return (is_not_to_big(sign, &str[start]));
}

int						ft_exit(char **args)
{
	g_sh.running = 0;
	if (get_array_size(args) < 2)
		return (g_sh.status);
	if (!is_valid_number(args[1]))
	{
		ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
		ft_putstr_fd(args[1], STDERR_FILENO);
		ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
		return (STATUS_FAILURE_BUILTIN);
	}
	if (get_array_size(args) > 2)
	{
		g_sh.running = 1;
		ft_putstr_fd("minishell: exit: too many arguments\n", STDERR_FILENO);
		return (STATUS_FAILURE);
	}
	return (ft_atoi(args[1]));
}
