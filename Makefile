CC=g++
CFLAGS=
LDFLAGS=
SOURCES=src/TicTacToe.cpp
NAME=deliverable
info=\033[0;33m
NC=\033[0m # no color

lib=-lUnitTest++

all:
	$(CC) $(SOURCES) -o $(NAME) $(lib)

checkin:
	@$(CC) test.cpp -o test $(lib)
	git add src release Makefile
	git commit -am "automated commit"
	git push
	$(MAKE) clean

clean:
	rm -rf *.o test deliverable 

