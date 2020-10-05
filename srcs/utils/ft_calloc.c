/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlecoeuv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:33:13 by tlecoeuv          #+#    #+#             */
/*   Updated: 2020/10/05 21:32:17 by tlecoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned int	i;
	int				*pt;

	i = 0;
	if (!(pt = malloc(sizeof(size) * count)))
		return (NULL);
	while (i < count)
	{
		pt[i] = 0;
		i++;
	}
	return (pt);
}
