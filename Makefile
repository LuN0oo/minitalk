# ===================== VARIABLES ===================== #

NAME_SERVER = server
NAME_CLIENT = client

CC = cc
CFLAGS = -Wall -Wextra -Werror

PRINTF_DIR = Printf/

PRINTF_SRC = \
	$(PRINTF_DIR)ft_printf.c \
	$(PRINTF_DIR)ft_nbr_func.c \
	$(PRINTF_DIR)ft_str_func.c

SERVER_SRC = server.c $(PRINTF_SRC)
CLIENT_SRC = client.c $(PRINTF_SRC)

SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

# ===================== RULES ===================== #

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(SERVER_OBJ)
	$(CC) $(CFLAGS) $(SERVER_OBJ) -o $(NAME_SERVER)

$(NAME_CLIENT): $(CLIENT_OBJ)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) -o $(NAME_CLIENT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# ===================== CLEAN ===================== #

clean:
	rm -f $(SERVER_OBJ) $(CLIENT_OBJ)

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all

.PHONY: all clean fclean re