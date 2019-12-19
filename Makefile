#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkayumba <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/18 17:16:34 by mkayumba          #+#    #+#              #
#    Updated: 2019/12/17 13:41:27 by mkayumba         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC	= gcc

CFLAGS	= -g -Wall -Wextra -Werror

LIBFT	= ./libft

HEADERS	= ./include/

DIR_S	= ./src

DIR_O	= temporary

RM	= rm -f

NAME	=	libftprintf.a

SOURCES	=	ft_printf.c\
		check/check_flags_width_precision.c\
		check/check_lenght_specifies.c\
		check/check_type.c\
		print_buffer/find_conv_type.c\
		put_format/format_integer.c\
		put_format/integer_width_precision.c\
		put_format/hash_and_signe.c\
		conversion/conv_character_percentage.c\
		conversion/conv_type_string_addr.c\
		conversion/conv_type_integer.c\
		conversion/ntoa.c\
		conversion/conv_type_float.c\
		conversion/fill_buffer.c\

SRC = $(addprefix $(DIR_S)/,$(SOURCES))

OBJ = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all:	$(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT)
	cp ./libft/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p temporary
	@mkdir -p temporary/check/
	@mkdir -p temporary/print_buffer
	@mkdir -p temporary/put_format
	@mkdir -p temporary/conversion
	@$(CC) $(CFLAGS) -I $(HEADERS) -o $@ -c $<

clean:
	@rm -rf $(DIR_O)
	@rm -f $(OBJ)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all