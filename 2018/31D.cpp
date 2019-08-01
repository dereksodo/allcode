#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 207;
const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,1,0,-1};
int a[maxn][maxn];
int w,h,n;
int cnt;
vector<int> list;
void dfs(int x, int y)
{
    a[x][y] = 1;
    if((x % 2 == 1) && (y % 2 == 1)) cnt++;
    int xt = 0,yt = 0;
    for(int k = 0;k < 4; ++k)
    {
        xt = x + dx[k]; 
        yt = y + dy[k];
        if(xt >= 0 && xt <= w * 2 && yt >= 0 && yt <= h * 2 && !a[xt][yt])
        {
            dfs(xt,yt);
        }
    }
}

int main()
{
    scanf("%d%d%d",&w,&h,&n);
    memset(a,0x00,sizeof(a));
    for(int x = 0;x <= 2 * w; ++x)
    {
        a[x][0] = a[x][h * 2] = 1;
    }
    for(int y = 0;y <= 2 * h; ++y)
    {
        a[0][y] = a[w * 2][y] = 1;
    }
    int x1,y1,x2,y2;
    for(int i = 1;i <= n; ++i)
    {
        cin>>x1>>y1>>x2>>y2;
        if(x1 > x2)
        {
            swap(x1,x2);
        }
        if(y1 > y2)
        {
            swap(y1,y2);
        }
        if(y1 == y2) 
        {
            for(int x = x1 * 2;x <= x2 * 2; ++x)
            {
                a[x][y1 * 2] = 1;
            }
        }
        else
        {
            for(int y = y1 * 2;y <= y2 * 2; ++y)
            {
                a[x1 * 2][y] = 1;
            }
        }
    }
    for(int x = 0;x <= w * 2; ++x)
    {
        for(int y = 0;y <= h * 2; ++y)
        {
            if(!a[x][y])
            {
                cnt = 0;
                dfs(x,y);
                list.push_back(cnt);
            }
        }
    }
    sort(list.begin(),list.end());
    for(int i = 0;i < list.size(); ++i)
    {
        printf("%d ",list[i]);
    }
    printf("\n");
    return 0;
}