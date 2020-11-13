/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 10:55:06 by tanguy            #+#    #+#             */
/*   Updated: 2020/11/13 11:53:24 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*restaurer le comportement de SIGINT avec signal(SIGINT, DFL),
		quand on est dans un child.*/
/*comment passer la boucle qui prends en compte la commande quand on
	est dans le père?
	---> if (ctrl_c != 1) ? c'est nul mais pk pas*/
/*si on est dans des pipes à la suite comment faire?*/

void		ctrl_c(int sig)
{
	(void)sig;
	g_sh.ctrl = 1;
	g_sh.status = STATUS_CTRL_C;
}
