CC = gcc
CFLAGS = -Wall -Wextra -g
SRC = src/main.c src/hash_table.c
OUT = mydb

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT)