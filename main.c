#include "calc_head.h"

/**
 * main - the main function of the scientific calulator
 * Return: void
 */
 
void main()
{
    char name[256], *prob, ch, hello[256] = "Hello ";
    prob = malloc(sizeof(char) * 128);
    printf("Please enter your full name: ");
    getstr(name);
    printf("\e[1;1H\e[2J");
    printstar();
    printstar();
    strcat(hello, name);
    printstr(hello);
    printstr("~- W.A.R.M _ W.E.L.C.O.M.E -~");
    printstar();
    description();
    
    do {
        do {
        printf("\nPlease enter the math problem: ");
        getstr(prob);
        } while(prob[0] == '\0');
        
        calcsep(prob);

    } while (prob);
    
    free(prob);
}
