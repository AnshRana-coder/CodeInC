/**Q8. WAP to print below mentioned pattern: 
1  
01  
101  
0101  
10101 */
#include <stdio.h>

int main() {
    
    int i,j,count=0;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            if(i>=j){
                count++;
                if((i + j) % 2 == 0){
                    printf("%d",1);
                }else{
                    printf("%d",0);
                }
            }
            
        }
        printf("\n");
    }

    return 0;
}