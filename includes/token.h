/*************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 15:54:43 by avieira           #+#    #+#             */
/*   Updated: 2020/10/10 13:55:15 by austin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# define SUCCESS 1
# define ERROR 0

# define CLN "|"
# define INF "<"
# define D_SUP ">>"
# define SUP ">"
# define D_QUOTE "\""
# define QUOTE "'"
# define SPC " "
# define TAB "\t"
# define BS "\\"
# define SM_CL ";"
# define DOLL "$"

# define BRACE_IN '{'
# define BRACE_OUT '}'

typedef enum		e_elem_name
{
					cln,		// |
					inf,		// <
					d_sup,		// >>
					sup,		// >
					d_quote,	// \"
					quote,		// \'
					spc,		// " "
					tab,		// \t
					bs,			// '\'
					sm_cl,		// ;
					doll,		// $
					none
}					t_elem_name;

typedef struct		s_elem
{
	const char		**str;
	int				size;
	t_elem_name		name;
}					t_elem;

typedef enum		e_type
{
					pip,
					in,
					out,
					append_out,
					word,
					space,
					v_env,
					end
}					t_type;

typedef struct		s_token
{
	char			*str;
	t_type			type;
	struct s_token	*next;
}					t_token;

typedef void		(*f_get_tok)(char *, t_elem *, t_type *, t_token *);
void				get_tok_str_null(char *, t_elem *, t_type *, t_token *);
void				get_tok_quote(char *, t_elem *, t_type *, t_token *);
void				get_tok_d_quote(char *, t_elem *, t_type *, t_token *);
void				get_tok_doll(char *, t_elem *, t_type *, t_token *);
void				get_tok_word(char *, t_elem *, t_type *, t_token *);

int					get_len_input_doll(char *, t_elem *);
int					get_len_input_quotes(char *, t_elem *);
int					get_len_input_word(char *, t_elem *);
int					get_elem_size(char *, t_elem *);
t_elem_name			get_elem_name(char *, t_elem *);


t_token				*tok_lstnew(void *content);
void				tok_lstadd_back(t_token **alst, t_token *nw);
void				append_token(t_token *, char *, t_type);
/*
void				tok_lstadd_back(t_token **alst, t_token *nw);
//void				tok_lstclear(t_token **lst, void (*del)(void *));
void				tok_lstdelone(t_token *lst, void (*del)(void *));
void				tok_lstiter(t_token *lst, void (*f)(void *));
void				tok_lstclear(t_token **lst, void (*del)(void *));
t_token				*tok_lstmap(t_token *lst, void *(*f)(void *),
														void (*del)(void *));
*/

#endif
