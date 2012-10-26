CC=g++
CFLAGS=
LDFLAGS=
SOURCES=main.cpp tictactoe.h tictactoe.cpp


all:
	g++ $(SOURCES) -o test

checkin:
	g++ $(SOURCES) -o test
	git add $(SOURCES)
	git commit -am "automated commit"
	git push

clean:
	rm -rf *o test
