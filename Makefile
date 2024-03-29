SRCS := srcs/main.c srcs/utils/string_utils.c srcs/utils/math_utils.c srcs/init_fractal.c srcs/render_fractal.c srcs/handle_events.c srcs/fractals/julia.c srcs/fractals/mandelbrot.c srcs/fractals/tricorn.c srcs/utils/put_pixel.c

OBJS = ${SRCS:.c=.o}

HEADERS := includes/fractol.h includes/string.h includes/math.h includes/keys.h

NAME = fractol

CFLAGS = -Wall -Wextra -Werror

CC = cc

all : $(NAME)

bonus : $(NAME)

$(NAME) : $(OBJS)
	@echo "Compiling fractol ..."
	@$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit $(OBJS) -o $(NAME)

%.o : %.c $(HEADERS)
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean :
	@echo "Deleting object files ..."
	@rm -rf $(OBJS)

fclean :
	@echo "Deleting all ..."
	@rm -rf $(OBJS) $(NAME)

re : fclean all

.PHONY : fclean clean