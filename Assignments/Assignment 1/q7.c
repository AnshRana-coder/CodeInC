//Q7. WAP for Binary to Decimal conversion & Decimal to Binary for a given number  as per 
//user’s choice.
#include<stdio.h>
#include <math.h>
int main(){
    int a,x,sum=0,num;
    printf("Enter a no ");
    scanf("%d",&a);
    num=a;
    int count=0;


    while(num>0){
         count++;
         num=a/10;
    }
    printf("%d",count);
}