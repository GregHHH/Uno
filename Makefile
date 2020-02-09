NAME = Uno

SRC = src/main.c src/traduction.c

all: $(NAME) 

$(NAME):
	gcc -o $(NAME) $(SRC)
clean:
	/bin/rm -f
fclean: clean
	/bin/rm -f $(NAME)
re: fclean all