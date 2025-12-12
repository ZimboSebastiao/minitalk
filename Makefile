# Nome dos executáveis
CLIENT_NAME	= client
SERVER_NAME	= server

# Diretórios
SRC_DIR		= src
OBJ_DIR		= obj
INC_DIR		= inc
LIB_DIR		= lib

# Fontes
CLIENT_SRC	= $(SRC_DIR)/client/ft_client.c \
			  $(SRC_DIR)/client/ft_states_client.c
SERVER_SRC	= $(SRC_DIR)/server/ft_server.c \
              $(SRC_DIR)/server/ft_states_server.c

# Objetos
CLIENT_OBJ	= $(CLIENT_SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
SERVER_OBJ	= $(SERVER_SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Compilador
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -I$(INC_DIR) -I$(LIB_DIR) -I$(LIB_DIR)/ft_printf

# Libft
LIBFT		= $(LIB_DIR)/libft.a
LIBFT_FLAGS	= -L$(LIB_DIR) -lft

# Regras
all: $(LIBFT) $(CLIENT_NAME) $(SERVER_NAME)

# Compila a libft
$(LIBFT):
	@make -C $(LIB_DIR) > /dev/null 2>&1
	@echo "📚 Libft compilada"

# Compila o cliente
$(CLIENT_NAME): $(CLIENT_OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(CLIENT_OBJ) $(LIBFT_FLAGS) -o $(CLIENT_NAME)
	@echo "🖥️  Cliente compilado"

# Compila o servidor
$(SERVER_NAME): $(SERVER_OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(SERVER_OBJ) $(LIBFT_FLAGS) -o $(SERVER_NAME)
	@echo "💾 Servidor compilado"

# Compila os objetos
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Limpeza
clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIB_DIR) clean > /dev/null 2>&1
	@echo "🧹 Objetos removidos"

fclean: clean
	@rm -f $(CLIENT_NAME) $(SERVER_NAME)
	@make -C $(LIB_DIR) fclean > /dev/null 2>&1
	@echo "🗑️  Executáveis e biblioteca removidos"

re: fclean all

.PHONY: all clean fclean re