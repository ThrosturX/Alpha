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
NC=\033[0m # no color
info=\033[0;33m
green=\033[0;32m

lib=-L./UnitTest++/ -lUnitTest++

#Obsolete
#OPS= throstur11@ru.is
#comp_failed:= echo "Compilation failed!!" | mutt -s "Build failed -- Compilation Error!" $(OPS)

all:
	$(CC) $(SOURCES) $(TESTS) -o $(BLOC) $(lib)

install:
	@echo "\n$(info)Installing...$(NC)\n"
	@-mkdir release
	$(CC) $(SOURCES) $(EXE) -o $(BLOC)
	@echo "\n$(green) Success!! $(NC)\n"

deploy:
	@echo "\n$(info)Updating software...$(NC)\n"
	@git pull	
	@echo "\n$(info)Running tests...$(NC)\n"
	$(CC) $(SOURCES) $(TESTS) -o $(BLOC) $(lib) 
	@echo "\n$(info)Preparing build...$(NC)\n"
	@rm -rf $(TC)
	@echo "\n$(info)Deploying software...$(NC)\n"
	$(CC) $(SOURCES) $(EXE) -o $(BLOC)
	@rm -rf src/*.o 
	@echo "\n$(green)Software has been deployed.$(NC)\n"

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
	@$(CC) $(SOURCES) $(TESTS) -o $(BLOC) $(lib) 
	@$(BLOC)
	@rm -rf $(TC)	
	@echo ""

clean:
	rm -rf $(TC) build.log

