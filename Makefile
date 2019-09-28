GREEN = $(shell printf "\e[38;5;10m")
WHITE = $(shell printf "\e[39m")
RED = $(shell printf "\033[0;31m")
YELLOW = $(shell printf "\033[0;33m")

NAME = pathfinding
INCL = -Iincludes -Iminilibx_macos -Ift_libft/includes
LIB = -Lminilibx_macos -lmlx ft_libft/libft.a
FRAMEWORK = -framework OpenGL -framework AppKit
SOURCE = draw grid init keyconf_keys keyconf_mouse main nodes pathfinding pixels time
CFILES = $(SOURCE:%=source/%.c)
OFILES = $(SOURCE:%=.objects/%.o)
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):  .objects $(OFILES) ft_libft/libft.a
	@gcc -o $(NAME) $(OFILES) $(LIB) $(INCL) $(FRAMEWORK) $(FLAGS) -O3
	@echo "$(YELLOW)√$(WHITE)"

.objects/%.o: source/%.c includes/pathfinding.h
	@echo "$(GREEN)Compiling$(WHITE) : $<"
	@gcc -o $@ -c $< $(INCL) -O3

.objects:
	@mkdir .objects

ft_libft/libft.a:
	@make -C ft_libft

clean:
	@rm -f $(OFILES)
	@make clean -C ft_libft/

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ft_libft
	@echo "$(RED)Cleaning...$(WHITE)"

re: fclean all
