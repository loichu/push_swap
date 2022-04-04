# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/14 17:48:26 by lhumbert          #+#    #+#              #
#    Updated: 2022/04/04 21:56:02 by lhumbert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                     Config                                   #
################################################################################

NAME			= push_swap
AUTHOR			= loichu
DATE			= 04/04/2022

SRCS = push.c rotate.c swap.c wheel_sort.c presort.c node.c math.c errors.c \
		chunks.c analyze.c basic_sort.c move_utils.c utils.c
MAIN = main.c

################################################################################
#                                    Compile                                   #
################################################################################

SRCS_DIR	= src
OBJS_DIR	= obj
OBJS		= $(addprefix $(OBJS_DIR)/, ${SRCS:.c=.o})
MAIN_OBJ	= $(addprefix $(OBJS_DIR)/, ${MAIN:.c=.o})

LIBFT		= libft.a
LIBFT_DIR	= libft

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -I . -I $(SRCS_DIR) -I $(LIBFT_DIR)
DBG_FLAGS	= -g -fsanitize=address

################################################################################
#                                     Colors                                   #
################################################################################

COM_COLOR   = \033[0;34m
OBJ_COLOR   = \033[0;36m
OK_COLOR    = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR  = \033[0;33m
NO_COLOR    = \033[m

################################################################################
#                                      Rules                                   #
################################################################################

all:		header $(NAME)

header:
			@printf "%b" "$(OK_COLOR)"
			@echo "$$(cat logo.ascii)"
			@echo
			@printf "%b" "$(OBJ_COLOR)Author:	$(WARN_COLOR)$(AUTHOR)\n"
			@printf "%b" "$(OBJ_COLOR)Date: 	$(WARN_COLOR)$(DATE)\n\033[m"
			@printf "%b" "$(OBJ_COLOR)CC: 	$(WARN_COLOR)$(CC)\n\033[m"
			@printf "%b" "$(OBJ_COLOR)Flags: 	$(WARN_COLOR)$(CFLAGS)\n\033[m"
			@echo

$(NAME):		$(OBJS) $(MAIN_OBJ)
				$(CC) $(OBJS) $(MAIN_OBJ) $(CFLAGS) $(LIBFT_DIR)/$(LIBFT) \
					-o $(NAME)

obj/%.o:		$(SRCS_DIR)/%.c $(LIBFT_DIR)/$(LIBFT)
				@mkdir -p $(dir $@)
				$(CC) $(CFLAGS) -c $< -o $@

debug:			$(OBJS) $(MOCK_OBJS)
				$(CC) $(OBJS) $(MAIN_OBJ) $(CFLAGS) $(DBG_FLAGS) \
					$(LIBFT_DIR)/$(LIBFT) -o $(NAME)

clean:
				rm -rf $(OBJS) $(MAIN_OBJ)

fclean:			clean
				rm -rf $(NAME)
				$(MAKE) -C $(LIBFT_DIR) fclean

$(LIBFT_DIR)/$(LIBFT):
				$(MAKE) -C $(LIBFT_DIR) all
				$(MAKE) -C $(LIBFT_DIR) bonus

re:				fclean all

.PHONY:			all clean fclean re header
