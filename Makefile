CC = cc
CFLAGS = -g -Wall

SRC = src
OBJ = obj
BINDIR = bin
INSTALLPATH = $(HOME)/.local/bin

SRCS = $(wildcard $(SRC)/*.c)
OBJS = $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))
BIN = $(BINDIR)/prop

# default target
all: $(BIN)

release: CC = clang
release: CFLAGS = -Wall -O2 -DNDEBUG
release: clean
release: $(BIN)

install: $(BIN)
	@mkdir -p $(INSTALLPATH)
	@cp $(BIN) $(INSTALLPATH)/prop
	@strip $(INSTALLPATH)/prop
	@echo "Installed to $(INSTALLPATH)/prop"

$(OBJ)/%.o: $(SRC)/%.c
	@mkdir -p $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN): $(OBJS)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $(OBJS) -o $@

clean:
	rm -rf $(BINDIR)/* $(OBJ)/*

.PHONY: all release install clean
