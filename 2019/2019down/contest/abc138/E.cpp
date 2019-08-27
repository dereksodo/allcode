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
using namespace std;
typedef long long ll;
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
vector<int> v[30];
int p[30];
int mp(char c)
{
	return int(c - 'a' + 1);
}
int main(int argc, char const *argv[])
{
	string s,t;
	cin>>s>>t;
	for(int i = 0;i < s.size(); ++i)
	{
		v[mp(s[i])].push_back(i);
		p[mp(s[i])] = 1;
	}
	for(int i = 0;i < t.size(); ++i)
	{
		if(p[mp(t[i])] == 0)
		{
			printf("-1\n");
			return 0;
		}
	}
	int nowpos = -1;
	int ans = 0;
	for(int i = 0;i < t.size(); ++i)
	{
		char now = t[i];
		int ai = mp(now);
		int pos = upper_bound(v[ai].begin(),v[ai].end(),nowpos) - v[ai].begin();
		// printf("%c %d\n",now,pos);
		if(pos == int(v[ai].size()))
		{
			++ans;
			nowpos = v[ai][0];
		}
		else
		{
			nowpos = v[ai][pos];
		}
	}
	printf("%lld\n",ll(ans) * ll(int(s.size())) + ll(nowpos) + 1ll);
	return 0;
}