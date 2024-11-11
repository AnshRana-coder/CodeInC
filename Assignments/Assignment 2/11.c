//WAP to implement Insert -Front, any position in between & end in an array. Print 
//the array before insert & after insert.

#include <stdio.h>

int main() {
    int n,k,num;

    printf("Enter the number of elements");
    scanf("%d", &n);

    int arr[n+1];
    printf("Enter the element ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("enter the element to be inserted");
    scanf("%d", &num);
    printf("enter the pos to be inserted");
    scanf("%d",k);
    
    if(k==0){
        for(int i=0;i<n+1;i++){
            arr[n+1-i]=arr[n+2-i]

        }
    }else if(k==n+1){
        arr[n+1]=num;
    }

    return 0;

}
