/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<stdio.h>

int findMaxElem(int arr[], int n)
{

    int maxno = 0;
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] > maxno)
        {
            maxno = arr[i];
        }
    }
    return maxno;
}
int main()
{
    int n;
    
    
    printf("Enter the size of an array\n");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int ans = findMaxElem(arr, n);
    printf("Max no : %d", ans);   
    return 0;
}

