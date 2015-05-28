#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
typedef unsigned int u_int32;
typedef unsigned long long u_int64;
#define newnum ((num *) malloc(sizeof(num)));
#define newvalue(tam) ((u_int32*) malloc(sizeof(u_int32*)*(tam)));
typedef struct{
	int size;
	u_int32 * value;
} num;

num * read_num();
void print_num(const num * v );
