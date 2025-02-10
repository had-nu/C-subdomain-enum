CC = gcc
CFLAGS = -Iheaders -Wall -Wextra -Werror
DEPS = headers/subenum.h
OBJ = src/main.o src/subenum.o

%.o: src/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

subenum: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f src/*.o subenum
