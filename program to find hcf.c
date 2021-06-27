/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int x , y , i , HCF;
    printf("enter two numbers to find their HCF");
    scanf("%d""%d" , &x ,&y);
    
    for(i = 1 ; i <= x || i <= y ; i++){
        if(x % i == 0 && y % i == 0)
        HCF = i;
    }
    printf("the HCF is %d" , HCF);


    return 0;
}


