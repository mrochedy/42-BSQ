NAME = bsq

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS =	main.c \
		read_map.c \
		check_map.c \
		ft_split.c \
		get_int_map.c \
		fill_square_in_map.c \
		get_biggest_square.c \
		print_final_map.c \
		tools.c \
		map_tools.c

OBJS_DIR = objs
OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

# ANSI color codes
GREEN = \033[1;32m
YELLOW = \033[1;33m
WHITE = \033[1;97m
BLUE = \033[1;34m
CYAN = \033[1;36m
RED = \033[1;31m
RESET = \033[0m

COL1 = \033[38;2;255;204;153m # Pastel orange
COL2 = \033[38;2;255;214;140m # Light pastel orange
COL3 = \033[38;2;255;224;128m # Pastel yellow-orange
COL4 = \033[38;2;255;234;115m # Pastel orange-yellow
COL5 = \033[38;2;255;244;102m # Light pastel yellow
COL6 = \033[38;2;255;255;153m # Pastel yellow

all: $(NAME)

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "$(CYAN)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@echo "\n$(YELLOW)Linking objects...$(RESET)"
	@$(CC) $(OBJS) -o $(NAME)
	@echo "$(BLUE)Progress: 100%$(RESET)"
	@echo "$(GREEN)Compilation complete!$(RESET)\n"
	@echo "$(COL1)██████╗ ███████╗ ██████╗ "
	@echo "$(COL2)██╔══██╗██╔════╝██╔═══██╗"
	@echo "$(COL3)██████╔╝███████╗██║   ██║"
	@echo "$(COL4)██╔══██╗╚════██║██║▄▄ ██║"
	@echo "$(COL5)██████╔╝███████║╚██████╔╝"
	@echo "$(COL6)╚═════╝ ╚══════╝ ╚══▀▀═╝ $(RESET)\n"

clean:
	@rm -rf $(OBJS_DIR)
	@echo "$(RED)Cleaned object files.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)Removed executable.$(RESET)"

re: fclean all

.PHONY : all clean fclean re
