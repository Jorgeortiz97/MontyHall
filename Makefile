CC = gcc
OBJ = main

$(OBJ): $(OBJ).c
	$(CC) -o $@ $^

.PHONY: clean

clean:
	rm -f $(OBJ)
