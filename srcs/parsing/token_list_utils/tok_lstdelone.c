/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_lstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:39:35 by avieira           #+#    #+#             */
/*   Updated: 2020/10/15 18:51:50 by austin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	tok_lstdelone(t_token *lst)
{
	if (lst)
	{
		if (lst->str)
			free(lst->str);
		free(lst);
		lst = NULL;
	}
}
