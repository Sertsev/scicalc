#include "calc_head.h"

/**
 * calcsep - a function to separate the operators and the integers
 * 
 * @prob: the string pointer of the math problem the user entered
 * Return: returns nothing
 */

void calcsep(char *prob)
{
    char cp[256], *opr;
    int i = 0, n, k = 0, j = 0, h = 0;
    double *iarr, result;
    iarr = malloc(sizeof(double)*(strleng(prob)/2));
    opr = malloc(sizeof(char)*strleng(prob)/2);
    
    while (prob[i] != '\0')
    {
        if (prob[i] == ' ') /* a statement removing spaces */
        {
            i++;
        }
        else if (prob[i] == 'q' || prob[i] == 'Q') /* a statement recognizing help and ready to quit */
        {
            i++;
            if ((prob[i] == 'u' || prob[i] == 'U') && (prob[++i] == 'i' || prob[++i] == 'I') && (prob[++i] == 't' || prob[++i] == 'T'))
            {
                printf("\e[1;1H\e[2J");
                atexit(farewell);
                free(opr);
                free(iarr);
                exit(1);
            }
        }
        else if (prob[i] == 'h' || prob[i] == 'H') /* a statement recognizing help and ready to give */
        {
            i++;
            if ((prob[i] == 'e' || prob[i] == 'E') && (prob[++i] == 'l' || prob[++i] == 'L') && (prob[++i] == 'p' || prob[++i] == 'P'))
            {
                h = 1;
                helper();
                free(iarr);
                free(opr);
                break;
            }
        }
        else if (prob[i]  == '(')
        {
            if(isdigit(prob[i - 1]))
            {
                opr[j] = '*';
                j++;
            }
            
            i = calcbra(prob, iarr, i, k);
            k++;
            continue;
        }
        else if (prob[i]  == 'P') /* a statement finding PI constant and saving for calculation */
        {
            i++;
            if (prob[i] == 'I')
            {
                if (isdigit(prob[i - 2]))
                {
                    opr[j] = '*';
                    j++;
                }
                
                iarr[k] = PI;
                k++;
                i++;
                
                if (isdigit(prob[i]))
                {
                    opr[j] = '*';
                    j++;
                }
            }
        }
        else if (prob[i]  == 'e') /* a statement finding e constant and saving for calculation */
        {
            if (isdigit(prob[i - 1]))
            {
                opr[j] = '*';
                j++;
            }
            
            iarr[k] = e;
            k++;
            i++;
            
            if (isdigit(prob[i]))
            {
                opr[j] = '*';
                j++;
            }
            
        }
        else if (prob[i]  == 'L' || prob[i] == 'l')
        {
            i++;
            if (prob[i]  == 'n' || prob[i] == 'N')
            {
                i++;
                if (prob[i] == ' ')
                {
                    do {
                        i++;
                    } while (prob[i] == ' ');
                }
                
                if (isdigit(prob[i]))
                {
                    i = tonum(prob, i, iarr, k);
                    iarr[k] = log(iarr[k]);
                    k++;
                }
                else if (prob[i] == '(')
                {
                    
                    i = calcbra(prob, iarr, i, k);
                    iarr[k] = log(iarr[k]);
                    k++;
                }
                else 
                {
                    err(prob[i]);
                    free(iarr);
                    free(opr);
                    break;
                }
            } 
            else if (prob[i]  == 'o' || prob[i] == 'O')
            {
                i++;
                if (prob[i]  == 'g' || prob[i] == 'G')
                {
                    i++;
                    if (prob[i] == ' ')
                    {
                        do {
                            i++;
                        } while (prob[i] == ' ');
                    }
                    
                    if (isdigit(prob[i]))
                    {
                        i = tonum(prob, i, iarr, k);
                        iarr[k] = log10(iarr[k]);
                        k++;
                    }
                    else if (prob[i] == '(')
                    {
                        
                        i = calcbra(prob, iarr, i, k);
                        iarr[k] = log(iarr[k]);
                        k++;
                    }
                    else 
                    {
                        err(prob[i]);
                        free(iarr);
                        free(opr);
                        break;
                    }
                }
            }
            else 
                    {
                        err(prob[i]);
                        free(iarr);
                        free(opr);
                        break;
                    }
            
        } 
        else if (prob[i]  == 's' || prob[i] == 'S')
        {
           i++;
                if ((prob[i]  == 'q' || prob[i] == 'Q') && (prob[++i]  == 'r' || prob[++i] == 'R') && (prob[++i]  == 't' || prob[++i] == 'T'))
                {
                    i++;
                    if (prob[i] == ' ')
                    {
                        do {
                            i++;
                        } while (prob[i] == ' ');
                    }
                    
                    if (isdigit(prob[i]))
                    {
                        i = tonum(prob, i, iarr, k);
                        iarr[k] = sqrt(iarr[k]);
                        k++;
                    }
                    else if (prob[i] == '(')
                    {
                        
                        i = calcbra(prob, iarr, i, k);
                        iarr[k] = sqrt(iarr[k]);
                        k++;
                    }
                    else 
                    {
                        err(prob[i]);
                        free(iarr);
                        free(opr);
                        break;
                    }
                }
                else if ((prob[i]  == 'i' || prob[i] == 'I') && (prob[++i]  == 'n' || prob[++i] == 'N') && (prob[++i]  == 'h' || prob[++i] == 'H'))
                {
                    i++;
                    if (prob[i] == ' ')
                    {
                        do {
                            i++;
                        } while (prob[i] == ' ');
                    }
                    
                    if (isdigit(prob[i]))
                    {
                        i = tonum(prob, i, iarr, k);
                        iarr[k] = sinh(iarr[k]);
                        k++;
                    }
                    else if (prob[i] == '(')
                    {
                        
                        i = calcbra(prob, iarr, i, k);
                        iarr[k] = sinh(iarr[k]);
                        k++;
                    }
                    else 
                    {
                        err(prob[i]);
                        free(iarr);
                        free(opr);
                        break;
                    }
                }
                else if ((prob[i]  == 'i' || prob[i] == 'I') && (prob[++i]  == 'n' || prob[++i] == 'N'))
                {
                    i++;
                    if (prob[i] == ' ')
                    {
                        do {
                            i++;
                        } while (prob[i] == ' ');
                    }
                    
                    if (isdigit(prob[i]))
                    {
                        i = tonum(prob, i, iarr, k);
                        iarr[k] = sin(iarr[k]);
                        k++;
                    }
                    else if (prob[i] == '(')
                    {
                        
                        i = calcbra(prob, iarr, i, k);
                        iarr[k] = sin(iarr[k]);
                        k++;
                    }
                    else 
                    {
                        err(prob[i]);
                        free(iarr);
                        free(opr);
                        break;
                    }
                }
                else 
                    {
                        err(prob[i]);
                        free(iarr);
                        free(opr);
                        break;
                    }
        } 
        else if (prob[i]  == 'c' || prob[i] == 'C')
        {
            
            i++;
            if ((prob[i]  == 'o' || prob[i] == 'O') && (prob[++i]  == 's' || prob[++i] == 'S') && (prob[++i]  == 'h' || prob[++i] == 'H'))
                {
                    i++;
                    if (prob[i] == ' ')
                    {
                        do {
                            i++;
                        } while (prob[i] == ' ');
                    }
                    
                    if (isdigit(prob[i]))
                    {
                        i = tonum(prob, i, iarr, k);
                        iarr[k] = cosh(iarr[k]);
                        k++;
                    }
                    else if (prob[i] == '(')
                    {
                        
                        i = calcbra(prob, iarr, i, k);
                        iarr[k] = cosh(iarr[k]);
                        k++;
                    }
                    else 
                    {
                        err(prob[i]);
                        free(iarr);
                        free(opr);
                        break;
                    }
                }
            else if ((prob[i]  == 'o' || prob[i] == 'O') && (prob[++i]  == 's' || prob[++i] == 'S'))
                {
                    i++;
                    if (prob[i] == ' ')
                    {
                        do {
                            i++;
                        } while (prob[i] == ' ');
                    }
                    
                    if (isdigit(prob[i]))
                    {
                        i = tonum(prob, i, iarr, k);
                        iarr[k] = cos(iarr[k]);
                        k++;
                    }
                    else if (prob[i] == '(')
                    {
                        
                        i = calcbra(prob, iarr, i, k);
                        iarr[k] = cos(iarr[k]);
                        k++;
                    }
                    else 
                    {
                        err(prob[i]);
                        free(iarr);
                        free(opr);
                        break;
                    }
                }
                else 
                    {
                        err(prob[i]);
                        free(iarr);
                        free(opr);
                        break;
                    }
                
        }
        
        else if (prob[i]  == 't' || prob[i] == 'T')
        {
            i++;
            if ((prob[i]  == 'a' || prob[i] == 'A') && (prob[++i]  == 'n' || prob[++i] == 'N') && (prob[++i]  == 'h' || prob[++i] == 'H'))
                {
                    i++;
                    if (prob[i] == ' ')
                    {
                        do {
                            i++;
                        } while (prob[i] == ' ');
                    }
                    
                    if (isdigit(prob[i]))
                    {
                        i = tonum(prob, i, iarr, k);
                        iarr[k] = tanh(iarr[k]);
                        k++;
                    }
                    else if (prob[i] == '(')
                    {
                        
                        i = calcbra(prob, iarr, i, k);
                        iarr[k] = tanh(iarr[k]);
                        k++;
                    }
                    else 
                    {
                        err(prob[i]);
                        free(iarr);
                        free(opr);
                        break;
                    }
                }
            else if ((prob[i]  == 'a' || prob[i] == 'A') && (prob[++i]  == 'n' || prob[++i] == 'N'))
                {
                    i++;
                    if (prob[i] == ' ')
                    {
                        do {
                            i++;
                        } while (prob[i] == ' ');
                    }
                    
                    if (isdigit(prob[i]))
                    {
                        i = tonum(prob, i, iarr, k);
                        iarr[k] = tan(iarr[k]);
                        k++;
                    }
                    else if (prob[i] == '(')
                    {
                        
                        i = calcbra(prob, iarr, i, k);
                        iarr[k] = tan(iarr[k]);
                        k++;
                    }
                    else 
                    {
                        err(prob[i]);
                        free(iarr);
                        free(opr);
                        break;
                    }
                }
                else 
                    {
                        err(prob[i]);
                        free(iarr);
                        free(opr);
                        break;
                    }
        }
        
        else if (prob[i]  == 'a' || prob[i] == 'A')
        {
            i++;
                if ((prob[i]  == 's' || prob[i] == 'S') && (prob[++i]  == 'i' || prob[++i] == 'I') && (prob[++i]  == 'n' || prob[++i] == 'N'))
                {
                    i++;
                    if (prob[i] == ' ')
                    {
                        do {
                            i++;
                        } while (prob[i] == ' ');
                    }
                    
                    if (isdigit(prob[i]))
                    {
                        i = tonum(prob, i, iarr, k);
                        iarr[k] = asin(iarr[k]);
                        k++;
                    }
                    else if (prob[i] == '(')
                    {
                        
                        i = calcbra(prob, iarr, i, k);
                        iarr[k] = asin(iarr[k]);
                        k++;
                    }
                    else 
                    {
                        err(prob[i]);
                        free(iarr);
                        free(opr);
                        break;
                    }
                }
                else if ((prob[i]  == 'c' || prob[i] == 'C') && (prob[++i]  == 'o' || prob[++i] == 'O') && (prob[++i]  == 's' || prob[++i] == 'S'))
                {
                    i++;
                    if (prob[i] == ' ')
                    {
                        do {
                            i++;
                        } while (prob[i] == ' ');
                    }
                    
                    if (isdigit(prob[i]))
                    {
                        i = tonum(prob, i, iarr, k);
                        iarr[k] = acos(iarr[k]);
                        k++;
                    }
                    else if (prob[i] == '(')
                    {
                        
                        i = calcbra(prob, iarr, i, k);
                        iarr[k] = acos(iarr[k]);
                        k++;
                    }
                    else 
                    {
                        err(prob[i]);
                        free(iarr);
                        free(opr);
                        break;
                    }
                }
                else if ((prob[i]  == 't' || prob[i] == 'T') && (prob[++i]  == 'a' || prob[++i] == 'A') && (prob[++i]  == 'n' || prob[++i] == 'N'))
                {
                    i++;
                    if (prob[i] == ' ')
                    {
                        do {
                            i++;
                        } while (prob[i] == ' ');
                    }
                    
                    if (isdigit(prob[i]))
                    {
                        i = tonum(prob, i, iarr, k);
                        iarr[k] = atan(iarr[k]);
                        k++;
                    }
                    else if (prob[i] == '(')
                    {
                        
                        i = calcbra(prob, iarr, i, k);
                        iarr[k] = atan(iarr[k]);
                        k++;
                    }
                    else 
                    {
                        err(prob[i]);
                        free(iarr);
                        free(opr);
                        break;
                    }
                }
                else 
                    {
                        err(prob[i]);
                        free(iarr);
                        free(opr);
                        break;
                    }
        }
        
        else if (isdigit(prob[i])) 
        {
        
        i = tonum(prob, i, iarr, k);

        k++;
        
        }
        else if (prob[i] == '+' ||  prob[i] == '*' || prob[i] == '-' || prob[i] == '/' || prob[i] == '%' || prob[i] == '^' || prob[i] == '!' || prob[i] == 'E')
        {
            opr[j] = prob[i];
            j++;
            i++;
            if (prob[i] == '+' ||  prob[i] == '*' || prob[i] == '-' || prob[i] == '/' || prob[i] == '%' || prob[i] == '^' || prob[i] == '!' || prob[i] == 'E')
            {
                h = 1;
                err(prob[i]);
                free(iarr);
                free(opr);
                break;
            }
        }
        else
        {
            h = 1;
            err(prob[i]);
            free(iarr);
            free(opr);
            break;
        }
        
    }
    
   
    if (h == 0)
    {
        result = bodmas(opr, iarr, k);
        printf("\t = %f", result);
        free(iarr);
    }
}

