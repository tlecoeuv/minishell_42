/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 13:29:17 by tanguy            #+#    #+#             */
/*   Updated: 2020/11/10 13:29:28 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int		get_size_str(int nb)
{
	int		i;

	i = 0;
	if (nb == 0)
		i++;
	while (nb != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	int				size;
	char			*dst;
	unsigned int	nb;

	size = get_size_str(n);
	if (n < 0)
		size++;
	if (!(dst = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	nb = (n < 0 ? -n : n);
	if (n < 0)
		dst[0] = '-';
	if (nb == 0)
		dst[0] = '0';
	dst[size] = '\0';
	while (nb != 0)
	{
		dst[size - 1] = (nb % 10) + '0';
		nb = nb / 10;
		size--;
	}
	return (dst);
}
