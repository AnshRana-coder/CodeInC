//WAP to find who scored first “99” in an array marks. 
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

    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]==99){
            count=count+1;
            
            

        }

        
    }
    if(count!=0){
        printf("99 is present");
    }else{
        printf("99 is not present");
    }

    return 0;
}