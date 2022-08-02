CC=cc
CFLAGS= -g -Wall
BINDIR=bin
BIN = $(BINDIR)/main
SRC=src
OBJ=obj
SRCS=$(wildcard $(SRC)/*.c)
OBJS=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))

INSTALLPATH=~/.local/bin/prop

all:$(BIN)

release: CC=clang
release: CFLAGS=-Wall -O2 -DNDEBUG
release: clean
release: $(BIN)

install: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(INSTALLPATH)
	#mkdir ~/.local/share/prop
	#cp ./src/prop/Makefile ~/.local/share/prop/

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -r $(BINDIR)/* $(OBJ)/*
