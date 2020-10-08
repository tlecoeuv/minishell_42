/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:17:04 by avieira           #+#    #+#             */
/*   Updated: 2020/10/09 01:10:39 by austin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int				i;
	char			*substr;
	unsigned int	len_s;

	len_s = 0;
	if (!s)
		return (NULL);
	while (s[len_s])
		len_s++;
	len = (len > len_s - start) ? len_s - start : len;
	len = (start > len_s) ? 0 : len;
	if (!(substr = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (len-- && s[start + i])
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = 0;
	return (substr);
}
