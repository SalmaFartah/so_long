CC = cc

CFLAGS = -Wall -Wextra -Werror

FLAGS = -framework Cocoa -framework OpenGL -framework IOKit

LIBFLAGS = -Iinclude -lglfw -L

USER = sfartah

LIBDIR = "/Users/$(USER)/.brew/opt/glfw/lib/"

NAME = so_long

SRC = 	so_long.c\
		init_map.c\
		display_ar.c\
		valid/costruction.c\
		valid/check_walls.c\
		valid/check_SEC.c\
		valid/check_path.c\
		valid/free_ar.c\
		gnxtL/get_next_line.c\
		gnxtL/get_next_line_utils.c\
		libft/ft_lstnew.c\
		libft/ft_lstadd_back.c\
		libft/ft_lstlast.c\
		libft/sl_strlen.c\
		libft/ft_lstclear.c\
		libft/ft_lstdelone.c\
		libft/ft_lstsize.c\
		libft/ft_calloc.c\
		libft/ft_bzero.c

OBJ = $(SRC:.c=.o)

%.o : %.c so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(FLAGS) $(LIBFLAGS) $(LIBDIR)/libmlx42.a $(OBJ) -o $@

clean :
	rm -rf $(OBJ) 

fclean : clean
	rm -rf $(NAME)

re : fclean all

ac : all clean
