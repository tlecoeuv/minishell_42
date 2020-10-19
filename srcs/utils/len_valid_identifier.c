/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_valid_identifier.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: austin <avieira@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 04:33:28 by austin            #+#    #+#             */
/*   Updated: 2020/10/19 14:16:44 by austin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int			get_len_valid_identifier(char *str)
{
	int		len;

	len = 0;
	if (str[len] > '0' && str[len] < '9')
		return (0);
	len++;
	while ((str[len] >= '0' && str[len] <= '9') ||
			(str[len] >= 'A' && str[len] <= 'Z') ||
			(str[len] >= 'a' && str[len] <= 'z') || 
			str[len] == '_')
			len++;
	return (len);
}
