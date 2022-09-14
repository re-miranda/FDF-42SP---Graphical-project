#MAIN
NAME = fdf.out

#LIBS
LIBFT = ft
MINILIBX =  -lmlx -lXext -lX11

#LIBS_PATH
LIBFT_PATH = ../libft

#OTHER
CC = gcc
AR = ar -rcs
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -g

#FILES
SRCS = fdf.c line_handler.c x.c mlx_handlers/init_mlx.c mlx_handlers/image_utils.c mlx_handlers/input_utils.c
OBJS = $(SRCS:%.c=%.o)

all:	$(NAME) clean

$(NAME):	$(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_PATH) -l$(LIBFT) $(MINILIBX)

$(LIBFT):
	make -C $(LIBFT_PATH) all

%.o:	%.c
	$(CC) $(CFLAGS) -c $< -o $(<:%.c=%.o) -I/usr/include -I$(LIBFT_PATH)

clean:
	make -C $(LIBFT_PATH) clean
	$(RM) $(OBJS)

fclean:	clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
