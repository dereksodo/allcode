#include <iostream>
#include <cstring>
#include <cstdlib>
#include <set>
#include <vector>
#include <map>
#include <cstdio>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <cassert>
#include <climits>
#include <numeric>
#include <sstream>
using namespace std;
typedef long long ll;
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
const int maxn = 1000005;
int tot;
int ch[maxn << 2][2];
int b[maxn];
void build(int s)
{
	int u = 1;
	for(int k = 30;k >= 0; --k)
	{
		int c = (s >> k) & 1;
		if(!ch[u][c])
		{
			ch[u][c] = ++tot;
		}
		u = ch[u][c];
	}
}
int search(int s)
{
	int u = 1,ans = 0;
	for(int k = 30;k >= 0; --k)
	{
		int c = (s >> k) & 1;
		if(ch[u][c ^ 1])
		{
			u = ch[u][c ^ 1];
			ans = ans + (1 << k);
		}
		else
		{
			u = ch[u][c];
		}
	}
	return ans;
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	for(int i = 2;i <= n; ++i)
	{
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		b[y] = b[x] ^ w;
	}
	tot = 1;
	int ans = 0;
	for(int i = 1;i <= n; ++i)
	{
		build(b[i]);
		ans = max(ans,search(b[i]));
	}
	cout<<ans<<endl;
	return 0;
}