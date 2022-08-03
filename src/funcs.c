#include <stdlib.h>
#include <stdio.h>

void print_usage()
{
  printf("Usage:  prop [-l language] [options...]\n\tprop full\n\n");
  printf("General options:\n\t-l language\tSelects one of the languages(C, python, haskell)\n\t-h\t\tPrints this text\n\t-v\t\tPrints the current version\n");
  printf("Specific options:\n\t");
}

// C
void create_makefile()
{
   FILE *fp;

   fp = fopen ("Makefile", "w+");
   fprintf(fp, "CC=cc\nCFLAGS= -g -Wall\nBINDIR=bin\nBIN = $(BINDIR)/main\nSRC=src\nOBJ=obj\nSRCS=$(wildcard $(SRC)/*.c)\nOBJS=$(patsubst $(SRC)/%%.c, $(OBJ)/\%%.o, $(SRCS))\n\nall:$(BIN)\nrelease: CC=clang\nrelease: CFLAGS=-Wall -O2 -DNDEBUG\nrelease: clean\nrelease: $(BIN)\n\n$(BIN): $(OBJS)\n\t$(CC) $(CFLAGS) $(OBJS) -o $@\n\n$(OBJ)/%%.o: $(SRC)/%%.c\n\t$(CC) $(CFLAGS) -c $< -o $@\nclean:\n\t$(RM) -r $(BINDIR)/* $(OBJ)/*");

   fclose(fp);
}

void def_create_enviorment()
{ // This works // TODO: Improve this
  create_makefile();
  system("mkdir bin obj src; touch ./src/main.c ./src/funcs.c ./src/funcs.h");
}

void create_skeleton()
{
  system("mkdir bin obj src; touch ./src/main.c ./src/funcs.c ./src/funcs.h");
}

// PYTHON
void def_create_enviorment_py() {
  // idk what to do here
}

// CUSTOM FUNCTIONS
int strcmp_nois(const char *str1, const char *str2) //stolen from stakc overfow
{
    while (*str1 && *str1 == *str2) {
      ++str1;
      ++str2;
    }

    return (int)(unsigned char)(*str1) - (int)(unsigned char)(*str2);
}
