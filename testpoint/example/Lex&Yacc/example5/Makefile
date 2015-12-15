NAME=example5
LEX=flex
YACC=bison
CC=g++

$(NAME): lex.yy.o $(NAME).tab.o
	$(CC) lex.yy.o $(NAME).tab.o -o $(NAME)

lex.yy.o: lex.yy.c $(NAME).tab.h
	$(CC) -c lex.yy.c

$(NAME).tab.o: $(NAME).tab.c $(NAME).tab.h
	$(CC) -c $(NAME).tab.c

$(NAME).tab.c  $(NAME).tab.h: $(NAME).y
	$(YACC) -d $(NAME).y

lex.yy.c: $(NAME).l
	$(LEX) $(NAME).l

clean:
	rm -f *.o *.c *.h $(NAME)
        

