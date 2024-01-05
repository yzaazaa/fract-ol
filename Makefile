SRCS := srcs/main.c srcs/string_utils.c srcs/math_utils.c srcs/init_fractal.c srcs/render_fractal.c srcs/events.c srcs/julia.c srcs/mandelbrot.c srcs/tricorn.c srcs/put_pixel.c

OBJS = ${SRCS:.c=.o}

HEADERS := includes/fractol.h includes/string.h includes/math.h includes/keys.h

NAME = fractol

CFLAGS = -Wall -Wextra -Werror

CC = cc

all : $(NAME)

$(NAME) : $(OBJS)
	@echo "Compiling mandatory ..."
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