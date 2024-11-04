// Q4. WAP to accept two integer numbers and swap them using 4 different methods in C
#include<stdio.h>
#include <math.h>
int main(){
    int a,b,c;
    printf("Enter 2 no.");
    scanf("%d %d",&a, &b);

// meathod 1

    c=a;
    a=b;
    b=c;

// meathod 2

    a=a+b;
    b=a-b;
    a=a-b;
    
    return 0;
}