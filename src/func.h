#define VERSION "Version 0.1"

//char *LOGO[] = {"_/_/_/    _/  _/_/    _/_/    _/_/_/",
//                "_/    _/  _/_/      _/    _/  _/    _/",
//                "_/    _/  _/        _/    _/  _/    _/",
//                "_/_/_/    _/          _/_/    _/_/_/",
//                "_/                            _/",
//                "_/                            _/",
//};

int print_usage();

void def_create_enviorment();

void create_skeleton();

int strcmp_nois(const char *str1, const char *str2);

void create_makefile();

void def_create_enviorment_py();

typedef struct Project {
  char name[20];
  char language[15];

} Project;
