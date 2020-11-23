/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 16:20:59 by avieira           #+#    #+#             */
/*   Updated: 2020/11/23 12:40:53 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include "token.h"
# include "syntax.h"
# include "get_next_line.h"
# include "command.h"
# include "utils.h"
# include "env.h"
# include "builtins.h"
# include "error.h"
# include "redirection.h"
# include "signals.h"

typedef struct	s_shell
{
	char	**env;
	char	*cwd;
	int		status;
	int		running;
}				t_shell;

extern t_shell	g_sh;
extern t_sig	g_sig;

#endif
