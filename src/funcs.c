#include <stdlib.h>
#include <stdio.h>


void print_usage()
{
  printf("Usage:\n\tprop full\nCreates a Makefile and a project skeleton\n\n\tprop M\nJust creates a decent Makefile\n\n\tprop skeleton\nJust creates the project subdirectory structure/skeleton\n\n");
  printf("Available flags:\n\t-h\tPrints this text\n\t-v\tPrints the current version\n");
}


void create_makefile()
{
   FILE *fp;

   fp = fopen ("Makefile", "w+");
   fprintf(fp, "CC=cc\nCFLAGS= -g -Wall\nBINDIR=bin\nBIN = $(BINDIR)/main\nSRC=src\nOBJ=obj\nSRCS=$(wildcard $(SRC)/*.c)\nOBJS=$(patsubst $(SRC)/%%.c, $(OBJ)/\%%.o, $(SRCS))\n\nall:$(BIN)\nrelease: CC=clang\nrelease: CFLAGS=-Wall -O2 -DNDEBUG\nrelease: clean\nrelease: $(BIN)\n\n$(BIN): $(OBJS)\n\t$(CC) $(CFLAGS) $(OBJS) -o $@\n\n$(OBJ)/%%.o: $(SRC)/%%.c\n\t$(CC) $(CFLAGS) -c $< -o $@\nclean:\n\t$(RM) -r $(BINDIR)/* $(OBJ)/*");

   fclose(fp);

 // system("cp ~/.local/share/prop/Makefile .");
}

void def_create_enviorment()
{ // This works // TODO: Improve this
  create_makefile();
  system("mkdir bin obj src; touch ./src/main.c ./src/funcs.c ./src/funcs.h");
}

int strcmp_nois(const char *s1, const char *s2)
{
    while (*s1 && *s1 == *s2) {
      ++s1;
      ++s2;
    }

    return (int)(unsigned char)(*s1) - (int)(unsigned char)(*s2);
}
