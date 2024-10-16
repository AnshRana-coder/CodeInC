#include<stdio.h>
int main(){
    int F;
    printf("Enter the temperature in fahrenite ");
    scanf("%d",&F);
    printf("The temperature in centigrade is is ");
    printf("%f",(F-32)* 5/9);
    return 0;
}