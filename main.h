#ifndef MAIN_H
#define MAIN_H

#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>


#define R_SIZE 1024
#define W_SIZE 1024
#define BUFFER_D -1

#define CMD_N	0
#define C_R		1
#define CMD_D		2
#define C_CHA	3

#define CONVERT_LOW	1
#define CONVERT_UN	2

#define USE_G 0
#define USE_STRTOK 0

#define HI_FI	".simple_shell_history"
#define H_M	4096

extern char **environ;


/**
 * struct list - Singly linked
 * @numb: The number
 * @uu: A string
 * @next: Points
 */
typedef struct list
{
	int numb;
	char *uu;
	struct list *next;
} ll_t;
/**
 * struct ff - Struct for some purpose
 * @arg: Argument
 * @argv: Argument vector
 * @p: Pointer
 * @argc: Argument count
 * @co: Counter
 * @_number_err: Error number
 * @l_f: Flag
 * @newname: New name
 * @envnow: Current environment
 * @h: History
 * @a: Alias
 * @environ: Environment
 * @r_env_ch: Environment change flag
 * @str: String
 * @c_b: Buffer
 * @c_b_t: Buffer type
 * @rf: File descriptor
 * @h_count: History count
 */
typedef struct ff
{
	char *arg;
	char **argv;
	char *p;
	int argc;
	unsigned int co;
	int _number_err;
	int l_f;
	char *newname;
	ll_t *envnow;
	ll_t *h;
	ll_t *a;
	char **environ;
	int r_env_ch;
	int str;

	char **c_b;
	int c_b_t;
	int rf;
	int h_count;
} ff_t;

#define INF_IN \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 * struct bui - Struct for some purpose
 * @ty: Type
 * @func: Function pointer
 */
typedef struct bui
{
	char *ty;
	int (*func)(ff_t *);
} bb_table;





char *_chme(char *, char);
char **split(char *, char *);
char **split1(char *, char);
char *_note(char *, char, unsigned int);
void rfree_me(char **);
void *_realloc_me(void *, unsigned int, unsigned int);
int loophsh(char **);
void _aputs_me(char *);
int _aputchar_me(char);
int hs_me(ff_t *, char **);
int fi_bui_me(ff_t *);
int ren_his(ff_t *ff);
ll_t *add_x(ll_t **, const char *, int);
ll_t *a_n_end(ll_t **, const char *, int);
size_t print_l_s(const ll_t *);
int delete_n(ll_t **, unsigned int);
void free_l(ll_t **);
size_t l_l(const ll_t *);
char **l_t_s(ll_t *);
size_t print_l(const ll_t *);
void chec_cha_me(ff_t *, char *, size_t *, size_t, size_t);
int repl_al_me(ff_t *);
int repl_vars_me(ff_t *);
void fo_cmd_me(ff_t *);
int iscmdme(ff_t *, char *);
char *dupchars_me(char *, int, int);
int _putdd_me(char c, int dd);
int _putsdd_me(char *ptr, int dd);
int _len(char *);
void fi_cmd_me(ff_t *);
int _date(ff_t *);
int _alias_me(ff_t *);
ssize_t _input_me(ff_t *);
int _getline_me(ff_t *, char **, size_t *);
void _Handler(int);
void cl_in_me(ff_t *);
void st_in_me(ff_t *, char **);
void fr_in_me(ff_t *, int);
char *_genv_me(ff_t *, const char *);
int _env_me(ff_t *);
int _mysetenv_me(ff_t *);
int _myunsetenv_me(ff_t *);
int p_env_l(ff_t *);
int read_his(ff_t *ff);
int b_h_l(ff_t *ff, char *buf, int linec);
int _comp(char *, char *);
char *_with(const char *, const char *);
char *findpathme(ff_t *, char *, char *);
void print_many_characters(char *);
int _putchar(char);
char *_copyn(char *, char *, int);
char *_concatn(char *, char *, int);
int repl_stri_me(char **, char *);
char *_concat(char *, char *);
char *_copy(char *, char *);
char *_dupl(const char *);
int buffer_free_me(void **);
int reactive(ff_t *);
int is_del(char, char *);
int is_alpha_me(int);
int atoi_me(char *);
int _my_erratoi(char *);
void _error_print_me(ff_t *, char *);
int print_digit_me(int, int);
char *_convert(long int, int, int);
void _comment_me(char *);
int _exit_me(ff_t *);
int _cd_me(ff_t *);
int _help_me(ff_t *);
char **g_envir_m(ff_t *);
int _unsetenvnew_me(ff_t *, char *);
int _senv_me(ff_t *, char *, char *);
char *g_h_f(ff_t *ff);
ll_t *node_s(ll_t *, char *, char);
ssize_t _node_i(ll_t *, ll_t *);
int is_ch_me(ff_t *, char *, size_t *);
int w_his(ff_t *ff);
int p_a(ll_t *n);
int s_alias_me(ff_t *ff, char *s);
ssize_t r_buffer(ff_t *ff, char *b, size_t *j);
ssize_t i_buffer(ff_t *ff, char **buffer, size_t *l);
int u_alias_me(ff_t *ff, char *s);


#endif
