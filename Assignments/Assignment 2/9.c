// WAP to find a peak element which is not smaller than its neighbors.


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

    int peak=arr[0];
  

    for (int i = 1; i < (n-1); i++) {
        
        if(arr[i]>arr[i+1] && arr[i]>arr[i-1]){
            peak = arr[i];
        }
        
    }
    if (peak==arr[0]){
        printf("NO PEAK ELEMENT");
    }else{
        printf("1 st peak element is %d", peak);
    }
    return 0;
}
