#include<stdio.h>
int main(){
    int i,j;
    for(i=1;i<=6;i++){

        for(j=1;j<=10;j++){
                if((i==1&&j<=6)||(i==6&&j<=6)|| i==12-j || j==1)
                printf("*");
                else
                printf(" ");
          
        }
        
       
        printf("\n");
    }
    return 0;
}