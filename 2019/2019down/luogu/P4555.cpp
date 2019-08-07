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
const int maxn = 1e5 + 5;
char a[maxn],s[maxn << 1];
int pal[maxn << 1];
int n;
int l[maxn << 1],r[maxn << 1];
void manacher()
{
	s[0] = '~';
	s[1] = '#';
	for(int i = 0;i < n; ++i)
	{
		s[i * 2 + 2] = a[i];
		s[i * 2 + 3] = '#';
	}
	n = n * 2 + 2;
	// printf("%s\n",s);
	int maxright = 0,mid = 0;
	for(int i = 1;i < n; ++i)
	{
		if(i < maxright)
		{
			pal[i] = min(pal[(mid << 1) - i],maxright - i);
		}
		else
		{
			pal[i] = 1;
		}
		while(s[i + pal[i]] == s[i - pal[i]])
		{
			pal[i]++;
		}
		if(pal[i] + i > maxright)
		{
			maxright = pal[i] + i;
			mid = i;
		}
		l[i + pal[i] - 1] = max(l[i + pal[i] - 1],pal[i] - 1);
		r[i - pal[i] + 1] = max(r[i - pal[i] + 1],pal[i] - 1);
	}
}
int main(int argc, char const *argv[])
{
	scanf("%s",a);
	n = strlen(a);
	manacher();
	int ans = 0;
	for(int i = 2;i < n; i += 2)
	{
		r[i] = max(r[i],r[i - 2] - 2);
	}
	for(int i = n - 1;i >= 2; i -= 2)
	{
		l[i] = max(l[i],l[i + 2] - 2);
	}
	for(int i = 2;i < n; ++i)
	{
		if(l[i] && r[i])
		{
			ans = max(ans,r[i] + l[i]);
		}
	}
	cout<<ans<<endl;
	return 0;
}