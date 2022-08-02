int print_usage();

int def_create_enviorment();

int validate_arg(char *argv[]);

int strcmp_nois(const char *a, const char *b);

int create_makefile();

typedef struct Project {
  char name[20];
  char language[15];

} Project;

