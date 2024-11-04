//  WAP to check whether a given is Armstrong or not  
// For example, 153 is an Armstrong number because 1^3 + 5^3 + 3^3 = 153.
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
    num=a;
    while(a>0){
        x=a%10;
        sum=sum + pow(x,count) ;
        a=a/10;
       
    }
    if (sum==num){
        printf("armstrong no");
    }
    else{
        printf("not armstrong no");
    }
}