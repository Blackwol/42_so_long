NAME		= so_long.a
EXEC_NAME = so_long

LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a

CC			= gcc
FLAGS		= -Wall -Wextra -Werror -c
FLAGS2	= -Wall -Wextra -Werror
LIB			= ar rc
LIB1		= ar -s
RM			= rm -rf

SRCS		= so_long.c \
					file_validations.c file_content_validations.c aux_funcs.c \
					wall_validations.c game_rules.c

OBJS		= so_long.o \
					file_validations.o file_content_validations.o aux_funcs.o \
					wall_validations.o game_rules.o

all:		$(NAME)

$(NAME):	$(OBJS) $(LIBFT)
			$(LIB)	$(NAME) $(OBJS)
			$(LIB1) $(NAME)
			$(CC) $(FLAGS2) -o $(EXEC_NAME) $(NAME)

$(OBJS):
			$(CC) $(FLAGS) $(SRCS)

$(LIBFT):
			make all -C $(LIBFT_DIR)
			cp $(LIBFT) $(NAME)

clean:
			make clean -C $(LIBFT_DIR)
			$(RM) $(OBJS)

fclean:		clean
			make fclean -C $(LIBFT_DIR)
			$(RM) $(NAME)
			$(RM) $(EXEC_NAME)

re:			fclean all
