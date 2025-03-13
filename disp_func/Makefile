CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRC = ft_printf.c	putch.c 	putst.c		putnb.c		putunb.c 	putadrs.c 	puthex.c

OBJ = $(SRC:%.c=%.o)

HDRF = ft_printf.h

%.o : %.c $(HDRF)
	@$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ)
	@ar rc $(NAME) $(OBJ)

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all