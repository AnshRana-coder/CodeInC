#include<stdio.h>
int main(){
    int a,b,c;
    printf("Enter item no ");
    scanf("%d",&a);
    printf("Enter quantity ");
    scanf("%d",&b);
    printf("Enter unit price ");
    scanf("%d",&c);
    printf("amount is ");
    printf("%f",(float)b*c*80/100);
    return 0;
}