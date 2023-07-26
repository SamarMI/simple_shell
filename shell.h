#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* for read/write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1
/* for convert_number() */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/**
 * struct liststr - singly linked list
 * @num: the number field in list.
 * @str: a string in field
 * @next: points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

extern char **environ;

/*string_functions1.c */
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

/*string_functions2.c */
int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);
/*string_functions3.c */
char * StrToLower(char *) ;
int _toLower(int);


/* realloc.c */
char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);

/*atoi.c*/
int _isalpha(int c);
int _atoi(char *s);
char *convert_number(long int, int, int);



/* lists_functions1.c */
list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int delete_node_at_index(list_t **, unsigned int);
void free_list(list_t **);

/* lists_functions2.c */
size_t list_len(const list_t *);
char **list_to_strings(list_t *);
size_t print_list(const list_t *);
list_t *node_starts_with(list_t *, char *, char);
ssize_t get_node_index(list_t *, list_t *);
/*main.c*/
int _shellExit(char *b);
int _shellInt(int a);

int check(char *buffer, int j, char **inpts);
char *path_cm(char *cm, char *full_command2);
void interactive(char **env);
int execute(char **inputs, char **env);
void freein(char *buffer, char **inpts, int j, int x);
int non_interactive(char **env);
void env_print(void);
void pre(void);

void set_env( char *var, char *value);
void unset_env(char *var);
void set2(char *var, char *value, unsigned int size);

char *_strtok2(void);
char *_strtok(char *str, const char *delim);
char *in[20];
#endif

