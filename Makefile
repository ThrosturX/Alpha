.PHONY: build 
CC=g++
CFLAGS=
LDFLAGS=
BLOC= release/TicTacToe
TC = $(BLOC) src/*.o
SOURCES=src/play.cpp
TESTS=test/playTest.cpp
NAME=BoardGame
NC=\033[0m # no color
info=\033[0;33m
green=\033[0;32m

lib=-L./UnitTest++/ -lUnitTest++

OPS= throstur11@ru.is
comp_failed:= echo "Compilation failed!!" | mutt -s "Build failed -- Compilation Error!" $(OPS)

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
	@rm -rf $(TC)
	@$(CC) $(SOURCES) $(TESTS) -o $(BLOC) $(lib) 
	@-$(BLOC)
	@rm -rf $(TC)
	@echo ""

test-build:
	@echo "\nBuilding test build...\n"
	rm -rf $(TC)
	@$(CC) $(SOURCES) $(TESTS) -o $(BLOC) $(lib) || $(call comp_failed) 
	@$(BLOC)
	@rm -rf $(TC)	

clean:
	rm -rf $(TC)

