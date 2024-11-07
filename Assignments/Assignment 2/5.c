// WAP to find sum of all scores in Marks array. 
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

    int sum=0;
    for(int i=0;i<n;i++){
        sum=sum+arr[i];

        
    }
    printf("%d is the sum of marks in array",sum);
    
    return 0;
}