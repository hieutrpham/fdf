CC = cc -Wall -Werror -Wextra -MMD -MP -Wunreachable-code -Ofast
NAME = fdf
SRC_PATH = src/
OBJ_PATH = obj/
LIBFT_PATH = ./libft/
LIBFT = $(LIBFT_PATH)libft.a
LIBMLX = ./MLX42
LIBX := $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
INCLUDE = -I. -Iinclude/ -I$(LIBMLX)/include

GREEN := \033[32m
RESET := \033[0m

SRC = main.c \
	  draw.c

SRCS = $(addprefix $(SRC_PATH), $(SRC))

OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))
DEP = $(addprefix $(OBJ_PATH), $(SRC:.c=.d))

all: libmlx $(OBJ_PATH) $(LIBFT) $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $^ -o $@ $(LIBFT) $(LIBX)
	@printf "$(GREEN)$(NAME) created successfully!$(RESET)\n"

$(LIBFT):
	make -C $(LIBFT_PATH)

clean:
	rm -rf $(OBJ_PATH) $(DEP) 
	make -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all

debug:
	make CC="$(CC) -g" re

asan:
	make CC="$(CC) -fsanitize=address" re

.PHONY: all re clean fclean debug asan

-include $(DEP)
