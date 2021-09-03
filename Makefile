# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fjimenez <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/20 12:14:57 by fjimenez          #+#    #+#              #
#    Updated: 2021/09/03 09:48:49 by fjimenez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#

NAME = libftprintf.a
LIBFT =	libft.a

LIB_DIR 	= 	libft/
OBJ_DIR 	=	obj/
SRC_DIR 	= 	src/
SRC_FILES =	ft_printf.c \
		   	ft_com_param.c \
		   	ft_param_size.c \
		   	ft_init.c \
		   	ft_nb_utils.c \
		   	ft_param_search.c \
		   	ft_print_hexa_min.c \
		   	ft_print_hexa_may.c \
		   	ft_print_number.c \
		   	ft_print_porcent.c \
		   	ft_print_ptr.c \
		   	ft_print_unsig.c \
		   	ft_printf_utils.c \
		   	ft_put_char.c \
		   	ft_put_num_neg.c \
		   	ft_put_num_pos.c \
		   	ft_put_str.c \
		   	ft_utils_neg.c \
		   	ft_utils_pos.c \
			ft_utils_unsig.c \
			ft_utils_ptr.c
			   
SRC = $(SRC_FILES:%=$(SRC_DIR)%)

OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

LFLAGS = -I includes/
FLAGS = -Wall -Wextra -Werror

CC = cc
RM = rm -rf
AR = ar rcs
RANLIB = ranlib

all:	$(OBJ_DIR) $(NAME)

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)
		@echo Create: ft_printf Object directory

$(NAME): 	$(OBJ)
			@echo Loading libft
			@make -C $(LIB_DIR)
			@cp $(LIB_DIR)$(LIBFT) ./$(NAME)
			@$(AR) $(NAME) $(OBJ)
			@echo =====DONE=====

$(OBJ): $(SRC)
		@$(MAKE) $(OBJ_FILES)

$(OBJ_FILES):
		@$(CC) $(FLAGS) $(LFLAGS) -c -o $(OBJ_DIR)$@ $(SRC_DIR)$(@:%.o=%.c)
clean:	
		@$(RM) $(OBJ_DIR)
		@$(RM) $(OBJS)
		@make -C $(LIB_DIR) clean

fclean:	clean
		@$(RM) $(NAME)
		@make -C $(LIB_DIR) fclean
re: fclean all

.PHONY: all clean fclean re