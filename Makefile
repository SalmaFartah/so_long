CC = cc

HEADERS	= -I ./MLX42/include

CFLAGS = -Wall -Wextra -Werror -Wunreachable-code -Ofast

USER = sfartah

LIBS = ./MLX42/build/libmlx42.a -I include -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/"

NAME = so_long

SRC = 	so_long.c\
		init_map.c\
		draw_map.c\
		move.c\
		init_game.c\
		list_to_array.c\
		valid/costruction.c\
		valid/check_walls.c\
		valid/check_sec.c\
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

GRAY = \033[0;90m
DEFAULT = \033[0;39m
BLACK   = \033[0;30m
RED     = \033[0;31m
GREEN   = \033[0;32m
YELLOW  = \033[0;33m
BLUE    = \033[0;34m
MAGENTA = \033[0;35m
CYAN    = \033[0;36m
WHITE   = \033[0;37m

# Bold Text Colors
BOLD_BLACK   = \033[1;30m
BOLD_RED     = \033[1;31m
BOLD_GREEN   = \033[1;32m
BOLD_YELLOW  = \033[1;33m
BOLD_BLUE    = \033[1;34m
BOLD_MAGENTA = \033[1;35m
BOLD_CYAN    = \033[1;36m
BOLD_WHITE   = \033[1;37m

all : $(NAME)

%.o : %.c so_long.h gnxtL/get_next_line.h
	@echo "$(BOLD_MAGENTA)Building object file $@…$(DEFAULT)"
	@$(CC) $(CFLAGS) -c $< $(HEADERS) -o $@
	
clone_mlx :
	@git clone https://github.com/codam-coding-college/MLX42.git

build :
	@cmake ./MLX42 -B ./MLX42/build && make -C ./MLX42/build

$(NAME) : $(OBJ)
	@echo "$(BOLD_BLUE)─────────────────────────────────────────"
	@echo "✅ linking to executable file <$(NAME)>…"
	@echo "─────────────────────────────────────────$(DEFAULT)"
	@$(CC) $(CFLAGS) $(OBJ) $(LIBS) $(HEADERS) -o $@

clean :
	@echo "$(GRAY)🧹 cleaning object files…$(DEFAULT)"
	@rm -rf $(OBJ)

fclean :
	@echo "$(GRAY)🚮 Full clean…$(DEFAULT)"
	@rm -rf MLX42
	@rm -rf $(NAME) $(OBJ)

re : fclean all

ac : all clean
