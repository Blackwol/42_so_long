LIB_NAME		= so_long.a
EXEC_NAME = so_long
NAME = so_long

LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a

CC			= gcc
FLAGS		= -Wall -Wextra -Werror -c
FLAGS2		= -Wall -Wextra -Werror
LIB			= ar rc
LIB1		= ar -s
RM			= rm -rf
MLX_FLASG	= -lmlx -lXext -lX11

SRCS		= so_long.c \
					file_validations.c file_content_validations.c hooks.c \
					wall_validations.c game_rules.c game.c get_next_line.c \
					get_next_line_utils.c generate_imgs1.c generate_imgs2.c \
					moves.c render.c init.c validations_utils.c

OBJS		= so_long.o \
					file_validations.o file_content_validations.o hooks.o \
					wall_validations.o game_rules.o game.o get_next_line.o \
					get_next_line_utils.o generate_imgs1.o generate_imgs2.o \
					moves.o render.o init.o validations_utils.o

all:		$(NAME)

$(NAME):	$(OBJS) $(LIBFT)
			$(LIB)	$(LIB_NAME) $(OBJS)
			$(LIB1) $(LIB_NAME)
			$(CC) $(FLAGS2) -o $(EXEC_NAME) $(LIB_NAME) $(MLX_FLASG)

$(OBJS):
			$(CC) $(FLAGS) $(SRCS)

$(LIBFT):
			make all -C $(LIBFT_DIR)
			cp $(LIBFT) $(LIB_NAME)

clean:
			make clean -C $(LIBFT_DIR)
			$(RM) $(OBJS)

fclean:		clean
			make fclean -C $(LIBFT_DIR)
			$(RM) $(LIB_NAME)
			$(RM) $(EXEC_NAME)

re:			fclean all

.PHONY:	all re clean fclean
