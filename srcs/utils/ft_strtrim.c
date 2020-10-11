/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:17:37 by avieira           #+#    #+#             */
/*   Updated: 2020/10/11 12:34:00 by austin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static size_t	ft_strl(const char *s)
{
	int l;

	l = 0;
	while (*s++)
		l++;
	return (l);
}

static int		check_set(char c, char const *set)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	int		start;
	char	*s;
	int		i;

	if (!s1)
		return (NULL);
	start = 0;
	len = ft_strl(s1);
	while (check_set(s1[start], set) && len > 0)
	{
		start++;
		len--;
	}
	while (check_set(s1[start + len - 1], set) && len > 0)
		len--;
	if (!(s = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = -1;
	while (++i < len)
		s[i] = s1[start + i];
	s[i] = 0;
	return (s);
}