/**
 * calcbra - a function to calculate equations on the bracket
 * 
 * @prob: a string pointer
 * @iarr: the double array pointer
 * @i: the string array indicator intiger value
 * @k: the double array indicator integer value
 * 
 * Return: returns an integer value of the string indicator
 */

int calcbra(char *prob, double *iarr, int i, int k)
{
    char cp[256], *opr;
    int n, m = 0, j = 0, h = 0;
    double *barr, result;
    barr = malloc(sizeof(double)*(1024));
    opr = malloc(sizeof(char)*(768));
    
    barr[0] = 1;
    i++;
    
    while (prob[i] != ')')
    {
        
        if (prob[i] == ' ')
        {
            i++;
        }
        else if (prob[i]  == '(')
        {
            if(isdigit(prob[i - 1]))
            {
                opr[j] = '*';
                j++;
            }
            
            i = calcbra(prob, barr, i, m);
            m++;
        }
        else if (prob[i]  == 'P') /* a statement finding PI constant and saving for calculation */
        {
            i++;
            if (prob[i] == 'I')
            {
                if (isdigit(prob[i - 2]))
                {
                    opr[j] = '*';
                    j++;
                }
                
                barr[m] = PI;
                m++;
                i++;
                
                if (isdigit(prob[i]))
                {
                    opr[j] = '*';
                    j++;
                }
            }
        }
        else if (prob[i]  == 'e')
        {
            if (isdigit(prob[i - 1]))
            {
                opr[j] = '*';
                j++;
            }
            
            barr[m] = e;
            m++;
            i++;
            
            if (isdigit(prob[i]))
            {
                opr[j] = '*';
                j++;
            }
            
        }
        else if (prob[i]  == 'L' || prob[i] == 'l')
        {
            i++;
            if (prob[i]  == 'n' || prob[i] == 'N')
            {
                i++;
                if (prob[i] == ' ')
                {
                    do {
                        i++;
                    } while (prob[i] == ' ');
                }
                
                if (isdigit(prob[i]))
                {
                    i = tonum(prob, i, barr, m);
                    barr[m] = log(barr[m]);
                    m++;
                }
                else if (prob[i] == '(')
                {
                    
                    i = calcbra(prob, barr, i, m);
                    barr[m] = log(barr[m]);
                    m++;
                }
            } 
            else if (prob[i]  == 'o' || prob[i] == 'O')
            {
                i++;
                if (prob[i]  == 'g' || prob[i] == 'G')
                {
                    i++;
                    if (prob[i] == ' ')
                    {
                        do {
                            i++;
                        } while (prob[i] == ' ');
                    }
                    
                    if (isdigit(prob[i]))
                    {
                        i = tonum(prob, i, barr, m);
                        barr[m] = log10(barr[m]);
                        m++;
                    }
                    else if (prob[i] == '(')
                    {
                        
                        i = calcbra(prob, barr, i, m);
                        barr[m] = log(barr[m]);
                        m++;
                    }
                }
            }
            
        } 
        else if (prob[i]  == 's' || prob[i] == 'S')
        {
           i++;
                if ((prob[i]  == 'q' || prob[i] == 'Q') && (prob[++i]  == 'r' || prob[++i] == 'R') && (prob[++i]  == 't' || prob[++i] == 'T'))
                {
                    i++;
                    if (prob[i] == ' ')
                    {
                        do {
                            i++;
                        } while (prob[i] == ' ');
                    }
                    
                    if (isdigit(prob[i]))
                    {
                        i = tonum(prob, i, barr, m);
                        barr[m] = sqrt(barr[m]);
                        m++;
                    }
                    else if (prob[i] == '(')
                    {
                        
                        i = calcbra(prob, barr, i, m);
                        barr[m] = sqrt(barr[m]);
                        m++;
                    }
                }
                else if ((prob[i]  == 'i' || prob[i] == 'I') && (prob[++i]  == 'n' || prob[++i] == 'N') && (prob[++i]  == 'h' || prob[++i] == 'H'))
                {
                    i++;
                    if (prob[i] == ' ')
                    {
                        do {
                            i++;
                        } while (prob[i] == ' ');
                    }
                    
                    if (isdigit(prob[i]))
                    {
                        i = tonum(prob, i, barr, m);
                        barr[m] = sinh(barr[m]);
                        m++;
                    }
                    else if (prob[i] == '(')
                    {
                        
                        i = calcbra(prob, barr, i, m);
                        barr[m] = sinh(barr[m]);
                        m++;
                    }
                }
                else if ((prob[i]  == 'i' || prob[i] == 'I') && (prob[++i]  == 'n' || prob[++i] == 'N'))
                {
                    i++;
                    if (prob[i] == ' ')
                    {
                        do {
                            i++;
                        } while (prob[i] == ' ');
                    }
                    
                    if (isdigit(prob[i]))
                    {
                        i = tonum(prob, i, barr, m);
                        barr[m] = sin(barr[m]);
                        m++;
                    }
                    else if (prob[i] == '(')
                    {
                        
                        i = calcbra(prob, barr, i, m);
                        barr[m] = sin(barr[m]);
                        m++;
                    }
                }
        } 
        else if (prob[i]  == 'c' || prob[i] == 'C')
        {
            
            i++;
            if ((prob[i]  == 'o' || prob[i] == 'O') && (prob[++i]  == 's' || prob[++i] == 'S') && (prob[++i]  == 'h' || prob[++i] == 'H'))
                {
                    i++;
                    if (prob[i] == ' ')
                    {
                        do {
                            i++;
                        } while (prob[i] == ' ');
                    }
                    
                    if (isdigit(prob[i]))
                    {
                        i = tonum(prob, i, barr, m);
                        barr[m] = cosh(barr[m]);
                        m++;
                    }
                    else if (prob[i] == '(')
                    {
                        
                        i = calcbra(prob, barr, i, m);
                        barr[m] = cosh(barr[m]);
                        m++;
                    }
                }
            else if ((prob[i]  == 'o' || prob[i] == 'O') && (prob[++i]  == 's' || prob[++i] == 'S'))
                {
                    i++;
                    if (prob[i] == ' ')
                    {
                        do {
                            i++;
                        } while (prob[i] == ' ');
                    }
                    
                    if (isdigit(prob[i]))
                    {
                        i = tonum(prob, i, barr, m);
                        barr[m] = cos(barr[m]);
                        m++;
                    }
                    else if (prob[i] == '(')
                    {
                        
                        i = calcbra(prob, barr, i, m);
                        barr[m] = cos(barr[m]);
                        m++;
                    }
                }
        }
        
        else if (prob[i]  == 't' || prob[i] == 'T')
        {
            i++;
            if ((prob[i]  == 'a' || prob[i] == 'A') && (prob[++i]  == 'n' || prob[++i] == 'N') && (prob[++i]  == 'h' || prob[++i] == 'H'))
                {
                    i++;
                    if (prob[i] == ' ')
                    {
                        do {
                            i++;
                        } while (prob[i] == ' ');
                    }
                    
                    if (isdigit(prob[i]))
                    {
                        i = tonum(prob, i, barr, m);
                        barr[m] = tanh(barr[m]);
                        m++;
                    }
                    else if (prob[i] == '(')
                    {
                        
                        i = calcbra(prob, barr, i, m);
                        barr[m] = tanh(barr[m]);
                        m++;
                    }
            else if ((prob[i]  == 'a' || prob[i] == 'A') && (prob[++i]  == 'n' || prob[++i] == 'N'))
                {
                    i++;
                    if (prob[i] == ' ')
                    {
                        do {
                            i++;
                        } while (prob[i] == ' ');
                    }
                    
                    if (isdigit(prob[i]))
                    {
                        i = tonum(prob, i, barr, m);
                        barr[m] = tan(barr[m]);
                        m++;
                    }
                    else if (prob[i] == '(')
                    {
                        
                        i = calcbra(prob, barr, i, m);
                        barr[m] = tan(barr[m]);
                        m++;
                    }
                }
        }
        
        else if (prob[i]  == 'a' || prob[i] == 'A')
        {
            i++;
                if ((prob[i]  == 's' || prob[i] == 'S') && (prob[++i]  == 'i' || prob[++i] == 'I') && (prob[++i]  == 'n' || prob[++i] == 'N'))
                {
                    i++;
                    if (prob[i] == ' ')
                    {
                        do {
                            i++;
                        } while (prob[i] == ' ');
                    }
                    
                    if (isdigit(prob[i]))
                    {
                        i = tonum(prob, i, barr, m);
                        barr[m] = asin(barr[m]);
                        m++;
                    }
                    else if (prob[i] == '(')
                    {
                        
                        i = calcbra(prob, barr, i, m);
                        barr[m] = asin(iarr[m]);
                        k++;
                    }
                }
                else if ((prob[i]  == 'c' || prob[i] == 'C') && (prob[++i]  == 'o' || prob[++i] == 'O') && (prob[++i]  == 's' || prob[++i] == 'S'))
                {
                    i++;
                    if (prob[i] == ' ')
                    {
                        do {
                            i++;
                        } while (prob[i] == ' ');
                    }
                    
                    if (isdigit(prob[i]))
                    {
                        i = tonum(prob, i, barr, m);
                        barr[m] = acos(barr[m]);
                        m++;
                    }
                    else if (prob[i] == '(')
                    {
                        
                        i = calcbra(prob, barr, i, m);
                        barr[m] = acos(iarr[m]);
                        m++;
                    }
                }
                else if ((prob[i]  == 't' || prob[i] == 'T') && (prob[++i]  == 'a' || prob[++i] == 'A') && (prob[++i]  == 'n' || prob[++i] == 'N'))
                {
                    i++;
                    if (prob[i] == ' ')
                    {
                        do {
                            i++;
                        } while (prob[i] == ' ');
                    }
                    
                    if (isdigit(prob[i]))
                    {
                        i = tonum(prob, i, barr, m);
                        barr[m] = atan(barr[m]);
                        m++;
                    }
                    else if (prob[i] == '(')
                    {
                        
                        i = calcbra(prob, barr, i, m);
                        barr[m] = atan(barr[m]);
                        m++;
                    }
                }
        }
        
        else if (isdigit(prob[i])) 
        {
            i = tonum(prob, i, barr, m);
            m++;
        
        }
        else if (prob[i] == '+' ||  prob[i] == '*' || prob[i] == '-' || prob[i] == '/' || prob[i] == '%' || prob[i] == '^' || prob[i] == '!' || prob[i] == 'E')
        {
            opr[j] = prob[i];
            j++;
            i++;
            if (prob[i] == '+' ||  prob[i] == '*' || prob[i] == '-' || prob[i] == '/' || prob[i] == '%' || prob[i] == '^' || prob[i] == '!' || prob[i] == 'E')
            {
                h = 1;
                err(prob[i]);
                break;
            }
        }
        else
        {
            h = 1;
            err(prob[i]);
            break;
        }
        }
    }
    opr[j] = '\0';

    if (h == 0)
    {
        iarr[k] = bodmas(opr, barr, m);
        free(barr);
    }
    
    i++;
    
    return (i);
}


