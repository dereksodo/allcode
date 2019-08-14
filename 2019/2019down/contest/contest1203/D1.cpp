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
const int maxn = 1000;
string s,t;
int ok(string f)
{
	// printf("f = %s,t = %s\n",f.c_str(),t.c_str());
	int pos1 = 0;
	for(int i = 0;i < f.size() && pos1 < t.size();)
	{
		while(f[i] != t[pos1] && i < f.size())
		{
			++i;
		}
		pos1++;
		++i;
	}
	if(pos1 == t.size())
	{
		// printf("YES\n");
		return 1;
	}
	// printf("NO\n");
	return 0;
}
int check(int len)
{
	// printf("len = %d\n\n\n",len);
	for(int i = 0;i < s.size() - len; ++i)
	{
		// printf("i = %d\n",i);
		// printf("%s %s\n",s.substr(0,i).c_str(),s.substr(i + len).c_str());
		string now = s.substr(0,i) + s.substr(i + len);
		// printf("%s\n",now.c_str());
		// printf("ok\n");
		if(ok(now))
		{
			return 1;
		}
	}
	return 0;
}
int main(int argc, char const *argv[])
{
	cin>>s>>t;
	int ans = 0;
	int l = 1,r = s.size();
	while(l <= r)
	{
		int mid = l + r >> 1;
		if(check(mid))
		{
			l = mid + 1;
			ans = mid;
		}
		else
		{
			r = mid - 1;
		}
	}
	printf("%d\n",ans);
	return 0;
}