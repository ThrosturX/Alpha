.PHONY: test
CC=g++
CFLAGS=
LDFLAGS=
SOURCES=test.cpp parser.cpp

all:
	$(CC) parser.cpp -o parser

checkin:
	@$(CC) main.cpp -o parser
	git add $(SOURCES) Makefile
	git commit -am "automated commit"
	git push
	$(MAKE) clean

test:
	$(MAKE) clean
	@$(CC) test.cpp -o test
	@./test
	@rm -rf test
	@echo "Test success"
	$(MAKE) checkin
	@echo ""

clean:
	rm -rf *.o test parser

