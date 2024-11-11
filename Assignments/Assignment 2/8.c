//WAP to find maximum & minimum score in the Marks array. 

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

    int max=arr[0];
    int min=arr[0];

    for (int i = 1; i < n; i++) {
        if(arr[i]>=max){
            max=arr[i];

        }
        if (arr[i] < min) {
            min = arr[i];
        }

        
    }
    printf("Max no is %d \n",max);
    printf("Min no is %d ",min);
    return 0;
}
