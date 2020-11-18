/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 00:27:25 by tanguy            #+#    #+#             */
/*   Updated: 2020/11/15 10:50:23 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

typedef struct	s_sig
{
	int			sigint;
	int			sigquit;
	pid_t		pid;
}				t_sig;

void			handle_sigint(int code);
void			handle_sigquit(int code);
void			reset_sig(void);

#endif
