.PHONY: build 
CC=g++
CFLAGS=
LDFLAGS=
BLOC= release/TicTacToe
SOURCES=src/play.cpp
TESTS=test/playTest.cpp
NAME=BoardGame
NC=\033[0m # no color
info=\033[0;33m
green=\033[0;32m

lib=-lUnitTest++

all:
	$(CC) $(SOURCES) $(TESTS) -o $(BLOC) $(lib)

checkin:
	@$(CC) $(SOURCES) $(TESTS) -o $(BLOC) $(lib)
	git add $(SOURCES) $(TESTS) Makefile
	git commit -am "$(MAKECMDGOALS)" 
	git push
	$(MAKE) clean

build:
	@echo "\n$(info)Building...$(NC)\n"
	@rm -rf *.o $(BLOC) 
	@$(CC) $(SOURCES) $(TESTS) -o $(BLOC) $(lib) 
	@$(BLOC)
	@rm -rf
	@echo ""

clean:
	rm -rf *.o $(BLOC)

