//WAP to find average score of the Marks array. 
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
    float avg=(float)sum/n;
    printf("%.2f is the average of marks in array",avg);
    
    return 0;
}