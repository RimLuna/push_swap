# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbougssi <rbougssi@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/30 04:33:27 by rbougssi          #+#    #+#              #
#    Updated: 2021/06/30 04:33:29 by rbougssi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap

SPATH := srcs
SFILES := algo.c ff.c helper.c \
		init.c instruct.c instruct2.c \
		median.c push_swap.c smol.c

CC = gcc
AR = ar rc
IPATH = includes/
OPATH = obj
IFLAG = -I $(IPATH)
CFLAGS = -Wall -Wextra $(IFLAG)
OBJ = $(SFILES:.c=.o)
OBJS = $(addprefix $(OPATH)/, $(OBJ))
SRCS = $(addprefix $(SPATH)/, $(SFILES))

all:	$(NAME)

$(NAME): $(SRCS)
		$(CC) $(CFLAGS) $(SRCS) -o $@

clean:
	@/bin/rm -rf $(OPATH)

fclean:
	@/bin/rm -rf $(OPATH)
	@/bin/rm -rf $(NAME)

re: fclean all