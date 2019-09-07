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
	}
	for(int i = 1;i <= n; ++i)
	{
		card[a[i]]++;
	}
	int p = *max_element(card + 1,card + n + 1);
	for(int i = 1;i <= n; ++i)
	{
		if(card[i] == p)
		{
			s.push_back(i);
		}
	}
	int n2 = n;
	while(s.size() != 1)
	{
		memset(card,0x00,sizeof(card));
		n %= int(s.size());
		if(n == 0)
		{
			printf("0.0000\n");
		}
		for(int i = 1;i <= n2; ++i)
		{
			if(find(s.begin(),s.end(),a[i]) != s.end())
			{
				card[a[i]]++;
			}
		}
		ans *= 
		int p = *max_element(card + 1,card + n + 1);
		for(int i = 1;i <= n; ++i)
		{
			if(card[i] == p)
			{
				s.push_back(i);
			}
		}
	}
	return 0;
}