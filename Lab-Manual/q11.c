#include<stdio.h>
int main(){
    int a,b,c;
    printf("Enter no of employee ");
    scanf("%d",&a);
    printf("Enter basic salary  ");
    scanf("%d",&b);
    printf("net salary is  ");
    printf("%f",(float)a*(b+b*0.12));
    return 0;
}