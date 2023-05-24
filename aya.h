#ifndef AYA_H
#define AYA_H

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>
#include <dirent.h>
#include <limits.h>

void free_str(char **strings, int n);
int write_string(char *str);
void get_cmd(void);
void command_devide(char *text);
int exec(char **command);
char *get_path(char *command);
char **pathform(char *command);
int path_execute(char **command);
int path_exists(char *command);
void _prints(char **strings);
char *erase_initials(char *str, int n);
char *concatenate(char *s1, char *s2);
int _strlen(char *str);
int compare_chars(char *s1, char *s2, int chars_compared);
void ctrl(int sig);
int _putchar(char c);
char *_strcpy(char *dest, char *src);
int count_words(char *text);
void prompt(void);

char *file_name;
extern char **environ;
#endif /* AYA_H */
