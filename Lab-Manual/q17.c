#include<stdio.h>
int main(){
    char a;
    printf("Enter a character");
    scanf("%c",&a);
    int x=a;
    if(x>=65||x<=90 || x<=122||x>=97){
        if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u'||a=='A'||a=='E'||a=='I'||a=='O'||a=='U'){
            printf("ENterted aalphabet is Vowel");
        }
        else{
            printf("its consonenst");
        }

    }
    else{
        printf("entered thung is not a alphabet");
    }
    return 0;
}