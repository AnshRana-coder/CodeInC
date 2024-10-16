#include<stdio.h>
#include<math.h>
int main(){
    int a,b;
    printf("Enter height of the tringle ");
    scanf("%d",&a);
    printf("Enter base of the tringle ");
    scanf("%d",&b);
    printf("hypotenuse of the triangle is ");
    printf("%f",sqrt(a*a+b*b));
    return 0;
}