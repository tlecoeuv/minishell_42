/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_valid_identifier.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: austin <avieira@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 04:33:28 by austin            #+#    #+#             */
/*   Updated: 2020/10/20 13:06:46 by austin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int			get_len_valid_identifier(char *str)
{
	int		len;

	len = 0;
	if (str[len] == '?')
		return (1);
	if (str[len] >= '0' && str[len] <= '9')
		return (0);
	while ((str[len] >= '0' && str[len] <= '9') ||
			(str[len] >= 'A' && str[len] <= 'Z') ||
			(str[len] >= 'a' && str[len] <= 'z') || 
			str[len] == '_')
			len++;
	return (len);
}

int			error_identifier(char *builtin, char *name)
{
	int		len_name;

	len_name = get_len_name(name);
	if (len_name != get_len_valid_identifier(name))
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(builtin, STDERR_FILENO);
		ft_putstr_fd(": `", STDERR_FILENO);
		ft_putstr_fd(name, STDERR_FILENO);
		ft_putstr_fd("': not a valid identifier\n", STDERR_FILENO);
		g_sh.status = STATUS_FAILURE_BUILTIN;
		return (0);
	}
	return (1);
}
