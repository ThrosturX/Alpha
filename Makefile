.PHONY: build deploy
CC=g++
CFLAGS=
LDFLAGS=
BLOC= release/TicTacToe
TC = $(BLOC) src/*.o 
SOURCES=src/TicTacToe.cpp src/Play.cpp
EXE=src/game.cpp
TESTS=test/tests.cpp
NAME=BoardGame
CMP=test/e2e/test.sh
TBASE=test/e2e/base
TRES=test/e2e/res
NC=\033[0m # no color
info=\033[0;33m
green=\033[0;32m
blue=\033[0;34m
col=\033[0;35m

lib=-L./UnitTest++/ -lUnitTest++

all:
	$(CC) $(SOURCES) $(TESTS) -o $(BLOC) $(lib)

install:
	@echo "\n$(info)Installing...$(NC)\n"
	@-mkdir release
	$(CC) $(SOURCES) $(EXE) -o $(BLOC)
	@echo "\n$(green)Success!! $(NC)\n"

deploy:
	@echo "\n$(info)Updating software...$(col)\n"
	@git pull	
	@-mkdir release
	@echo "\n$(info)Running tests...$(col)\n"
	$(CC) $(SOURCES) $(TESTS) -o $(BLOC) $(lib) 
	@-$(BLOC)
	@cppcheck --enable=all src
	@echo "\n$(info)Preparing build...$(NC)\n"
	@rm -rf $(TC)
	@echo "\n$(info)Deploying software...$(NC)\n"
	$(CC) $(SOURCES) $(EXE) -o $(BLOC)
	@rm -rf src/*.o 
	@echo "\n$(blue)Running End-To-End tests...$(col)\n"
	@$(CMP) 
	@echo "\n$(blue)All End-To-End tests passed!$(NC)\n"
	@echo "\n$(green)Software has been deployed.$(NC)\n"
	
checkin:
	@$(CC) $(SOURCES) $(TESTS) -o $(BLOC) $(lib)
	@$(BLOC)
	git add $(SOURCES) $(TESTS) Makefile
	git commit -am "$(MAKECMDGOALS)" 
	git push
	$(MAKE) clean

build:
	@echo "\n$(info)Building...$(NC)\n"
	@rm -rf $(TC)
	@$(CC) $(SOURCES) $(TESTS) -o $(BLOC) $(lib) 
	@-$(BLOC)
	@rm -rf $(TC) $(BLOC)
	@echo ""

test-build:
	@echo "\nBuilding test build...\n"
	rm -rf $(TC)
	@$(CC) $(SOURCES) $(TESTS) -o $(BLOC) $(lib) 
	@$(BLOC)
	@cppcheck --enable=all src
	@$(MAKE) e2e
	@rm -rf $(TC)	
	@echo ""

e2e:
	@echo "\nRunning End-To-End tests...\n"
	$(CMP) 

clean:
	rm -rf $(TC) build.log

