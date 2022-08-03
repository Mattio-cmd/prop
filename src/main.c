//TODO: Please add suport for other languages (html, latex, idk what else)
#include <stdio.h>
#include <stdlib.h>

#include "func.h"

int main(int argc, char *argv[]) {

  if(argv[1] == NULL) {
    print_usage();
    return 0;
  }

//  if(argc > 2) {
//    printf("ERROR: Too many arguments, check -h for usage.\n");
//    return -1;
//  }

  if(strcmp_nois(argv[1], "full") == 0) def_create_enviorment();

  if(strcmp_nois(argv[1], "-l") == 0) {
    switch(*argv[2]) {

      case 'c':
        if(strcmp_nois(argv[3], "full") == 0) def_create_enviorment();
        if(strcmp_nois(argv[3], "M") == 0) create_makefile();
        if(strcmp_nois(argv[3], "skeleton") == 0) create_skeleton();
        break;

      case 'p':
        print_usage();
        break;

      default:
        if(argv[2] == NULL) printf("Language not suported!");
        printf("Language not suported yet.\n");

    }
  }

  if(strcmp_nois(argv[1], "-h") == 0) print_usage();

  if(strcmp_nois(argv[1], "-v") == 0) printf("%s\n", VERSION);

  return 0;
}
