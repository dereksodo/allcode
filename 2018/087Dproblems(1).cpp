#include <iostream>
#include <vector>
#include <utility>
using namespace std;

#define MAXN 10000000
int n,m;
typedef struct{
	int first;
	int second;
}node;
vector<node> G[MAXN];
bool v[MAXN];
int d[MAXN];
node node_(int a,int b)
{
	node x;
	x.first = a;
	x.second = b;
	return x;
}
bool f(int x,int y)
{
	if(v[x])
	{
		return d[x] != y;
	}
	v[x] = 1;
	d[x] = y;
	for(int i = 0;i < G[x].size(); ++i)
	{
		node t = G[x][i];
		if(f(t.first,y + t.second))
		{
			return 1;
		}
	}
	return 0;
}
int main(int argc, char const *argv[])
{
	cin>>n>>m;
	while(m--)
	{
		int l,r,d;
		cin>>l>>r>>d;
		G[l].push_back(node_(r,d));
		G[d].push_back(node_(l,-d));
	}
	for(int i = 1;i <= n; ++i)
	{
		if(!v[i] && f(i,0))
		{
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
}