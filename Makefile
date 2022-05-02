NAME	=	get_next_line

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -D BUFFER_SIZE=1000
AFLAGS	=	-crs
RM 		=	rm -rf

SRCS	=	$(wildcard *.c)
OBJS	=	$(SRCS:.c=.o)

# Targets
test:
	@clear
	@$(CC) $(CFLAGS) -o test $(SRCS)
	@./test
	@rm test

# Removes objects
clean:
	@$(RM) $(OBJS)

# Removes objects and executables
fclean: clean
	@$(RM) $(NAME)
