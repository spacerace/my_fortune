CC=gcc
OPTS=-Wall -Werror -Os
SRC=fortune.c
OUT=fortune
SIZE=size

all:
	$(CC) $(OPTS) $(SRC) -o $(OUT)
	$(SIZE) $(OUT)
