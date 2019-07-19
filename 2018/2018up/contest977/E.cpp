#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int maxn = 2 * 1e5 + 5;
vector<int> G[maxn];
int n,m;
int pre[maxn];
int find(int index)
{
	if(pre[index] == index)
	{
		return index;
	}
	return pre[index] = find(pre[index]);
}
void join(int x,int y) {
    int fx=find(x),fy=find(y);                                               
    if(fx!=fy) pre[fx]=fy;                                                                        
}
int main(int argc, char const *argv[])
{
	cin>>n>>m;
	for(int i = 0;i < n; ++i)
	{
		pre[i] = i;
	}
	for(int i = 0;i < m; ++i)
	{
		int x,y;
		cin>>x>>y;
		G[x].push_back(y);
		G[y].push_back(x);
		join(x,y);
	}
	int ans = 0;
	for(int i = 0;i < n; ++i)
	{
		if(pre[i] == i)
		{
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}