NAME := push_swap

SPATH := srcs
SFILES := ff.c helper.c helper2.c \
		init.c instruct.c instruct2.c \
		push_swap.c imzine.c algikhane.c \
		check.c

CC = gcc
AR = ar rc
IPATH = includes/
OPATH = obj
IFLAG = -I $(IPATH)
CFLAGS = -Wall -Wextra -Werror $(IFLAG)
OBJ = $(SFILES:.c=.o)
OBJS = $(addprefix $(OPATH)/, $(OBJ))
SRCS = $(addprefix $(SPATH)/, $(SFILES))

all:	$(NAME)

$(NAME): $(SRCS) $(IPATH)/push_swap.h
		@$(CC) $(CFLAGS) $(SRCS) -o $@

clean:
	@/bin/rm -rf $(OPATH)

fclean:
	@/bin/rm -rf $(OPATH)
	@/bin/rm -rf $(NAME)

re: fclean all