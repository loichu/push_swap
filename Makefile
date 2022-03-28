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

SRCS = main.c push.c rotate.c swap.c wheel_sort.c presort.c node.c math.c errors.c chunks.c analyze.c basic_sort.c move_utils.c
DEBUG_SRCS = print_debug.c
MOCK_SRCS = mock_debug.c

OBJS = $(SRCS:.c=.o)
DEBUG_OBJS = $(DEBUG_SRCS:.c=.o)
MOCK_OBJS = $(MOCK_SRCS:.c=.o)

RM = rm -f

all:			$(NAME)

$(NAME):		$(OBJS) $(MOCK_OBJS)
				gcc -o $(NAME) $(OBJS) $(MOCK_OBJS) $(CFLAGS) $(LDFLAGS)

debug:			$(OBJS) $(DEBUG_OBJS)
				gcc -o $(NAME) $(OBJS) $(DEBUG_OBJS) $(CFLAGS) $(LDFLAGS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus
