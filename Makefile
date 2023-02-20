# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hece <hece@student.42kocaeli.com.tr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 15:16:39 by hece              #+#    #+#              #
#    Updated: 2023/02/20 15:16:40 by hece             ###   ########.tr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = @gcc
RM = @rm -f
FLAGS = -Wall -Wextra -Werror
BONUS_NAME = checker

SRC_1 = srcs/push_swap/push_swap.c \

SRC_2 =	srcs/push_swap/push_swap_check.c \
		srcs/push_swap/push_swap_find.c \
		srcs/push_swap/push_swap_rules.c \
		srcs/push_swap/push_swap_rules_two.c \
		srcs/push_swap/push_swap_rules_three.c \
		srcs/push_swap/ps_rotate_and_push.c \
		srcs/push_swap/ps_rotate_type.c \
		srcs/push_swap/ps_solver.c \
		srcs/push_swap/push_swap_sort.c \
		srcs/push_swap/push_swap_stack_utils.c \
		srcs/push_swap/push_swap_utils_two.c \
		srcs/push_swap/push_swap_utils.c \
		srcs/push_swap/push_swap_split.c \
		srcs/push_swap/push_swap_split_utils.c
		
BONUS_SRC = srcs/checker/checker.c \
			gnl/get_next_line.c
			

OBJ_1 = ${SRC_1:.c=.o}
OBJ_2 = ${SRC_2:.c=.o}

BONUS_OBJ =${BONUS_SRC:.c=.o}

.c.o:
	${CC} -c $< -o ${<:.c=.o} -g

${NAME}: ${OBJ_1} ${OBJ_2}
	${CC} ${FLAGS} ${OBJ_1} ${OBJ_2} -o ${NAME}
	@echo "\n\033[33mMandatory files compiled successfully ✅\033[0m\n"
${BONUS_NAME}: ${OBJ_2} ${BONUS_OBJ} 
	${CC} ${FLAGS} ${BONUS_OBJ} ${OBJ_2} -o ${BONUS_NAME}

all: ${NAME} ${BONUS_NAME}

bonus: ${BONUS_NAME} 
	@echo "\n\033[33mBonus files compiled successfully ✅\033[0m\n"
clean:
	${RM} ${OBJ_1} ${OBJ_2} ${BONUS_OBJ}
	@echo "\n\033[33mObject files compiled successfully ✅\033[0m\n"

fclean: clean
	${RM} ${NAME} ${BONUS_NAME}
	@echo "\n\033[33mAll files deleted successfully ✅\033[0m\n"

re: clean all

.PHONY: all clean fclean re bonus
