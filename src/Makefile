.PHONY: build 
CC=g++
CFLAGS=
LDFLAGS=
BLOC= ../release/TicTacToe
SOURCES=play.cpp ../test/playTest.cpp
NAME=deliverable
NC=\033[0m # no color
info=\033[0;33m
green=\033[0;32m

lib=-lUnitTest++

all:
	$(CC) $(SOURCES) -o $(NAME) $(lib)

checkin:
	@$(CC) $(SOURCES) -o test $(lib)
	git add $(SOURCES) Makefile
	git commit -am "$(MAKECMDGOALS)" 
	git push
	$(MAKE) clean

build:
	@echo "\n$(info)Building...$(NC)\n"
	@rm -rf *.o test $(NAME) 
	@$(CC) $(SOURCES) -o $(BLOC) $(lib) 
	@$(BLOC)
	@rm -rf test
	@echo ""

clean:
	rm -rf *.o test $(BLOC)

