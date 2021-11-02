GREEN = \033[38;5;2m
NORMAL = \033[38;5;255m
RED = \033[38;5;1m
BLUE = \033[38;5;4m

SRCS	=	get_next_line/get_next_line.c\
			get_next_line/get_next_line_utils.c\
			main.c\
			keyboard.c\
			error_txt.c\
			utils.c\
			check_maps.c\
			exit.c\
			change_position.c\
			check_position.c\
			create_img.c\
			change_maps.c\
			check_input.c

OBJS	= $(SRCS:.c=.o)

NAME	= so_long

GCC		= gcc

FLAGS	= -Wall -Wextra -Werror -fsanitize=address -g

HEADER_FILE = so_long.h

MLX_DIR	= minilibx_opengl

MLX_LIB = libmlx.a

LINKS = -framework OpenGL -framework AppKit

all:	$(NAME)

$(NAME):	$(OBJS)
	$(MAKE) -C $(MLX_DIR)
	$(GCC) $(FLAGS) -o $(NAME) $(OBJS) $(MLX_DIR)/$(MLX_LIB) $(LINKS)

%.o: %.c $(HEADER_FILE)
	@echo "$(GREEN)Compiling:$(NORMAL)"
	$(GCC) -c $< -o $(<:.c=.o)
	@echo "$(GREEN)Successfully compiled!$(NORMAL)"

clean:
	@echo "$(RED)Removing all object files...$(NORMAL)"
	rm -f $(OBJS)
	make -C $(MLX_DIR) clean
	@echo "$(GREEN)Succesfully removed all object files!$(NORMAL)"

fclean: clean
	@echo "$(RED)Removing libraries and bitmap file...$(NORMAL)"
	rm -f $(NAME)
	make -C $(MLX_DIR) clean
	@echo "$(GREEN)Successfully removed libraries and bitmap file!$(NORMAL)"

re: fclean all

.PHONY:	clean fclean re
