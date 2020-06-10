/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlecoeuv <tlecoeuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 22:02:29 by tlecoeuv          #+#    #+#             */
/*   Updated: 2020/06/04 17:25:36 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_create_str(int size)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (i < size)
	{
		str[i] = '0';
		i++;
	}
	str[size] = '\0';
	return (str);
}

int		ft_strchr(char *str, int c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	if (c == '\0')
		return (i);
	return (-1);
}

char	*ft_str_dup_line(char *str)
{
	char	*copy;
	int		i;
	int		size;

	size = 0;
	i = 0;
	while (str[size] && str[size] != '\n')
		size++;
	if (!(copy = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
