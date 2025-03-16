CC = cc

HEADERS	= -I ./MLX42/include

CFLAGS = -Wall -Wextra -Werror -Wunreachable-code -Ofast

USER = sfartah

LIBS = ./MLX42/build/libmlx42.a -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"

NAME = so_long

SRC = 	so_long.c\
		init_map.c\
		display_ar.c\
		draw_map.c\
		move.c\
		init_game.c\
		list_to_array.c\
		valid/costruction.c\
		valid/check_walls.c\
		valid/check_SEC.c\
		valid/check_path.c\
		valid/free_ar.c\
		valid/check_extension.c\
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
		libft/ft_bzero.c\
		libft/ft_split.c\
		libft/ft_strcmp.c\
		libft/putadrs.c\
		libft/putch.c\
		libft/puthex.c\
		libft/putnb.c\
		libft/putst.c\
		libft/putunb.c\
		libft/ft_printf.c
	
OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o : %.c so_long.h gnxtL/get_next_line.h
	@$(CC) $(CFLAGS) -c $< $(HEADERS) -o $@


	
clone_mlx :
	@git clone https://github.com/codam-coding-college/MLX42.git

build :
	@cmake ./MLX42 -B ./MLX42/build && make -C ./MLX42/build


$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBS) $(HEADERS) -o $@

clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

ac : all clean
