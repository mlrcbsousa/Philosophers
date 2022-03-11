# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msousa <msousa@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/29 15:00:20 by msousa            #+#    #+#              #
#    Updated: 2022/03/11 01:03:58 by msousa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	= -Wall -Wextra -Werror -pthread
CC		= gcc
RM		= rm -f
INC		= -Iinclude
OBJ		= ${SRC:.c=.o}
SRC		= 	philo.c \
			routine.c \
			lib/ft_atoi.c \
			lib/ft_isdigit.c \
			lib/ft_isnumber_u.c \
			lib/ft_isspace.c \
			lib/ft_timenow.c \
			lib/ft_usleep.c

NAME	= philo

${NAME}:	${OBJ}
			${CC} ${CFLAGS} ${OBJ} -o $@

%.o:%.c
			${CC} ${CFLAGS} ${INC} -c $< -o $@

all:		${NAME}

style:
			-norminette $$( find . -type f \( -name "*.c" -or -name "*.h" \) )

test:		${NAME}
			-./tests.sh

clean:
			${RM} ${OBJ}

fclean:		clean
			${RM} ${NAME}

re: 		fclean all

debug:		INC += -DDEBUG_MODE
debug:		CFLAGS += -g -fsanitize=address
debug:		clean
debug:		all

.PHONY : 	all clean fclean re bonus
