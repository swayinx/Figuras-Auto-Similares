CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -I.
LDLIBS = -lcsfml-graphics -lcsfml-window -lcsfml-system -lX11 -lm

all: $(patsubst examples/%.c, %, $(wildcard examples/*.c))

%: examples/%.c turtlec.c turtlec.h
	$(CC) $(CFLAGS) turtlec.c $< -o $@ $(LDLIBS)

clean:
	rm -f $(patsubst examples/%.c, %, $(wildcard examples/*.c))
