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
using namespace std;
typedef long long ll;
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
const int maxn = 5005;
int a[maxn];
tuple<ll,ll,ll> s[maxn];
map< pair<ll,ll>,ll > mp;
bool check()
{
	int first = mp[{0,get<1>(s[0]) - 1}];
	for(auto i : mp)
	{
		if(i.second != first)
		{
			return 1;
		}
	}
	return 0;
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	for(int i = 0;i < n; ++i)
	{
		scanf("%d",a + i);
	}
	int slen = 0;
	int last = 0;
	for(int i = 0;i < n;)
	{
		int j = i + 1;
		for(;j < n; ++j)
		{
			if(a[j] != a[i])
			{
				break;
			}
		}
		printf("i = %d,j = %d\n",i,j);
		j--;
		s[slen++] = {j - i + 1,last + 1,j};
		i = j + 1;
		last = i;
	}

	while(check())
	{
		priority_queue< pair<int,int> > pq;
		for(int i = 0;i < slen; ++i)
		{
			ll ans = 0;
			if(i)
			{
				ans = max(ans,get<1>(s[i]) + get<1>(s[i - 1]));
			}
			if(i != slen - 1)
			{
				ans = max(ans,get<1>(s[i]) + get<1>(s[i + 1]));
			}
			if(a[get<3>(s[i - 1])] == a[get<3>(s[i + 1])])
			{

			}
		}
	}
	return 0;
}