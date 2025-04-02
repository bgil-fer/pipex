# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgil-fer <bgil-fer@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/06 10:07:29 by bgil-fer          #+#    #+#              #
#    Updated: 2025/04/02 14:09:48 by bgil-fer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nombre del ejecutable
NAME		=	pipex

# Compilador y flags
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -Iinclude -g3
#-g3 -fsanitize=address

# Directorios
SRCDIR		=	src
OBJDIR		=	obj
LIBFTDIR	=	libft

# Archivos fuente y objetos
# $(shell find $(SRCDIR) -name "*.c")
SRCS 		= 	src/main.c src/utils.c

OBJS		=	$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

# Librerías
LIBFT = $(LIBFTDIR)/libft.a

# Regla principal
all: $(NAME)

# Crear el directorio de objetos si no existe
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Compilar los archivos fuente en objetos
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Compilar la libft
$(LIBFT):
	make -C $(LIBFTDIR) -s

# Enlazar con las librerías
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)


# Limpiar archivos intermedios
clean:
	rm -rf $(OBJDIR) 
	make -C $(LIBFTDIR) clean

# Eliminar el ejecutable y objetos
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFTDIR) fclean

# Recompilar desde cero
re: fclean all

.PHONY: all clean fclean re