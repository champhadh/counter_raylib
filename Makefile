CC = gcc
CFLAGS = -Wall -Wextra -g $(shell pkg-config --cflags raylib)
LIBS = $(shell pkg-config --libs raylib)

counter: window.c
	$(CC) $(CFLAGS) window.c -o counter $(LIBS)

clean:
	rm -f counter