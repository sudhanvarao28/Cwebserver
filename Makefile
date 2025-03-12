CC = gcc
CFLAGS = -Wall -Wextra -g
SRC = server/server.c tests/test_server.c 
OUT = tll.out

all:
	$(CC) $(CFLAGS) -o $(OUT) $(SRC)

clean:
	rm -f $(OUT)
