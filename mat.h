#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 4
#define MAXSIZE 100

typedef double mat[SIZE][SIZE];

/*-------------------------------------------mat.c declarations----------------------------------------------------*/
void read_mat(mat*,double[],int);
void print_mat(mat*);
void add_mat(mat*,mat*,mat*);
void sub_mat(mat*,mat*,mat*);
void mul_mat(mat*,mat*,mat*);
void mul_scalar(mat*,double,mat*);
void trans_mat(mat*,mat*);

/*-------------------------------------------add_func.c declarations----------------------------------------------------*/
char *get_word();
int find_comma();
int check_rest();
void zero_arr(double arr[]);
double *get_num();

