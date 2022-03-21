CBONUS = ft_printf_bonus.c ft_printf_bonus_utils1.c
OBONUS = ${CBONUS:.c=.o}

CC = gcc
W = -Wall -Werror -Wextra
INC = ft_printf.h
NAME = libftprintf.a

YELLOW=\033[1;33m
NC=\033[0m
GREEN=\033[0;32m
RED=\033[0;31m

all : ${NAME}

${NAME} : ${OBONUS} ${INC}
	@ar -rcs ${NAME} ${OBONUS}
	@echo "${YELLOW}libftprintf.a created 👍${NC}"

%.o:%.c
	@${CC} ${W} -o $@ -c $<
	@echo "${GREEN}$@ created ✅${NC}"

clean:
	@rm -f ${OBONUS}

fclean : clean
	@rm -f ${NAME}

re : fclean all

bonus : all