CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIBFT = libft/libft.a

CLIENT_SRCS = client.c
SERVER_SRCS = server.c
CLIENT_BONUS_SRCS = client_bonus.c
SERVER_BONUS_SRCS = server_bonus.c

all: $(LIBFT) client server

$(LIBFT):
	make -C libft

client: $(CLIENT_SRCS)
	$(CC) $(CFLAGS) -o client $(CLIENT_SRCS) $(LIBFT)

server: $(SERVER_SRCS)
	$(CC) $(CFLAGS) -o server $(SERVER_SRCS) $(LIBFT)

bonus:	$(CLIENT_BONUS_SRCS) $(SERVER_BONUS_SRCS)
	$(CC) $(CFLAGS) -o client_bonus $(CLIENT_BONUS_SRCS) $(LIBFT)
	$(CC) $(CFLAGS) -o server_bonus $(SERVER_BONUS_SRCS) $(LIBFT)

clean:
	make -C libft clean
	rm -f client server client_bonus server_bonus

re: clean all
