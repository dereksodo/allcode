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
const int maxn = 100005;
int a[maxn];
int card[maxn];
int n,m;
vector<int> s;
int main(int argc, char const *argv[])
{
	// freopen("a.in","r",stdin);
	// freopen("a.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= m; ++i)
	{
		scanf("%d",&a[i]);
		card[a[i]]++;
	}
	int mx = 0,mxcnt = 0;
	for(int i = 1;i <= n; ++i)
	{
		if(card[i] > mx)
		{
			mx = card[i];
			mxcnt = 1;
		}
		else if(card[i] == mx)
		{
			mxcnt++;
		}
	}
	if(mx <= 1)
	{
		printf("0.0000\n");
		return 0;
	}
	int cur = mxcnt;
	while(cur)
	{
		if(cur == 1)
		{
			break;
		}
		if(n % cur == 0)
		{
			printf("0.0000\n");
			return 0;
		}
		cur = n % cur;
	}
	printf("%.4lf\n",1.0 / double(mxcnt));
	return 0;
}