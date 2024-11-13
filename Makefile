SERVER = server
CLIENT = client

CFLAGS = -Wall -Werror -Wextra
CC = gcc
PRINTF = ft_printf
LIBFT = libft
LIBFT_LIB = $(LIBFT)/libft.a
PRINTF_LIB = $(PRINTF)/libftprintf.a

FLAGS = -I$(PRINTF) -I$(LIBFT) -L$(PRINTF) -L$(LIBFT) -lftprintf -lft

all: $(SERVER) $(CLIENT)

$(SERVER): server.c minitalk.h
	@echo "Building server..."
	@make -C $(PRINTF)
	@make -C $(LIBFT)
	$(CC) $(CFLAGS) server.c $(PRINTF_LIB) $(LIBFT_LIB) -o $(SERVER)
	@echo "Server is ready!"

$(CLIENT): client.c minitalk.h
	@echo "Building client..."
	@make -C $(PRINTF)
	@make -C $(LIBFT)
	$(CC) $(CFLAGS) client.c $(PRINTF_LIB) $(LIBFT_LIB) -o $(CLIENT)
	@echo "Client is ready!"

clean:
	@echo "Cleaning up..."
	@make clean -C $(PRINTF)
	@make clean -C $(LIBFT)
	@rm -f $(SERVER) $(CLIENT)
	@echo "Clean complete."

fclean: clean
	@echo "Full cleaning..."
	@make fclean -C $(PRINTF)
	@make fclean -C $(LIBFT)
	@rm -f $(SERVER) $(CLIENT)
	@echo "Full clean complete."

re: fclean all
