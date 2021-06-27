/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int i, x;
    printf("please enter a number to find its factors ");
    scanf("%d", &x);

    printf("All factors of %d are: \n", x);
    for(i=1; i<=x; i++)
    {
        if(x % i == 0)
        {
            printf("%d, ",i);
        }
    }

    return 0;
}
