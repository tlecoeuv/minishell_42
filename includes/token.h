/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 15:54:43 by avieira           #+#    #+#             */
/*   Updated: 2020/10/20 03:39:14 by austin           ###   ########.fr       */
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

typedef enum		e_elem_name
{
	cln,
	inf,
	d_sup,
	sup,
	d_quote,
	quote,
	spc,
	tab,
	bs,
	sm_cl,
	doll,
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
	end,
	nope
}					t_type;

typedef struct		s_token
{
	char			*str;
	t_type			type;
	char			retokenise;
	struct s_token	*next;
}					t_token;

int					create_tokens_list(char *input, t_token **tokens);
void				retokenise_vars(t_token **tokens);

int					get_elem_size(char *input, t_elem *elem);
t_elem_name			get_elem_name(char *input, t_elem *elem);
int					get_len_input_doll(char *input, t_elem *elem);
int					get_len_input_quotes(char *input, t_elem *elem);
int					get_len_input_word(char *input, t_elem *elem);

int					get_tok_sign(char *input, t_elem *elem,
								const t_type *elem_to_type, t_token **tokens);
int					get_tok_quote(char *input, t_elem *elem,
								const t_type *elem_to_type, t_token **tokens);
int					get_tok_d_quote(char *input, t_elem *elem,
								const t_type *elem_to_type, t_token **tokens);
int					get_tok_doll(char *input, t_elem *elem,
								const t_type *elem_to_type, t_token **tokens);
int					get_tok_word(char *input, t_elem *elem,
								const t_type *elem_to_type, t_token **tokens);
int					get_tok_bs(char *input, t_elem *elem,
								const t_type *elem_to_type, t_token **tokens);
char				*get_str_bs(char *input, t_elem *elem);

int					tok_join_words(t_token **tokens);

void				del_start_to_end(t_token **tokens, t_token *start,
																t_token *end);
t_token				*insert_lst_token(t_token *pre_token, t_token *new_tokens);
int					append_token(t_token **tokens, char *str, t_type type);

t_token				*tok_lstnew(void *content);
void				tok_lstadd_back(t_token **alst, t_token *nw);
void				tok_lstdelone(t_token *lst);
void				tok_lstclear(t_token **lst);
t_token				*tok_lstlast(t_token *lst);
//A ENLEVER
void				display_tokens(t_token **tokens);

#endif
