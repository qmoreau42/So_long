# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qmoreau <qmoreau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 15:55:56 by qmoreau           #+#    #+#              #
#    Updated: 2022/08/31 15:06:08 by qmoreau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	= libft.a

SRC_DIR	= ./

SRC		= ft_bzero.c\
		  ft_isalpha.c\
		  ft_isdigit.c\
		  ft_memcpy.c\
		  ft_memset.c\
		  ft_tolower.c\
		  ft_toupper.c\
		  ft_isalnum.c\
		  ft_isascii.c\
		  ft_isprint.c\
		  ft_memmove.c\
		  ft_strlen.c\
		  ft_strlcpy.c\
		  ft_strlcat.c\
		  ft_strchr.c\
		  ft_strrchr.c\
		  ft_strncmp.c\
		  ft_memchr.c\
		  ft_memcmp.c\
		  ft_strnstr.c\
		  ft_atoi.c\
		  ft_calloc.c\
		  ft_strdup.c\
		  ft_substr.c\
		  ft_strjoin.c\
		  ft_strtrim.c\
		  ft_putchar_fd.c\
		  ft_putstr_fd.c\
		  ft_putendl_fd.c\
		  ft_putnbr_fd.c\
		  ft_split.c\
		  ft_itoa.c\
		  ft_strmapi.c\
		  ft_striteri.c\
		  ft_printf.c\
		  ft_printf_c_s_i.c\
		  ft_printf_p_d_u.c\
		  ft_printf_perc_x_X.c\
		  get_next_line_bonus.c\
		  get_next_line_utils_bonus.c

SRCS	= ${addprefix ${SRC_DIR}, ${SRC}}

BONUS	= ft_lstnew.c\
		  ft_lstadd_front.c\
		  ft_lstsize.c\
		  ft_lstlast.c\
		  ft_lstadd_back.c\
		  ft_lstdelone.c\
		  ft_lstclear.c\
		  ft_lstiter.c\
		  ft_lstmap.c


OBJS	= ${SRCS:.c=.o}

B_OBJS	= ${BONUS:.c=.o}

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

#so:
#	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS) ${BONUS}
#	gcc -nostartfiles -shared -o libft.so $(OBJS) ${B_OBJS}

all: ${NAME}

${NAME} : ${OBJS}
	ar rc ${NAME} ${OBJS}

bonus:	${OBJS} ${B_OBJS}
	ar rc ${NAME} ${OBJS} ${B_OBJS}

clean:
	rm -f ${OBJS} ${B_OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus
