LEX = flex
CC = gcc

LEX_FILE = scanner.l
EXECUTABLE = scanner
TESTFILE = sample_testcase.txt

all: $(EXECUTABLE)

$(EXECUTABLE): lex.yy.c
	$(CC) -o $(EXECUTABLE) lex.yy.c -lfl

lex.yy.c: $(LEX_FILE)
	$(LEX) $(LEX_FILE)

test: $(EXECUTABLE)
	./$(EXECUTABLE) < $(TESTFILE)

clean:
	rm -f lex.yy.c $(EXECUTABLE)
