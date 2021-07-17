
/**
 * CALC_HEAD_H - a header file containing all the function declaration,
 * the constants and the standard libraries.
 */ 
 
#ifndef CALC_HEAD_H
#define CALC_HEAD_H

/**
 * defining constants for pi and e constant 
 */
 
#define PI 3.14159265359
#define e 2.71828182846

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void printstar();
void printstr(char *s);
int add(int a, int b);
int strleng(char *s);
int* strconv(char *c);
void calcsep(char *prob);
int calcbra(char *prob, double *iarr, int i, int k);
void getstr(char *str);
double bodmas(char *opr, double *iarr, int k);
void rems(char *str, int i);
void remv(double *iarr, int i, int k);
double fact(int i);
void err(char c);
int tonum(char *prob, int i, double *iarr, int k);
void helper();
void description();
void farewell();


#endif