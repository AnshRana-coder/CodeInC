#include<stdio.h>
int main(){
    int i,j;
    for(i=1;i<=6;i++){

        for(j=1;j<=11;j++){
                if((i==1&&j<=6)||(i==6&&j<=6)|| (i>1 &&j==6+i)|| j==1)
                printf("*");
                else
                printf(" ");
          
        }
        
       
        printf("\n");
    }
    return 0;
}