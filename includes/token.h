/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 15:54:43 by avieira           #+#    #+#             */
/*   Updated: 2020/10/02 12:31:25 by austin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# define PIPE "|"
# define INF "<"
# define D_SUP ">>"
# define SUP ">"
# define SM_CL ";"
# define DOLL "$"
# define BS "\\"
# define QUOTE "'"
# define D_QUOTE "\""

typedef enum		e_token_type
{
					cmd,
					cmd_arg,
					pipe,		// |
					inf,		// <
					d_sup,		// >>
					sup,		// >
					sm_cl,		// ;
					v_env,		// $
					bs			// '\'
}					t_token_type;

typedef struct		s_token
{
	char			*str;
	t_token_type	type;
	struct s_token	*next;
}					t_token;

#endif
