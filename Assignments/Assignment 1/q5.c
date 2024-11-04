//Q5. WAP to check whether number is Perfect Number or not. 
//(To check perfect number, we have to find all divisors of that number and find their sum, if 
//sum of divisors is equal to number it means number is Perfect Number.)
#include <stdio.h>

int main() {
    int x; 

    for (int i = 2; i <= 99; i++) {
        x = 0; 
        for (int j = 1; j <= i / 2; j++) {
            if (i % j == 0) {
                x += j;  
            }
        }

        
        if (x == i) {
            printf("%d ", i);
        }
    }


    return 0;
}