/**
 * bodmas - a function that calculates strings based on BOMDPMAS rule
 * 
 * @opr: the array of operators
 * @iarr: the array of integers
 * @k: the kength of the integer array
 * Return: returns an integer result
 */
 
double bodmas(char *opr, double *iarr, int k)
{
    int i = 0;
    double res;
    
    while (opr[i] != '\0')
    {
        if (opr[i] == 'E')
        {
            iarr[i] *= pow(10, (int)iarr[i+1]);
            
            rems(opr, i);
            remv(iarr, i, k);
        } else {
            i++;
        }
    }

    i = 0;
    
    while (opr[i] != '\0')
    {
        if (opr[i] == '!')
        {
            iarr[i] = (double)fact((int)iarr[i]);
            rems(opr, i);
        } else {
            i++;
        }
    }

    
    i = 0;
    
    while (opr[i] != '\0')
    {
        if (opr[i] == '%')
        {
            iarr[i] = (double)((int)iarr[i] % (int)iarr[i+1]);
            
            rems(opr, i);
            remv(iarr, i, k);
        } else {
            i++;
        }
    }
    
    i = 0;
    
    while (opr[i] != '\0')
    {
        if (opr[i] == '^')
        {
            iarr[i] = pow(iarr[i], (int)iarr[i+1]);

            rems(opr, i);
            remv(iarr, i, k);
        } else {
            i++;
        }
    }
    
    i = 0;
    
    while (opr[i] != '\0')
    {
        if (opr[i] == '/')
        {
            iarr[i] = iarr[i] / iarr[i+1];
            
            rems(opr, i);
            remv(iarr, i, k);
        } else {
            i++;
        }
    }
    
    i = 0;
    
    while (opr[i] != '\0')
    {
        if (opr[i] == '*')
        {
            iarr[i] = iarr[i] * iarr[i+1];
            
            rems(opr, i);
            remv(iarr, i, k);
        } else {
            i++;
        }
    }
    
    i = 0;
    
    while (opr[i] != '\0')
    {
        if (opr[i] == '-')
        {
            iarr[i] = iarr[i] - iarr[i+1];
            
            rems(opr, i);
            remv(iarr, i, k);
        } else {
            i++;
        }
    }
    
    i = 0;
    
    while (opr[i] != '\0')
    {
        if (opr[i] == '+')
        {
            iarr[i] = iarr[i] + iarr[i+1];
            
            rems(opr, i);
            remv(iarr, i, k);
        } else {
            i++;
        }
    }
    
    
    res = iarr[0];
    
    return (res);
}



/**
 * fact - is a function to calculate a factorial of a number
 * 
 * @i: an integer value
 * Return: returns an integer 
 */
 
double fact(int i)
{
    if (i == 1)
        return (1);
    
    return i * fact(i-1);
}
