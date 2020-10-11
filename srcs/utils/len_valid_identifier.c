/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_car_identifier.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: austin <avieira@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 04:33:28 by austin            #+#    #+#             */
/*   Updated: 2020/10/11 03:24:03 by austin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int			get_len_valid_identifier(char *str, int braces)
{
	int		len;

	len = 0;
	if (*str > '0' && *str < '9')
		return (-1);
	while ((str[len] >= '0' && str[len] <= '9') ||
			(str[len] >= 'A' && str[len] <= 'Z') ||
			(str[len] >= 'a' && str[len] <= 'z') || 
			str[len] == '_')
			len++;
	if (braces)
	{
		if (str[len] == BRACE_OUT)
			len++;
		else
			return (-1);
	}
	return (len);
}
