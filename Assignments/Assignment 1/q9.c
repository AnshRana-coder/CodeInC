/**Q9. WAP to print following Pyramid: 
0        0 
01      01
010    010  
0101  0101  
0101001010 */
#include <stdio.h>

int main() {
    
    int i,j,count=0;
    for(i=1;i<=5;i++){
        for(j=1;j<=10;j++){
            if(i>=j|| j>=i){
                printf("i");
                
            }else{
                printf( " ");
            }
            
        }
        printf("\n");
    }

    return 0;
}