//Q6. WAP to accept a coordinate point in an XY coordinate system and determine in which 
//quadrant the coordinate point lies.  
//Test Data: 7 9  
//Expected Output: The coordinate point (7,9) lies in the First quadrant.

#include<stdio.h>
#include <math.h>
int main(){
    int x,y;
    printf("Enter the coordinate");
    scanf("%d %d",&x, &y);
    
    if(x>0){
        if(y>0){
            printf("The coordinate point (%d,%d) lies in the First quadrant.",x,y);
        }
        else{
            printf("The coordinate point (%d,%d) lies in the Fourth quadrant.",x,y);
        }
    }
    else{
        if(y>0){
            printf("The coordinate point (%d,%d) lies in the Second quadrant.",x,y);
        }
        else{
            printf("The coordinate point (%d,%d) lies in the Third quadrant.",x,y);
        }
        
    }
    return 0;
}