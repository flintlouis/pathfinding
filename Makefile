NAME = pathfinding
INCL = -Iincludes -Iminilibx_macos -Ift_libft/includes
LIB = -Lminilibx_macos -lmlx ft_libft/libft.a
FRAMEWORK = -framework OpenGL -framework AppKit
CFILES = *
SOURCE = $(CFILES:%=source/%.c)
OFILES = $(SOURCE:.c=.o)
FLAGS = -Wall -Werror -Wextra # ADD LATER

all: $(NAME)

$(NAME):
	@echo "Compiling..."
	@make -C ft_libft
	@gcc -o $(NAME) $(SOURCE) $(LIB) $(INCL) $(FRAMEWORK)
	@make clean
	@echo "Done"

clean:
	@make clean -C ft_libft/

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ft_libft
	@echo "Cleaning..."

re: fclean all
