NAME = Minishell

SRCS_PATH			=	./srcs
INC_PATH			=	./includes

SRCS_NAME			=	main.c \
						parsing.c \
						ft_split.c \
						exec.c \
						get_next_line_utils.c \
						get_next_line.c \

INC_NAME			=	minishell.h

SRCS				=	$(addprefix $(SRCS_PATH)/, $(SRCS_NAME))
INC					=	$(addprefix $(INC_PATH)/, $(INC_NAME))

CC					=	gcc

CFLAGS				=	-Wall -Wextra -Werror -I./

all:				$(NAME)

$(NAME):
					@($(CC) $(CFLAGS) $(SRCS) -o $(NAME))

fclean:
					rm -rf $(NAME)

re:					fclean all

.PHONY:				clean fclean re all
