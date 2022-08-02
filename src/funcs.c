#include <stdlib.h>
#include <stdio.h>


int print_usage()
{
  printf("Usage:\n\tprop full\nCreates a Makefile and a project skeleton\n\n\tprop Makefile\nJust creates a decent Makefile\n\n\tprop skeleton\nJust creates the project subdirectory structure/skeleton\n\n");
  printf("Available flags:\n\t-h\tPrints this text\n\t-v\tPrints the current version\n");
  return 0;
}

void def_create_enviorment()
{ // This works // TODO: Improve this
  system("cp ~/.local/share/prop/Makefile .; mkdir bin obj src; touch ./src/main.c ./src/funcs.c ./src/funcs.h");
}

void create_makefile()
{
  system("cp ~/.local/share/prop/Makefile .");
}

int strcmp_nois(const char *a, const char *b)
{
    while (*a && *a == *b) {
      ++a;
      ++b;
    }

    return (int)(unsigned char)(*a) - (int)(unsigned char)(*b);
}
