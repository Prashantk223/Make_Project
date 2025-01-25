#include <stdio.h>
#include <math.h>
#include "mod2.h"
void square_sharedlib()
{
    printf("Hello from shared lib mod2.c Square root \n");   
    pow(15.00, 2); 
}