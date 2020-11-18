/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:15:30 by avieira           #+#    #+#             */
/*   Updated: 2020/10/09 01:01:17 by austin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

size_t					ft_strl_spec(const char *s, char spec)
{
	int					l;

	l = 0;
	while (s[l] && s[l] != spec)
		l++;
	return (l);
}

void					*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*t_dst;
	const unsigned char	*t_src;

	t_dst = dst;
	t_src = src;
	if (!dst && !src)
		return (NULL);
	while (n--)
		*t_dst++ = *t_src++;
	return (dst);
}
