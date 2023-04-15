CC = cc
CFLAGS = -Wall -Werror -Wextra
SRS_C = client.c
SRS_S = server.c
PRINT = ./printf/libftprintf.a ./printf/libft/libft.a

NAME = minitalk
CLIENT_NAME = client
SERVER_NAME = server

ifdef WITH_BONUS
	SRS_C = client_bonus.c
	SRS_S = server_bonus.c
endif

all: $(NAME)

$(NAME): $(CLIENT_NAME) $(SERVER_NAME)

bonus:
	$(MAKE) WITH_BONUS=1

$(CLIENT_NAME): $(SRS_C) $(PRINT)
	$(CC) $(CFLAGS) -o $(CLIENT_NAME) $(SRS_C) $(PRINT)

$(SERVER_NAME): $(SRS_S) $(PRINT)
	$(CC) $(CFLAGS) -o $(SERVER_NAME) $(SRS_S) $(PRINT)

$(PRINT):
	make -C ./printf

clean:
		$(RM) $(CLIENT_NAME) $(SERVER_NAME)
		$(MAKE) clean -C ./printf

fclean: clean
		$(RM) $(CLIENT_NAME) $(SERVER_NAME)
		$(MAKE) fclean -C ./printf

re: fclean all

.PHONY: all clean fclean re $(NAME)