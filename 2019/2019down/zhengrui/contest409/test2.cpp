#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#define inf 1061109567
using namespace std;
char a[2],b[2];
int n,m,u,v,cnt,pos[16],g[16][16],can[1<<16],f[1<<16],list[16];
int calc(int cnt){
    if (f[cnt]<inf) return f[cnt];
    int ans=inf,ncnt=cnt;
    while (ncnt){
        if (can[ncnt]) ans=min(ans,calc(cnt^ncnt)+1);
        ncnt=(ncnt-1)&cnt;
    }
    return f[cnt]=ans;
}
int main(){
    scanf("%d",&m);
    memset(pos,-1,sizeof(pos));
    for (int i=1;i<=m;i++){
        scanf("%s%s",a,b),u=a[0]-'L',v=b[0]-'L';
        if (pos[u]==-1) pos[u]=n++;
        if (pos[v]==-1) pos[v]=n++;
        g[pos[u]][pos[v]]=g[pos[v]][pos[u]]=1;
    }
    for (int i=0;i<(1<<n);i++){
        cnt=0,can[i]=1;
        for (int j=0;j<n;j++) if (i&(1<<j)) list[++cnt]=j;
        for (int a=1,u=list[a];a<=cnt&&can[i];u=list[++a])
            for (int b=1,v=list[b];b<=cnt&&can[i];v=list[++b])
                if (g[u][v]) can[i]=0;
    }
    memset(f,63,sizeof(f));
    f[0]=0;
    printf("%d\n",calc((1<<n)-1)-2);
    return 0;
}