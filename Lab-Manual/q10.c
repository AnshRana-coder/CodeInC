#include<stdio.h>
int main(){
    int a,b,c;
    printf("Enter 1st no. ");
    scanf("%d",&a);
    printf("Enter 2nd no. ");
    scanf("%d",&b);
    a=a+b;
    b=a-b;
    a=a-b;
    printf("%d ",a);
    printf("%d",b);
    
    return 0;
}