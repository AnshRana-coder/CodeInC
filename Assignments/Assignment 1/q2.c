// Q2. WAP to read two integers and print their HCF (Highest Common Factor). 
//First, divide the large number by a small number. If the remainder is left, then divide the first divisor by remainder. If the remainder divides the first divisor completely, then it is the HCF or highest common factor of the given two numbers.
#include<stdio.h>
#include <math.h>
int main(){
    int a,b,remainder;
    printf("Enter 2 no.");
    scanf("%d %d",&a, &b);
     if (a < b) {
        int temp = a;
        a = b;
        b = temp;
    }

    while (b != 0) {
        remainder = a % b; 
        a = b; 
        b = remainder; 
    }
    printf("The HCF is: %d\n", a);
    return 0;
}