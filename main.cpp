#include <iostream>
#include <cstring>

using namespace std;
int solve(char *a,char *b,int i,int j);
int dp[1005][1005];
int main() {
    char s1[1005],s2[1005];
    while(~scanf("%s%s",s1,s2)){
        memset(dp,-1,sizeof(dp));
       // cout<<strlen(s1)<<endl;
        cout<<solve(s1,s2,strlen(s1)-1,strlen(s2)-1)<<endl;
    }
    return 0;
}

int solve(char *a,char *b,int i,int j){
    if(i<0 || j<0){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(a[i]==b[j]){
        return dp[i][j] = 1 + solve(a,b,i-1,j-1);
    }
    else{
        return dp[i][j] = max(solve(a,b,i-1,j),solve(a,b,i,j-1));
    }

}