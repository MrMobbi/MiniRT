
	### COMPILATION ###

CC			= gcc -g -fsanitize=address
FLAGS		= -Wall -Werror -Wextra
FRAMEWORK	= -framework OpenGL -framework AppKit

	### EXECUTABLE ###

NAME		= minirt

	### PATH ###

SRCS_PATH	= srcs
OBJS_PATH	= objs
INCS_PATH	= -Iincl
MLX			= libmlx

	###	LIBS ###

LIBS		= -lmlx
LIBS_PATH	= -L$(MLX)

	### INCLUDE ###

#GNL			= srcs/gnl
#LIBFT		= srcs/libft

	### DIRECTORY ###

PARSING_DIR	= $(SRCS_PATH)/parsing

	### FILES TO OBJECT ###

SRCS	= $(wildcard $(SRCS_PATH)/*.c)\
		  $(wildcard $(PARSING_DIR)/*.c)


OBJS	= $(SRCS:$(SRCS_PATH)/%.c=$(OBJS_PATH)/%.o)

	### COLORS ###

RED			= \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
BLUE		= \033[1;34m
VIOLET		= \033[1;35m
CYAN		= \033[1;36m
WHITE		= \033[1;37m
RESET		= \033[0m

	### TEXTES ###

MLX_TXT			= echo "$(CYAN)=== Compiling MLX ===$(RESET)"
MLX_END_TXT		= echo "$(GREEN)=== MLX Compilated ===$(RESET)"
START_TXT		= echo "$(CYAN)=== Compiling Project ===$(RESET)"
END_TXT			= echo "$(GREEN)=== Project Compilated ===$(RESET)"
CHARG_LINE_TXT	= echo "$(GREEN)█$(RESET)\c"
CLEAN_TXT		= echo "$(RED) Deleting all files$(RESET)"
FCLEAN_TXT		= echo "$(RED) Deleting $(NAME)$(RESET)"
NL_TXT			= echo ""

	### RULES ###

all:		mlx tmp $(NAME)

art:
			@tput setaf 2; cat .ascii_art/projet; tput setaf default
			@tput setaf 2; cat .ascii_art/name; tput setaf default

$(NAME):	$(OBJS)
			@$(CC) $(FLAGS) $(FRAMEWORK) $(LIBS_PATH) $(LIBS) -o $@ $(OBJS)
			@$(NL_TXT)
			@$(END_TXT)

tmp:
			@mkdir -p objs

mlx:
			@$(MLX_TXT)
			make -C $(MLX)
			@cp $(MLX)/libmlx.dylib .
			@$(MLX_END_TXT)
			@$(NL_TXT)
			@$(START_TXT)

$(OBJS_PATH)/%.o:	$(SRCS_PATH)/%.c
					@mkdir -p $(@D)
					@$(CC) $(FLAGS) $(INCS_PATH) -c $< -o $@
					@$(CHARG_LINE_TXT)

clean:
			@$(CLEAN_TXT)
			@tput setaf 1; cat .ascii_art/trash; tput setaf default
			@rm -rf $(OBJS_PATH)
			@make clean -C $(MLX)

fclean:		clean
			@$(FCLEAN_TXT)
			@rm libmlx.dylib
			@rm -rf $(NAME)
			@$(NL_TXT)

re:			fclean all

.PHONY:		clean fclean re tmp libs all
