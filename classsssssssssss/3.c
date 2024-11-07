#include <stdio.h>
struct student{
    int roll_no;
    char name[10];
    float percentage;
};

int main(){
    struct student ob[5];
    
    int i;
    for(i=0;i<2;i++){
        printf("provide roll no");
        scanf("%d",&ob[i].roll_no);
        printf("provide percentaage");
        scanf("%f",&ob[i].percentage);
        printf("provide name");
        scanf("%s",&ob[i].name);


    }
    
    printf("%d  ",sizeof(ob));
    printf("%d   ",sizeof(int));
    printf("%d    ",sizeof(float));
    

    return 0;
}