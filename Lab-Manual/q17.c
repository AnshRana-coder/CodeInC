#include<stdio.h>
int main(){
    char a;
    printf("Enter a char ");
    scanf("%c",&a);
    if(a=='a'||a=='e' ||a=='i'||a=='0'||a=='u' ||a=='A' ||a=='E'||a=='I' ||a=='0'||a==")"  )
    printf("%c is vowel",a);
    
     else
     printf("conconent");
    return 0;
}