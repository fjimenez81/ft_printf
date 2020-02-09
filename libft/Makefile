# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fjimenez <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/18 08:07:14 by fjimenez          #+#    #+#              #
#    Updated: 2019/11/28 11:21:48 by fjimenez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

RM = rm -rf

CC = gcc

HEADER = libft.h

CFLAGS = -Wall -Wextra -Werror

SRCS =  ft_calloc.c ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
		ft_isdigit.c ft_isprint.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
		ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c \
		ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c \
		ft_strrchr.c ft_tolower.c ft_toupper.c ft_substr.c ft_strjoin.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_strtrim.c \
		ft_itoa.c ft_putnbr_fd.c ft_strmapi.c ft_split.c

OBJ = $(SRCS:.c=.o) 
		
BONUSSRC =	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c \
			ft_lstiter_bonus.c ft_lstmap_bonus.c

BONUSOBJ = $(BONUSSRC:.c=.o)

all: $(NAME) bonus

$(NAME):$(OBJ) $(HEADER)
		@$(CC) $(CFLAGS) -c $(SRCS) -I./includes/
		@ar -rcs $(NAME) $(OBJ) $(HEADER)
		@ranlib $(NAME)

bonus:	$(BONUSOBJ) $(HEADER)
		@$(CC) $(CFLAGS) -c $(BONUSSRC) -I./includes/
		@ar -rcs $(NAME) $(BONUSOBJ) $(HEADER)
		@ranlib $(NAME)
		
clean:
		@$(RM) $(OBJ) $(BONUSOBJ)

fclean: clean
		@$(RM) $(NAME)

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re
