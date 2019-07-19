#include <iostream>
using namespace std;
#define N 305
int dp[N][N][N],vis[N][N][N];
char G[N][N],t[1];
int n,m,x,y;
int dfs(int i,int j,char k) {
    if(vis[i][j][k]++)return dp[i][j][k];
    for(int a=1;a<=n;++a)if(G[i][a]>=k){
        if(!dfs(j,a,G[i][a])){dp[i][j][k]=1;break;}
    }
    return dp[i][j][k];
}
int main() {
    cin>>n>>m;
    for(int i=0;i<m;++i) {
        cin>>x>>y>>t;
        G[x][y]=t[0];
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j)putchar('B'-dfs(i,j,'a'));
        puts("");
    }
}