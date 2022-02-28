CFILES = ./mandatory/push_swap.c  ./mandatory/sa_pa_ra_rra.c  ./mandatory/sb_pb_rb_rrb.c  \
		./mandatory/ss_rr_rrr.c

OFILES = ${CFILES:.c=.o}

CBONUS = 
OBONUS = ${CBONUS:.c=.o}

CC = gcc
W = -Wall -Werror -Wextra
INC = ./mandatory/push_swap.h
INCB = ./bonus/push_swap_bonus.h
NAME = push_swap

YELLOW=\033[1;33m
NC=\033[0m
GREEN=\033[0;32m
RED=\033[0;31m

define HEADER_M

                  _                                  
  _ __  _   _ ___| |__      _____      ____ _ _ __   
 | '_ \| | | / __| '_ \    / __\ \ /\ / / _` | '_ \  
 | |_) | |_| \__ \ | | |   \__ \\ V  V / (_| | |_) | 
 | .__/ \__,_|___/_| |_|___|___/ \_/\_/ \__,_| .__/  
 |_|                  |_____|                |_|     

endef
export HEADER_M

define HEADER_B

                  _                                    _                            
  _ __  _   _ ___| |__      _____      ____ _ _ __    | |__   ___  _ __  _   _ ___  
 | '_ \| | | / __| '_ \    / __\ \ /\ / / _` | '_ \   | '_ \ / _ \| '_ \| | | / __| 
 | |_) | |_| \__ \ | | |   \__ \\ V  V / (_| | |_) |  | |_) | (_) | | | | |_| \__ \ 
 | .__/ \__,_|___/_| |_|___|___/ \_/\_/ \__,_| .__/___|_.__/ \___/|_| |_|\__,_|___/ 
 |_|                  |_____|                |_| |_____|                            

endef
export HEADER_B

.PHONY: all clean fclean re print_header_m print_header_b

all : ${NAME}

${NAME} : print_header_m ${OFILES}
	@make -C ./libft
	@$(CC) $(OFILES) $(W) ./libft/libft.a -o $(NAME)
	@echo "${YELLOW}$(NAME) created ${NC}"

print_header_m:
	@echo " ${RED}$$HEADER_M${NC} "

print_header_b:
	@echo " ${RED}$$HEADER_B${NC} "

%.o:%.c ${INC}
	@${CC} ${W} -o $@ -c $<
	@echo "${GREEN}$@ created${NC}"

%.o:%.c ${INCB}
	@${CC} ${W} -o $@ -c $<
	@echo "${GREEN}$@ created${NC}"

clean:
	@rm -f ./mandatory/*.o
	@rm -f ./bonus/*.o
	@make fclean -C ./libft

fclean : clean
	@rm -f ${NAME}

re : fclean all

bonus: print_header_b  ${OBONUS} $(INCB)
	@$(CC) $(OBONUS) $(W) -o $(NAME)
	@echo "${YELLOW}$(NAME) created ${NC}"