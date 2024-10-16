#include<stdio.h>
#include<math.h>
int main(){
    int a,b,c;
    float d;
    printf("Enter P. ");
    scanf("%d",&a);
    printf("Enter R ");
    scanf("%d",&b);
    printf("Enter T ");
    scanf("%d",&c);
    printf("ammount is ");
    float x=1 + (b/100);
    d=a*pow(x,c);
    printf("%f",d);
    return 0;
}