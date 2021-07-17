#include "calc_head.h"

/**
 * farewell - a function saying goodbye
 * Return: void
 */
 
void farewell()
{
    printstar();
    printstr(" :( Quiting ... ");
    printstar();
}

/**
 * description -  a function to discription about the program
 * Return: void
 */
 
void description()
{
    printstr("This is a simple scientific calculator which solves some");
    printstr("mathematical equations and functions you typed.");
    printstr("");
    printstr("Allowed operators are: ('+', '-', '*', '/', '%', '^', 'e',");
    printstr(" 'E', '!', 'sqrt', 'log', 'ln', 'e', 'sin', 'cos', 'tan', ");
    printstr(" 'asin', 'acos', 'atan', sinh, cosh, tanh).               ");
    printstr(" ");
    printstar();
    printstr("- RADIANS only -");
    printstar();
    printstar();
    printstr("NOTE: example \"8+(2*17)-5\" is allowed and will return 37");
    printstr(" based on BOMPDMAS rule. e2 = e*2 or 2(2+3) = 2*(2+3)");
    printstr("");
    printstr("In Details: B-brackets '()', O-order, M-modulation '%',");
    printstr(" P-power '^', D-division '/', M-multiplication '*',");
    printstr(" A-addition '+', S-subtraction '-'.                 ");
    printstar();
    printstr("It can be downloaded from my github page:                 ");
    printstr("                         https://github.io/sertsev/scicalc");
    printstr("Designed By: Sertse => https://github.io/sertsev          ");
    printstar();
    
}

/**
 * helper - a function to display a help message
 * Return: void
 */ 
 
void helper()
{
    printf("\e[1;1H\e[2J");
    printstar();
    printstar();
    printstr("- H.E.L.P -");
    printstar();
    description();
    printstr("Commands: help, quit                                      ");
    printstr("HELP/help/Help - displays the help notes                  ");
    printstr("QUIT/quitQuit -  will quit the program                    ");
    printstr("");
    printstr("Examples: (sqrt(59)*ln(8))/(cos(75)+sin(10)) = 42.2854600 ");
    printstr("sqrt(59)*ln(8)/cos(75)+sin(10)+e^(1+1)+2e2 =");
    printstr("sqrt59*ln8/cos75+sin10+e^2+2e2 =");
    printstr(" 35.046583");
    printstar();
    printstar();
}

/**
 * strleng - measures a length of a string
 * @s: a string location pointer
 * Return: returns length
 */ 
 
int strleng(char *s)
{
  int len = 0;

  while (s[len] != '\0')
    {
      len++;
    }

  return len;
}

/**
 * printstar - prints a star line
 * Return: void
 */ 
 
void printstar ()
{
  int i = 0;
  printf ("\n\t\t\t");

  while (i < 75)
    {
      printf ("*");
      i++;
    }
}

/**
 * printstr - a function to print a given string between a stars
 * @s: a string location pointer
 * Return: void
 */ 

void printstr (char *s)
{
  int len = strlen (s), spc, m = 0;

  printf ("\n\t\t\t***\t");

  spc = (60 - len) / 2;

  while (m < spc)
    {
      printf (" ");
      m++;
    }

  printf ("%s", s);

  while (m > 0)
    {
      printf (" ");
      m--;
    }

  printf ("\t***");
}

/**
 * getstr - reads a string from standard input 
 * @str: a string reserved location pointer
 * Return: void
 */ 
 
void getstr (char *str)
{
  int i = 0;

  do
    {
      str[i] = getchar();
      
      if (str[i] == '\n')
	{
	  str[i] = '\0';
	  break;
	}
	
      i++;
      
    if (i > 250)
    {
        str = realloc(str, sizeof(char) * (i + 10));
    }
    }
  while (str[i - 1] != '\0');
}

/**
 * err - a function to display an error message when their is one
 * @c: the wrong character entered
 * Return: void
 */ 
 
void err(char c)
{
    char er[2];
    int h = 0;
    
    er[h++] = c;
    er[h] = '\0';
    
    printstar();
    printstr("Wrong value!");
    printstr(er);
    printstar();
    printstr("|-> REMEMBER <-|");
    printstr("Allowed operators are: ('+', '-', '*', '/', '%', '^', 'e',");
    printstr(" 'E', '!', 'sqrt', 'log', 'ln', 'e', 'sin', 'cos', 'tan', ");
    printstr(" 'asin', 'acos', 'atan', sinh, cosh, tanh).               ");
    printstr(" Brackets are recommended for accurate answers.           ");
    printstar();
}

/**
 * remv - is a function to remove a number from a integer array
 * 
 * @iarr: a string array
 * @i: an index of the number to remove
 * @len: length of the array
 * 
 * Return: returns nothing
 */

void remv(double *iarr, int i, int len)
{
    int k;
    
   // printf(" %d %d ", k, len);
    
    for (k = i + 1; k < len; k++)
    {
        iarr[k] = iarr[k+1];
    }
    
   // printf(" %d %d ", k, len);
}

/**
 * rems - is a function to remove a caharcter from a string array
 * 
 * @str: a string array
 * @i: an index of the charcter to remove
 * 
 * Return: returns nothing
 */

void rems(char *str, int i)
{
    for (; str[i] != '\0'; i++)
    {
        str[i] = str[i+1];
    }
}

/**
 * tonum - a function to converts a string into an integer
 * @prob: a string pointer
 * @i: an integer value the indicator of the integer in the string
 * @iarr: a double integer array pointer
 * @k: an integer array location indicator
 * 
 * Returns: returns an integer
 */
 
 int tonum(char *prob, int i, double *iarr, int k)
 {
     int n = 0;
     char cp[256];
     double num;
     
        do {
            cp[n] = prob[i];
            n++;
            i++;
            do {
                if (prob[i] == ' ')
                {
                    i++;
                }
            } while (prob[i] == ' ');
        } while (isdigit(prob[i]) || prob[i] == '.');
        
        cp[n] = '\0';
        iarr[k] = atof(cp);
        
    return (i);
 }
