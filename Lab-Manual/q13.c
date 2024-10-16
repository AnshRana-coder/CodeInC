#include<stdio.h>
#include<math.h>
int main(){
    int a,b,c;
    printf("Enter a ");
    scanf("%d",&a);
    printf("Enter b ");
    scanf("%d",&b);
    printf("a to the power b is is ");
    c=pow(a,b);
    printf("%d",c);
    return 0;
}