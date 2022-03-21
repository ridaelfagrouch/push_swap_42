CFILES = ./mandatory/push_swap.c  ./mandatory/sa_pa_ra_rra.c  ./mandatory/sb_pb_rb_rrb.c  \
		./mandatory/ss_rr_rrr.c  ./mandatory/stack_len_disp.c  ./mandatory/sorting.c  \
		./mandatory/best_Mvm.c  ./mandatory/start_sorting.c  ./mandatory/sorting_cases.c \
		./mandatory/best_Mv_function.c  ./mandatory/node_data.c  ./mandatory/long_i_sub.c \
		./mandatory/long_i_sub_utils.c  ./mandatory/free_stack.c  ./mandatory/check_error.c

OFILES = ${CFILES:.c=.o}

CBONUS = ./bonus/checker.c  ./bonus/get_next_line_utils.c  ./bonus/get_next_line.c  ./bonus/node_data.c \
		./bonus/sorting.c  ./bonus/stack_len_disp.c ./bonus/trim_strcmp.c  ./bonus/check_error.c \
		./bonus/free_stack.c  ./bonus/sa_pa_ra_rra.c  ./bonus/sb_pb_rb_rrb.c  \
		./bonus/ss_rr_rrr.c

OBONUS = ${CBONUS:.c=.o}

CC = gcc
W = -Wall -Werror -Wextra
INC = ./mandatory/push_swap.h
INCB = ./bonus/checker.h
NAME = push_swap
NAME_B = checker

YELLOW=\033[1;33m
NC=\033[0m
GREEN=\033[0;32m
RED=\033[0;31m
DARKVIOLET=\033[1;5;1;36m

define HEADER_M

                              █████                                                           
                             ░░███                                                            
 ████████  █████ ████  █████  ░███████              █████  █████ ███ █████  ██████   ████████ 
░░███░░███░░███ ░███  ███░░   ░███░░███            ███░░  ░░███ ░███░░███  ░░░░░███ ░░███░░███
 ░███ ░███ ░███ ░███ ░░█████  ░███ ░███           ░░█████  ░███ ░███ ░███   ███████  ░███ ░███
 ░███ ░███ ░███ ░███  ░░░░███ ░███ ░███            ░░░░███ ░░███████████   ███░░███  ░███ ░███
 ░███████  ░░████████ ██████  ████ █████ █████████ ██████   ░░████░████   ░░████████ ░███████ 
 ░███░░░    ░░░░░░░░ ░░░░░░  ░░░░ ░░░░░ ░░░░░░░░░ ░░░░░░     ░░░░ ░░░░     ░░░░░░░░  ░███░░░  
 ░███                                                                                ░███     
 █████                                                                               █████    
░░░░░                                                                               ░░░░░     
endef
export HEADER_M

define HEADER_B
                              █████                                                                      █████    
                             ░░███                                                                      ░░███     
 ████████  █████ ████  █████  ░███████              █████  █████ ███ █████  ██████   ████████            ░███████ 
░░███░░███░░███ ░███  ███░░   ░███░░███            ███░░  ░░███ ░███░░███  ░░░░░███ ░░███░░███           ░███░░███
 ░███ ░███ ░███ ░███ ░░█████  ░███ ░███           ░░█████  ░███ ░███ ░███   ███████  ░███ ░███           ░███ ░███
 ░███ ░███ ░███ ░███  ░░░░███ ░███ ░███            ░░░░███ ░░███████████   ███░░███  ░███ ░███           ░███ ░███
 ░███████  ░░████████ ██████  ████ █████ █████████ ██████   ░░████░████   ░░████████ ░███████  █████████ ████████ 
 ░███░░░    ░░░░░░░░ ░░░░░░  ░░░░ ░░░░░ ░░░░░░░░░ ░░░░░░     ░░░░ ░░░░     ░░░░░░░░  ░███░░░  ░░░░░░░░░ ░░░░░░░░  
 ░███                                                                                ░███                         
 █████                                                                               █████                        
░░░░░                                                                               ░░░░░                         
endef
export HEADER_B

.PHONY: all clean fclean re print_header_m print_header_b

all : ${NAME}

${NAME} : print_header_m ${OFILES}
	@make -C ./libft
	@make -C ./ft_printf
	@$(CC) $(OFILES) $(W) ./libft/libft.a ./ft_printf/libftprintf.a -o $(NAME)
	@echo "${YELLOW}$(NAME) created 👍 ${NC}"

print_header_m:
	@echo " ${DARKVIOLET}$$HEADER_M${NC} "

print_header_b:
	@echo " ${DARKVIOLET}$$HEADER_B${NC} "

%.o:%.c ${INC}
	@${CC} ${W} -o $@ -c $<
	@echo "${GREEN}$@ created ✅${NC}"

%.o:%.c ${INCB}
	@${CC} ${W} -o $@ -c $<
	@echo "${GREEN}$@ created ✅${NC}"

clean:
	@rm -f ./mandatory/*.o
	@rm -f ./bonus/*.o
	@make fclean -C ./libft
	@make fclean -C ./ft_printf

fclean : clean
	@rm -f ${NAME}
	@rm -f ${NAME_B}

re : fclean all

bonus: print_header_b  ${OBONUS} $(INCB)
	@make -C ./libft
	@make -C ./ft_printf
	@$(CC) $(OBONUS) $(W)  ./libft/libft.a ./ft_printf/libftprintf.a -o $(NAME_B)
	@echo "${YELLOW}$(NAME_B) created 👍 ${NC}"