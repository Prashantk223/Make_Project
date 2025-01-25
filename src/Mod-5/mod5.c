#include <stdio.h>
#include <math.h>
#include "mod2.h"
#include "mod4.h"

int main()
{
    printf("Hello From Mod-5 calling dynamic library\n");
    square_sharedlib();
    printf("Hello From Mod-5 calling static library\n");
    Mod_4();

    return 0;
}