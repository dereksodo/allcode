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
// #define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
const int maxn = 15005;
int z[maxn],n;
string s;
void calc()
{
	memset(z,0x00,sizeof(z));
	int l = 0,r = 0;
	for(int i = 1;i < n; ++i)
	{
		if(i <= r)
		{
			z[i] = min(z[i - l],r - i);
		}
		while(i + z[i] < n && s[z[i]] == s[i + z[i]])
		{
			z[i]++;
		}
		if(i + z[i] > r)
		{
			l = i,r = i + z[i];
		}
	}
	for(int i = 1;i < n; ++i)
	{
		debug("z[%d] = %d\n",i,z[i]);
	}
}
int main(int argc, char const *argv[])
{
	string s1,s2;
	cin>>s1>>s2;
	int m = s1.size();
	int ans = 1e9;
	for(int i = 0;i < m; ++i)
	{
		s = s1.substr(i,m - i) + '$' + s1 + '^' + s2;
		debug("s = %s\n",s.c_str());
		n = s.size();
		calc();
		z[m + 1] = 0;
		int tmp = 0,tmp2 = 0,ok = 0,idx = -1;
		for(int j = 1;j < n; ++j)
		{
			if(z[j] > tmp)
			{
				tmp2 = tmp;
				tmp = z[j];
				idx = j;
				ok = 1;
			}
			else if(z[j] == tmp)
			{
				ok = 0;
			}
			else if(z[j] > tmp2)
			{
				tmp2 = z[j];
			}
			debug("tmp = %d,tmp2 = %d,ok = %d,idx = %d\n",tmp,tmp2,ok,idx);
		}
		if(ok && idx > 2 * m - i + 1)
		{
			ans = min(ans,tmp2 + 1);
		}
	}
	if(ans == 1e9)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n",ans);
	}
	return 0;
}