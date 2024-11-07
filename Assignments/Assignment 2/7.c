//WAP to check whether score is even or odd in an array.
#include <stdio.h>

int main() {
    int n;

    printf("Enter the number of elements");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the element ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            printf("element %d is even.\n", arr[i]);
        } else {
            printf("element %d is odd.\n", arr[i]);
        }
    }

    return 0;
}
