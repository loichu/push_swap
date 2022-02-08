# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/14 17:48:26 by lhumbert          #+#    #+#              #
#    Updated: 2021/10/22 18:47:43 by lhumbert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap

CC=gcc

CFLAGS = -Wall -Wextra -Werror -I.
LDFLAGS = -Llibft -lft

SRCS = main.c stack.c push.c rotate.c swap.c
SORT_SRC = wheel_sort.c

#BONUS_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
#	     ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS = $(SRCS:.c=.o)
SORT_OBJ = $(SORT_SRC:.c=.o)

#BONUS_OBJS = $(BONUS_SRCS:.c=.o)

RM = rm -f

all:			$(NAME)

$(NAME):		$(OBJS) $(SORT_OBJ)
			gcc -o $(NAME) $(OBJS) $(SORT_OBJ) $(CFLAGS) $(LDFLAGS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

#bonus:			$(OBJS) $(BONUS_OBJS)
#				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY:			all clean fclean re bonus
