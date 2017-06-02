# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/02 23:46:42 by anonymous         #+#    #+#              #
#    Updated: 2017/06/03 00:11:29 by anonymous        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a
SRC_PATH = src
SRC_FILES = 	ft_printf.c


SRC = $(addprefix $(SRC_PATH)/, $(SRC_FILES))
OBJ_PATH = obj
LIB_PATH = libft
LIB = $(LIB_PATH)/libft.a
INCLUDES_PATH = includes
INCLUDES = -I $(INCLUDES_PATH) -I $(LIB_PATH)
GREEN= \033[0;32m
NC= \033[0m
OBJ = $(addprefix $(OBJ_PATH)/, $(SRC_FILES:.c=.o))

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	cp $(LIB) $@
	ar rc $@ $^
	ranlib $@

$(LIB):
	make -C $(LIB_PATH)

obj/%.o: $(SRC_PATH)/%.c
	gcc $(INCLUDES) -c -o $@ $<

clean:
	make -C $(LIB_PATH) clean
	/bin/rm -f $(OBJ)

fclean: clean
	rm -f $(LIB)
	rm -f $(NAME)

re : clean all