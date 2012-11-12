.PHONY: test
CC=g++
CFLAGS=
LDFLAGS=
SOURCES=../src/TicTacToe.cpp
NAME=deliverable
info=\033[0;33m
NC=\033[0m # no color


all:
	$(CC) $(SOURCES) -o $(NAME)

checkin:
	@$(CC) test.cpp -o test
	git add $(SOURCES) Makefile
	git commit -am "automated commit"
	git push
	$(MAKE) clean

test:
	@echo "\n$(info)Running Tests...$(NC)\n"
	@rm -rf *.o test parser
	@$(CC) test.cpp -o test
	@./test
	@rm -rf test
	@echo ""

clean:
	rm -rf *.o src *.o test parser

