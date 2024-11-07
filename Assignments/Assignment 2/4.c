// WAP to find Who & how many students have scored 99 in an array Marks. 
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
        printf("%d time 99 is repeated",count);
    }else{
        printf("99 is not even present");
    }

    return 0;
}