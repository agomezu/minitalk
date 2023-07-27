CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIBFT = libft/libft.a

CLIENT_SRCS = client.c
SERVER_SRCS = server.c

all: $(LIBFT) client server

$(LIBFT):
	make -C libft

client: $(CLIENT_SRCS)
	$(CC) $(CFLAGS) -o client $(CLIENT_SRCS) $(LIBFT)

server: $(SERVER_SRCS)
	$(CC) $(CFLAGS) -o server $(SERVER_SRCS) $(LIBFT)

clean:
	make -C libft clean
	rm -f client server

re: clean all

