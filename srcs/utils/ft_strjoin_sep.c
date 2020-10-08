/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_sep.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 12:30:13 by tanguy            #+#    #+#             */
/*   Updated: 2020/10/08 12:40:42 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char		*ft_strjoin_sep(char *s1, char *s2, char sep)
{
	char	*s;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	if (!(s = malloc(sizeof(char) * (ft_strlen(s1)
		+ ft_strlen(s2) + 2))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		s[j++] = s1[i++];
	s[j] = sep;
	j++;
	i = 0;
	while (s2[i])
		s[j++] = s2[i++];
	s[j] = 0;
	return (s);
}
