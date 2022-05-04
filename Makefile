
NAME	=	test

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
RM 		=	rm -rf

SRCS	=	$(wildcard *.c)
OBJS	=	$(SRCS:.c=.o)

# Test function used with main
$(NAME): $(SRCS)
	@clear
	@$(CC) $(CFLAGS) -o $@ $^
	@./test
	@$(RM) $@