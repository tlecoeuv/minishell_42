NAME = minishell

CC = clang

MKD = mkdir

RM = rm -rf

SRCS = 	srcs/main.c \
		srcs/builtins/builtin_utils.c \
		srcs/builtins/cd.c \
		srcs/builtins/cd_vars.c \
		srcs/builtins/exit.c \
		srcs/builtins/pwd.c \
		srcs/env/env_utils.c \
		srcs/env/init_env.c \
		srcs/error/error.c \
		srcs/command/handle_tokens.c \
		srcs/command/get_commands.c \
		srcs/command/interpret_v_env.c \
		srcs/command/command_utils.c \
		srcs/command/handle_commands.c \
		srcs/command/handle_command_no_pipe.c \
		srcs/command/path.c \
		srcs/command/path_utils.c \
		srcs/signals/signals.c \
		srcs/redirection/do_redirection.c \
		srcs/redirection/get_redirection.c \
		srcs/redirection/redirection_builtins.c \
		srcs/redirection/redirection_utils.c \
		srcs/get_next_line/get_next_line.c \
		srcs/get_next_line/get_next_line_utils.c \
		srcs/syntax/check_append_out.c \
		srcs/syntax/check_end.c \
		srcs/syntax/check_in.c \
		srcs/syntax/check_nope.c \
		srcs/syntax/check_out.c \
		srcs/syntax/check_pip.c \
		srcs/syntax/check_space.c \
		srcs/syntax/check_v_env.c \
		srcs/syntax/check_word.c \
		srcs/syntax/syntax.c \
		srcs/tokens/get_elem_params.c \
		srcs/tokens/get_tok_bs.c \
		srcs/tokens/get_tok_doll.c \
		srcs/tokens/get_tok_d_quote.c \
		srcs/tokens/get_tok_quote.c \
		srcs/tokens/get_tok_sign.c \
		srcs/tokens/get_tok_word.c \
		srcs/tokens/tokens.c \
		srcs/tokens/tok_join_words.c \
		srcs/tokens/token_list_utils/append_token.c \
		srcs/tokens/token_list_utils/del_start_to_end.c \
		srcs/tokens/token_list_utils/tok_lstadd_back.c \
		srcs/tokens/token_list_utils/tok_lstadd_front.c \
		srcs/tokens/token_list_utils/tok_lstclear.c \
		srcs/tokens/token_list_utils/tok_lstdelone.c \
		srcs/tokens/token_list_utils/tok_lstiter.c \
		srcs/tokens/token_list_utils/tok_lstlast.c \
		srcs/tokens/token_list_utils/tok_lstmap.c \
		srcs/tokens/token_list_utils/tok_lstnew.c \
		srcs/tokens/token_list_utils/tok_lstsize.c \
		srcs/tokens/token_list_utils/insert_lst_token.c \
		srcs/utils/free_array.c \
		srcs/utils/ft_atoi.c \
		srcs/utils/ft_calloc.c \
		srcs/utils/ft_isalnum.c \
		srcs/utils/ft_isdigit.c \
		srcs/utils/ft_isspace.c \
		srcs/utils/ft_itoa.c \
		srcs/utils/ft_putstr_fd.c \
		srcs/utils/ft_split.c \
		srcs/utils/ft_strcat.c \
		srcs/utils/ft_strchr.c \
		srcs/utils/ft_strcmp.c \
		srcs/utils/ft_strdup.c \
		srcs/utils/ft_strjoin.c \
		srcs/utils/ft_strjoin_sep.c \
		srcs/utils/ft_strlen.c \
		srcs/utils/ft_strncmp.c \
		srcs/utils/ft_strtrim.c \
		srcs/utils/ft_substr.c \
		srcs/utils/get_array_size.c \
		srcs/utils/valid_identifier.c \
		srcs/utils/get_input.c \
		srcs/builtins/env.c \
		srcs/builtins/unset.c \
		srcs/builtins/export.c \
		srcs/builtins/echo.c \
		srcs/tokens/retokenise_vars.c

OBJ = $(SRCS:%.c=%.o)

IFLAGS = ./includes/

CFLAGS = -Wall -Wextra -Werror

SRCS_DIR = srcs/

STRT_STYLE = \033[1;32m

END_STYLE = \033[0m

all: $(NAME)

%.o: %.c
	@($(CC) $(CFLAGS) -c -I$(IFLAGS) $< -o $(<:.c=.o))

$(NAME): $(OBJ)
	@(echo "$(STRT_STYLE)Compiling...$(END_STYLE)")
	@($(CC) -o $(NAME) -I$(IFLAGS) $(OBJ) $(CFLAGS))
	@(echo "$(STRT_STYLE)Done.$(END_STYLE)")

clean:
	@(echo "$(STRT_STYLE)Cleaning...$(END_STYLE)")
	@($(RM) $(SRCS_DIR)/*.o)
	@($(RM) $(SRCS_DIR)/*/*.o)
	@($(RM) $(SRCS_DIR)/*/*/*.o)
	@(echo "$(STRT_STYLE)Done.$(END_STYLE)")

fclean: clean
	@(echo "$(STRT_STYLE)Fcleaning...$(END_STYLE)")
	@($(RM) $(NAME))
	@(echo "$(STRT_STYLE)Done.$(END_STYLE)")

re: fclean all

.PHONY: all clean fclean re
