#include <stdlib.h>
#include <stdio.h>
#include <string.h>



int print_usage() {
  printf("Usage:\n\tprop full\nCreates a Makefile and a project skeleton\n\n\tprop Makefile\nJust creates a decent Makefile\n\n\tprop skeleton\nJust creates the project subdirectory structure/skeleton\n\n");
  printf("Available flags:\n\t-h\tPrints this text\n\t-v\tPrints the current version\n");
  return 0;
}

int def_create_enviorment() { // This works // TODO: Improve this
  system("cp ~/.local/share/prop/Makefile .; mkdir bin obj src; touch ./src/main.c ./src/funcs.c ./src/funcs.h");

  return 0;
}

int create_makefile() {
  system("cp ~/.local/share/prop/Makefile .");

  return 0;
}

