/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_lstadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:31:12 by avieira           #+#    #+#             */
/*   Updated: 2020/10/02 14:05:55 by austin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/token.h"

void	tok_lstadd_front(t_token **alst, t_token *new)
{
	new->next = *alst;
	*alst = new;
}
