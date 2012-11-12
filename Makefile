.PHONY:test
CC=g++
SOURCES=UnitTestTest.cpp

all:
	$(CC) $(SOURCES)

test:
	$(CC) $(SOURCES) -o test
	./test
	@echo "Success"


clean:
	rm -rf *.o test

