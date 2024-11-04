################################################################################
#                          Makefile configuration                              #
################################################################################

NAME		= philo
CC			= cc
CFLAG		= -Wall -Wextra -Werror -g3

################################################################################
#                                 Include                                      #
################################################################################

INCDIR 	 		= include
INC	   	 		= ${INCDIR}/philo.h
INCLUDES		= -I ${INCDIR}

################################################################################
#                                 Sources                                      #
################################################################################

SRCDIR 		= 	srcs

SRC			=	${SRCDIR}/main.c \
				${SRCDIR}/clean.c \
				${SRCDIR}/parsing.c \
				${SRCDIR}/utils.c \
				${SRCDIR}/init.c \
				${SRCDIR}/routine.c \
				${SRCDIR}/status.c \

################################################################################
#                                   Objects                                    #
################################################################################

OBJDIR 		= objs

OBJ    		= ${SRC:${SRCDIR}/%.c=${OBJDIR}/%.o}

################################################################################
#                                   Colors                                     #
################################################################################

BLACK 	= \033[0;30m
RED 	= \033[0;31m
GREEN 	= \033[0;32m
YELLOW 	= \033[0;33m
BLUE 	= \033[0;34m
PURPLE 	= \033[0;35m
CYAN 	= \033[0;36m
RESET 	= \033[0m

################################################################################
#                                    Rules                                     #
################################################################################

all: ${NAME}

${NAME} : ${OBJ} 
	@${CC} ${CFLAG} ${INCLUDES} ${OBJ} -o ${NAME}
	@echo "${YELLOW}✰✰✰ Alright, you can use ${NAME} ✰✰✰ :D${RESET}"

${OBJDIR}/%.o: ${SRCDIR}/%.c ${INC}
	@mkdir -p ${dir $@}
	@${CC} ${CFLAG} ${INCLUDES} -c $< -o $@
	@echo "${GREEN}***  PHILOSOPHERS: compilation success  ***${RESET}"

clean:
	@rm -rf ${OBJDIR}

fclean: clean
	@echo "${BLUE}➟➟➟ Fclean in progress, please wait...${RESET}"
	@rm -f ${NAME}
	@echo "${GREEN}✓✓✓ Fclean done: ${NAME} has been removed${RESET}"

re: fclean all
	@echo "${CYAN}↻↻↻ Makefile has been re'd ↺↺↺ \o/${RESET}"

.PHONY: all clean fclean re bonus
