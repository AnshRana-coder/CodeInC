// WAP to increase every student mark by 5 & then print the updated array. 
#include<stdio.h>
#include <math.h>
int main(){
     int n;

    printf("Enter the number of elements");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the element ");

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("marks now");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n updated marks ");
    for(int i=0;i<n;i++){
        arr[i]=arr[i]+5;
        printf("%d ",arr[i]);
    }
    

    return 0;
}