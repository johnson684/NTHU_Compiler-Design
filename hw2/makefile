LEX = flex
CC = gcc
BYACC = byacc
YACC = yacc
TESTFILE = test.txt

all: parser

ytab: parser.y
	$(BYACC) -d parser.y

lex.yy.c: $(LEX_FILE)
	$(LEX) scanner.l

parser: lex.yy.c ytab
	$(CC) -o parser lex.yy.c y.tab.c -lfl
	
conflict: parser.y
	${YACC} -v parser.y

test: parser
	./parser < $(TESTFILE)

clean:
	rm -f lex.yy.c y.tab.c y.tab.h parser
