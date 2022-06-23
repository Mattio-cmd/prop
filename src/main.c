#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "func.h"

int main(int argc, char *argv[]) {

  if(argv[1] == NULL) {
    print_usage();
    return 0;
  }

  if(argc < 2) { // Maybe get rid of this
    printf("ERROR: Zero arguments provided, check -h for usage.\n");
    return -1;
  }

  if(argc > 2) {
    printf("ERROR: Too many arguments, check -h for usage.\n");
    return -1;
  }

  if(strcmp(argv[1], "-h") == 0) print_usage();

  if(strcmp(argv[1], "full") == 0) def_create_enviorment();

  if(strcmp(argv[1], "M") == 0) create_makefile();




  return 0;
}
