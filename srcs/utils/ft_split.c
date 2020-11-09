/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlecoeuv <tlecoeuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 11:58:33 by tlecoeuv          #+#    #+#             */
/*   Updated: 2020/11/09 18:42:56 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	nb_word(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (s[0] == '\0')
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			if (s[i + 1] && s[i + 1] != c)
				count++;
		i++;
	}
	if (s[0] != c)
		count++;
	return (count);
}

static int	size_word(char const *s, char c)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void	copy_word(char const *s, char c, char **dst, int j)
{
	int		k;

	k = 0;
	if (!(dst[j] = malloc(sizeof(char) * (size_word(s, c) + 1))))
		return ;
	while (s[k] && s[k] != c)
	{
		dst[j][k] = s[k];
		k++;
	}
	dst[j][k] = '\0';
}

char		**ft_split(char const *s, char c)
{
	int		size;
	char	**dst;
	int		j;

	if (s == NULL)
		return (NULL);
	j = 0;
	size = nb_word(s, c);
	if (!(dst = malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	while (j < size)
	{
		while (*s == c)
			s++;
		copy_word(s, c, dst, j);
		s = s + size_word(s, c);
		j++;
	}
	dst[j] = NULL;
	return (dst);
}
