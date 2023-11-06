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
    int dp[n+1][n+1];
    for(i=0;i<=n;i++){
        for(j=0;j<=n;j++){
            dp[i][j]=dp[i-1][j];
            if(j>=wts[i-1]){
                int rcap =j-wts[i-1];
                if(dp[i-1][rcap]+val[i-1]>dp[i-1][j]){
                    dp[i][j]=dp[i-1][rcap]+val[i-1];
                }
                else {
                    dp[i][j]= dp[i-1][j];
                }

            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
        printf("%d\n",dp[n][cap]);
    }
    return 0;
}