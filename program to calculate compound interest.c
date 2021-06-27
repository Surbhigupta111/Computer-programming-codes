/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
  
#include <stdio.h>
#include <math.h>

int main()
{
    float p, r, t ,c;
    
    printf("enter the principle interest:");
    scanf("%f" , &p);
    printf("enter the rate of interest:");
    scanf("%f" , &r);
    printf("enter the number of years:");
    scanf("%f" , &t);
    
     c = p *(pow(1 + r/100 , t));
    printf("The compound interest : %f" , c);

    return 0;
}