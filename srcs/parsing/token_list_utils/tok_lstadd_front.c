/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_lstadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:31:12 by avieira           #+#    #+#             */
/*   Updated: 2020/10/01 16:17:58 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/token.h"

void	tok_lstadd_front(t_token **alst, t_token *new)
{
	new->next = *alst;
	*alst = new;
}
