/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlecoeuv <tlecoeuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 11:51:45 by tlecoeuv          #+#    #+#             */
/*   Updated: 2020/10/08 19:11:30 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int		i;
	int		sign;
	int		nb;

	nb = 0;
	i = 0;
	sign = 1;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
				str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '+' || str[i] == '-')
		sign = sign * (str[i++] == '-' ? -1 : 1);
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (nb * sign);
}
