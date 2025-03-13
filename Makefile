CC = cc

HEADERS	= -I ./MLX42/include

CFLAGS = -Wall -Wextra -Werror -Wunreachable-code -Ofast

USER = sfartah

LIBS = ./MLX42/build/libmlx42.a ./disp_func/libftprintf.a -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"

NAME = so_long

SRC = 	so_long.c\
		init_map.c\
		display_ar.c\
		draw_map.c\
		move.c\
		init_game.c\
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
		libft/ft_bzero.c\
	
OBJ = $(SRC:.c=.o)

%.o : %.c so_long.h gnxtL/get_next_line.h disp_func/ft_printf.h
	@$(CC) $(CFLAGS) -c $< $(HEADERS) -o $@

all : $(NAME)
	

$(NAME) : $(OBJ)
	@make -C ./disp_func
	@$(CC) $(CFLAGS) $(OBJ) $(LIBS) $(HEADERS) -o $@

clean :
	@make -C ./disp_func clean
	@rm -rf $(OBJ) 

fclean : clean
	@make -C ./disp_func fclean
	@rm -rf $(NAME)

re : fclean all

ac : all clean
