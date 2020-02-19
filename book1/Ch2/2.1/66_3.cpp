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
const int maxn = 2e6 + 6;
char s[maxn];
int n;
int main(int argc, char const *argv[])
{
	scanf("%d%s",&n,s + 1);
	if(!(n & 1))
	{
		printf("NOT POSSIBLE\n");
		return 0;
	}
	int m = (n >> 1) + 1;
	int cnt1 = 0,cnt2 = 0;
	int fg1 = 1,fg2 = 1;
	for(int i = 1,j = m;i < m,j <= n; ++i,++j)
	{
		if(s[i] != s[j])
		{
			if(cnt1)
			{
				fg1 = 0;
				break;
			}
			else
			{
				--i,cnt1 = 1;
			}
		}
	}
	for(int i = 1,j = m + 1;i <= m,j <= n; ++i,++j)
	{
		if(s[i] != s[j])
		{
			if(cnt2)
			{
				fg2 = 0;
				break;
			}
			else
			{
				--j,cnt2 = 1;
			}
		}
	}
	if(fg2)
	{
		if(!cnt2 || !fg1)
		{
			printf("%s\n",s + m + 1);
		}
		else
		{
			printf("NOT UNIQUE\n");
		}
	}
	else if(!fg1)
	{
		printf("NOT POSSIBLE\n");
	}
	else
	{
		s[m] = '\0';
		printf("%s\n",s + 1);
	}
	return 0;
}