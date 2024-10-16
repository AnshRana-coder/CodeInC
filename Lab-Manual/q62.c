#include<stdio.h>
int main(){
    int i,j;
    for(i=1;i<=8;i++){

        for(j=1;j<=8;j++){
            if(i==1||i==8||j==1||j==8){
                printf("*");
            }
            else
            printf(" ");
        }
        
        printf(" ");
        printf("\n");
    }
    return 0;
}