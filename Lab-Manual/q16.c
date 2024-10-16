#include<stdio.h>
int main(){
    int a,b;
    printf("Enter 1st no. ");
    scanf("%d",&a);
    if(a%3==0  && a%5==0)
    printf("%d is divisible by 5 and 3",a);
    else if(a%3==0) 
    printf("%d is divisible by3",a);
    else if(a%5==0)
    printf("%d is divisible by3",a);
     else
     printf("others");
    return 0;
}