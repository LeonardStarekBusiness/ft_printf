NAME = libftprintf.a

CFLAGGEN = -Wall -Wextra -Werror -g
ARFLAGGEN = rcs

CC = cc
AR = ar

QUELLE_DATEIEN = ft_printf.c \
	utils/ft_putchar.c utils/ft_putstr.c \
	utils/ft_putnbr.c utils/ft_putuint.c \
	utils/ft_putptr.c \
	utils/ft_put_low_hex.c utils/ft_put_upper_hex.c

OBJEKT_DATEIEN = $(QUELLE_DATEIEN:.c=.o)


all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGGEN) -c $< -o $@

$(NAME): $(OBJEKT_DATEIEN)
	$(AR) $(ARFLAGGEN) $(NAME) $(OBJEKT_DATEIEN)

clean: 
	rm -f $(OBJEKT_DATEIEN)

fclean: clean 
	rm -f $(NAME)

re: fclean all

.PHONY: all clean flcean re
