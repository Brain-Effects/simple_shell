#ifndef SHELL_H
#define  SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#pragma once
/**
 * struct alias - A structure to store an alias
 * @name: The name of the alias
 * @value: The value of the alias
 * @next: A pointer to the next alias
 */
typedef struct alias
{
	char *name;
	char *value;
	struct alias *next;
} alias_t;

void copy_env_except(char **env, char **newenv, const char *name, int len);
int count_env(char **env);
int is_invalid_argument(const char *name);
char *format_variable(const char *name, const char *value);
void write_error(const char *msg);
int is_invalid_argument(const char *name);
void execute_command(char **cmd, char **env);
void exit_shell(char *buf);
void handle_getline_error(char *buf);
void prompt_user(void);
int update_oldpwd(char *pwd, char *temp);
int cd_to_directory(char *directory);
int cd_to_oldpwd(void);
int cd_to_home(void);
int cd(char *directory);
int print_alias(char *name, alias_t *head);
int create_alias(char *name, char *value, alias_t **head);
int update_alias_value(alias_t *node, char *value);
alias_t *find_alias(char *name, alias_t *head);
int create_or_update_alias(char *name, char *value, alias_t **head, char **arg);
int print_alias_list(alias_t *head);
int process_alias_args(char **args, alias_t **head);
int alias(char **args, alias_t **head);
char *search_path(char *cmd);
void prompt(void);
int read_cmd(char **cmd, size_t *cmd_len);
void tokenize_cmd(char *cmd, char **args);
int handle_builtin(char **args);
void execute_cmd(char **args);
int main(void);
void print_prompt(void);
extern char *env[];
void print_env(char *env[]);
void tok_str(char *str, char *tokens[]);
void add_path(char *cmd[]);
int my_exit(char **env);
extern char **environ;
extern char *cmd[20];
void tok_str(char *str, char *arr[]);
int setenv(const char *name, const char *value, int overwrite);
int unsetenv(const char *name);
char **handle_commands(char *str);
char **handle_operators(char *str);
int alias(char **args, alias_t **head);
char *replace_var(char *str, int status, int pid);
int handle_comment(char *line, int *index);
int execute_file(char *filename);
int main_execute(int argc, char *argv[]);
char *itoa(int value, char *str, int base);
char *itoa_buffer(int num, char *buffer, int base);
char *realloc_str(char *new_str, int len);
void shift_chars(char *new_str, int j, int len);
void copy_value(char *new_str, char *temp, int i);

#endif
