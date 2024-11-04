#include <stdio.h>

int main() {
    char a='r';
    char *p;
    p=&a;
    printf("Size of a=%d size of p=%d",sizeof(a),sizeof(p));
    printf("\nvalue of a=%c & p=%p",a,p+1);
    return 0;
}