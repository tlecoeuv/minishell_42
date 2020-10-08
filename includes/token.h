/*************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 15:54:43 by avieira           #+#    #+#             */
/*   Updated: 2020/10/08 20:13:17 by austin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# define OPE "|><"
# define PIP "|"
# define INF "<"
# define SUP ">"
# define D_SUP ">>"

# define SM_CL ";"
# define DOLL "$"
# define BS "\\"

# define QUOTE "'"
# define D_QUOTE "\""

# define SPACE " \t"

/*# define OPE_TYPE 0
# define SM_CL_TYPE 1
# define DOLL_TYPE 2
# define BS_TYPE 3
# define QUOTE_TYPE 4
# define D_QUOTE_TYPE 5
# define SPACE_TYPE 6
# define WORD_TYPE 7
# define PIP_TYPE 8
# define INF_TYPE 9
# define SUP_TYPE 10
# define D_SUP_TYPE 11*/

typedef enum		e_token_type
{
					ope,		// |<>
					sm_cl,		// ;
					v_env,		// $
					bs,			// '\'
					quote,		// '
					d_quote,	// "
					space,		// " \t"
					word,		// everything else
					pip,		// |
					inf,		// <
					sup,		// >
					d_sup,		// >>
}					t_token_type;

typedef struct		s_token
{
	char			*str;
	t_token_type	type;
	struct s_token	*next;
}					t_token;

int					get_l_token(char *, t_token_type, const char **);
char				*get_str_simple_token(char *, t_token_type, const char **);

int					is_in_strings(char, const char **);
t_token_type		wich_type(char *, const char **);

t_token				*tok_lstnew(void *content);
void				tok_lstadd_back(t_token **alst, t_token *nw);

/*
int					filter_tokens(t_token *tokens);
int					is_in_set(char *str, const char **set);

int					ft_isalnum(int c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strlen(const char *s1);

void				tok_lstadd_back(t_token **alst, t_token *nw);
//void				tok_lstclear(t_token **lst, void (*del)(void *));
void				tok_lstdelone(t_token *lst, void (*del)(void *));
void				tok_lstiter(t_token *lst, void (*f)(void *));
void				tok_lstclear(t_token **lst, void (*del)(void *));
t_token				*tok_lstmap(t_token *lst, void *(*f)(void *),
														void (*del)(void *));
*/
#endif
