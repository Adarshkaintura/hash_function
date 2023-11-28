#include<stdio.h>
#include<stdlib.h>
int main(){
    int arr[9];
    int k=0;
    printf("enter the elements in the array\n");
    for(int i=0;i<9;i++){
        printf("enter the data %d::",i+1);
        printf("\n");
        scanf("%d",&k);
        arr[k%9]=k;
    }
printf("the data in the list is as follows\n");
for (int i = 0; i < 9; i++)
{
    printf("%d ",arr[i]);
}
printf("enter the element you want to search\n");
scanf("%d",&k);
if(arr[k%9]==k){
    printf("data is found\n");
}
else{
    printf("not found\n");
}
return 0;
}