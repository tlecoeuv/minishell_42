/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 15:54:43 by avieira           #+#    #+#             */
/*   Updated: 2020/10/01 16:16:11 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

typedef enum		e_token_type
{
					cmd,
					cmd_arg,
					pipe,		// |
					inf,		// <
					d_inf,		// <<
					sup,		// >
					sm_cl,		// ;
}					t_token_type;

typedef struct		s_token
{
	char			*str;
	t_token_type	type;
	struct s_token	*next;
}					t_token;

#endif
