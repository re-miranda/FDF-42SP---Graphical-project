#MAIN
NAME = fdf

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
SRCS = fdf.c exit_routines.c \
	render/bresenham_line.c \
	render/map_draw.c \
	render/put_to_screen.c \
	mlx_handlers/mlx_init.c \
	mlx_handlers/mlx_input.c \
	mlx_handlers/mlx_pixel_tools.c \
	map_utils/map_funcs.c \
	map_utils/map_load.c \
	map_utils/map_tools.c
OBJS = $(SRCS:%.c=%.o)

all:	$(NAME)

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
