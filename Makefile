SRCS = main.c string_utils.c math_utils.c inits.c render.c events.c

OBJS = ${SRCS:.c=.o}

HEADER = fractol.h

NAME = fractol

CFLAGS = -Wall -Wextra -Werror

CC = cc

all : $(NAME)

$(NAME) : $(OBJS)
	@echo "Compiling mandatory ..."
	@$(CC) $(CLFAGS) -lmlx -framework OpenGL -framework AppKit $(OBJS) -o $(NAME)

%.o : %.c $(HEADER)
	@$(CC) $(CLFAGS) -Imlx -c $<

clean :
	@echo "Deleting object files ..."
	@rm -rf $(OBJS)

fclean :
	@echo "Deleting all ..."
	@rm -rf $(OBJS) $(NAME)

re : fclean all