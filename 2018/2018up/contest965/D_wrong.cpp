#include <iostream>
#include <cstring>
#include <cmath>
#include <climits>
using namespace std;
const int maxn = 1e5 + 5;
#define inf 0x3f3f3f3f
int w,l;
int a[maxn];
int vis[maxn];
int nex_pos(int pos)
{
	if(pos + l >= w)
	{
		return inf;
	}
	for(int i = pos + l;i > pos; --i)
	{
		if(a[i] - vis[i] >= 1)
		{
			vis[i]++;
			return i;
		}
	}
	return 0;
}
bool ok(int n)
{
	int pos = 0;
	while(n--)
	{
		pos = 0;
		while(1)
		{
			pos = nex_pos(pos);
			if(pos == inf)
			{
				break;
			}
			if(!pos)
			{
				return 0;
			}
		}
	}
	return 1;
}
int main()
{
	cin>>w>>l;
	int maxp = 0;
	for(int i = 1;i < w; ++i)
	{
		cin>>a[i];
		maxp += a[i];
	}
	int left = 0,right = max(maxp,w) * 2;
	while(left + 1 < right)
	{
		memset(vis,0x00,sizeof(vis));
		int mid = (left + right + 1) / 2;
		if(ok(mid))
		{
			left = mid;
		}
		else
		{
			right = mid;
		}
	}
	printf("%d\n",left);
	return 0;
}