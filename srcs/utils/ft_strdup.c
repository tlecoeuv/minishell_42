/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlecoeuv <tlecoeuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 13:18:28 by tlecoeuv          #+#    #+#             */
/*   Updated: 2020/11/09 18:41:47 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_strdup(char *src)
{
	char	*copy;
	int		i;
	int		size;

	if (src == NULL)
		return (NULL);
	size = ft_strlen(src);
	i = 0;
	if (!(copy = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (src[i])
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
