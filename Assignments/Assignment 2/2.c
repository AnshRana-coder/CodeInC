//WAP to print grade of students as per their marks given in an array. (>=75-- A 
//grade, 74 to 60--B Grade, 59 to 40--C grade below 40--D grade).
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
   
    for(int i=0;i<n;i++){
        if(arr[i]>=75){
            printf("A");

        }else if(arr[i]>=60){
            printf("B");

        }else if(arr[i]>40){
            printf("C");
        }else{
            printf("D");
        }

    }
    

    return 0;
}