//find prime no. within a range of no.
#include <stdio.h>

int main()
{
 
    int a, b, i, j, flag;

    printf("Enter lower bound of the interval: ");
    scanf("%d", &a); 
    printf("\nEnter upper bound of the interval: ");
    scanf("%d", &b); 
    printf("\nPrime numbers between %d and %d are: ", a, b);
    for (i = a; i <= b; i++) {
        flag = 1;

        for (j = 2; j < i ; ++j) {
            if (i % j == 0) {
                flag = 0;
                break;
            }
        }
        
        if (flag == 1)
            printf("%d ", i);
    }

    return 0;
}