#include<stdio.h>
int main(){
    int a,b,c;
    printf("Enter P. ");
    scanf("%d",&a);
    printf("Enter R ");
    scanf("%d",&b);
    printf("Enter T ");
    scanf("%d",&c);
    printf("SI is ");
    printf("%f",(float)(a*b*c)/100);
    return 0;
}