#source
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
	  ft_memset.c ft_bzero.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
	  ft_strncmp.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlcpy.c \
	  ft_strnstr.c ft_strlcat.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c\
	  ft_strjoin.c ft_strtrim.c

OBJS = $(SRCS:.c=.o)

#Programe
NAME = libft.a

#Compiler
CC = gcc

#Flags
CFLAGS	= -Wall -Wextra -Werror -I.

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
