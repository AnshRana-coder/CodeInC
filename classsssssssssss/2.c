#include <stdio.h>

int main() {
    
    char grades[20];
    int i;
    for(i=0;i<3;i++){
        printf("\n name   ");
        fgets(grades,sizeof(grades),stdin);
        fputs(grades,stdout);
       
    }
}
