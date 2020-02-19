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
// map<int,int> lst;
const int maxn = 1139227 + 5;
vector<int> d[maxn];
vector<int> lst[maxn];
int check(int s,int step = -1)
{
	int kk = s % 1139227;
	if(step != -1)
	{
		if(!d[kk].empty())
		{
			for(int i = 0;i < d[kk].size(); ++i)
			{
				if(d[kk][i] == s)
				{
					lst[kk][i] = step;
					return 0;
				}
			}
		}
		d[kk].push_back(s);
		lst[kk].push_back(step);
	}
	else
	{
		if(!d[kk].empty())
		{
			for(int i = 0;i < d[kk].size(); ++i)
			{
				if(d[kk][i] == s)
				{
					return lst[kk][i];
				}
			}
		}
	}
	return 0;
}
int main(int argc, char const *argv[])
{
	int n,ans = 0;
	cin>>n;
	for(int l = 1,r = 1,x;r <= n; ++r)
	{
		scanf("%d",&x);
		int pos = check(x);
		if(l <= pos)
		{
			l = pos + 1;
		}
		check(x,r);
		ans = max(ans,r - l + 1);
	}
	cout<<ans<<endl;
	return 0;
}