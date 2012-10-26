.PHONY: test
CC=g++
CFLAGS=
LDFLAGS=
SOURCES=test.cpp parser.cpp
info=\033[0;33m
NC=\033[0m # no color


all:
	$(CC) parser.cpp -o parser

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
	rm -rf *.o test parser

