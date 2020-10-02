/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:47:05 by avieira           #+#    #+#             */
/*   Updated: 2020/10/02 13:41:18 by austin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char			*ft_strdup(const char *s1)
{
	char	*cpy;
	char	*temp;
	int		len;

	len = 0;
	while (s1[len])
		len++;
	if (!(cpy = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	temp = cpy;
	while (len--)
		*temp++ = *s1++;
	*temp = 0;
	return (cpy);
}
