# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nelbi <neleon@student.42.fr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/20 11:24:02 by nelbi             #+#    #+#              #
#    Updated: 2025/04/01 14:56:35 by nelbi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RESET				= \e[0m\033[0m
GREEN				= \033[0;32m\e[1m

NAME 				= fixed
CC					= c++
FLAGS				= -Wall -Wextra -Werror -g3 -std=c++98 -MMD -MP

SRC_DIR				= .
SRCS				= main.cpp Fixed.cpp

RM					= rm -rf
OBJS_DIR			= ./objs/

OBJS_FILES 			= ${SRCS:.cpp=.o}

OBJS				= ${addprefix ${OBJS_DIR}, ${OBJS_FILES}}

DEPS				= ${OBJS:.o=.d}

${OBJS_DIR}%.o: ${SRC_DIR}/%.cpp
	@mkdir -p ${@D}
	@${CC} ${FLAGS} -c $< -o $@

${NAME}: ${OBJS}
	@${CC} ${FLAGS} ${OBJS} -o ${NAME}
	@echo "${GREEN}ex01		: DONE!${RESET}"

all: ${NAME}

clean:
	@${RM} ${OBJS_DIR} ${DEPS}
	@echo "${GREEN}Clean		: DONE!${RESET}"

fclean: clean
	@${RM} ${NAME}
	@echo "${GREEN}Full Clean	: DONE!${RESET}"

-include ${DEPS}

re: fclean all

.PHONY: all clean fclean re
