/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 16:20:59 by avieira           #+#    #+#             */
/*   Updated: 2020/10/09 02:43:46 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

//LIBRAIRES
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <string.h>
# include <errno.h>

//LIBRAIRIES A SUPPRIMER
# include <stdio.h>

//HEADERS PERSONELS
# include "token.h"
# include "get_next_line.h"
# include "exec.h"
# include "utils.h"
# include "env.h"

extern char		**g_env;

#endif
