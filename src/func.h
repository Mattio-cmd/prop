int print_usage();

void def_create_enviorment();

int validate_arg(char *argv[]);

int strcmp_nois(const char *s1, const char *s2);

int create_makefile();

typedef struct Project {
  char name[20];
  char language[15];

} Project;

