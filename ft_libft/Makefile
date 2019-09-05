# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fhignett <fhignett@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/04/19 13:58:37 by fhignett       #+#    #+#                 #
#    Updated: 2019/04/19 14:02:30 by fhignett      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

all: $(NAME)

$(NAME):
	@make -C libft
	@mv libft/$(NAME) $(NAME)
	@make clean

clean:
	@make clean -C libft

fclean: clean
	@rm -f $(NAME)

re: fclean all
