#include<stdio.h>
int main(){
    int n,i,j,val[10],wts[10],cap;
    printf("Number of inputs : ");
    scanf("%d",&n);
    printf("Enter the values : ");
    for(i=0;i<n;i++){
        scanf("%d",&val[i]);
    }
    printf("Enter the weight : ");
    for(i=0;i<n;i++){
        scanf("%d",&wts[i]);
    }
}