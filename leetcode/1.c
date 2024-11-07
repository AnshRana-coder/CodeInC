// two sum
//Input: nums = [2,7,11,15], target = 9
//Output: [0,1]
//Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

#include <stdio.h>

int twoSum(int* nums, int numsSize, int target, int returnSize){
    int i,j;
    for(i=0;i<numsSize;i++){
        for(j=0;i<numsSize;j++){
            if(nums[i]+nums[j]==target){
                printf("[%d %d]",i,j);
                break;
            }
        }break;
   
    }
   

}

int main() {
    int nums[]={1,2,3,4,5};
    int numsSize=6;
    int target;
    printf("Enter the target");
    scanf("%d",&target);
    int returnSize=2;
    twoSum(nums, numsSize, target,returnSize);
    return 0;
}