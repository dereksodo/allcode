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
int flag[maxn];
int a[maxn];
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	for(int i = 0;i < n; ++i)
	{
		scanf("%d",&a[i]);
	}
	bool allpos = 1,allneg = 1;
	for(int i = 0;i < n; ++i)
	{
		if(a[i] >= 0)
		{
			flag[i] = 1;
			allneg = 0;
		}
		else
		{
			flag[i] = -1;
			allpos = 0;
		}
	}
	if(allpos || allneg)
	{
		int maxpos = 0;
		for(int i = 0;i < n; ++i)
		{
			if(abs(a[i]) < abs(a[maxpos]))
			{
				maxpos = i;
			}
		}
		flag[maxpos] *= -1;
	}
	int sum = 0;
	for(int i = 0;i < n; ++i)
	{
		sum += a[i] * flag[i];
	}
	printf("%d\n",sum);
	int p = -1,q = -1;
	for(int i = 0;i < n; ++i)
	{
		if(flag[i] == 1)
		{
			if(p == -1)
			{
				p = i;
			}
		}
		else
		{
			if(q == -1)
			{
				q = i;
			}
		}
	}
	for(int i = 0;i < n; ++i)
	{
		if(i == p || i == q)
		{
			continue;
		}
		if(flag[i] == 1)
		{
			printf("%d %d\n",a[q],a[i]);
			a[q] -= a[i];
		}
		else
		{
			printf("%d %d\n",a[p],a[i]);
			a[p] -= a[i];
		}
	}
	printf("%d %d\n",a[p],a[q]);
	return 0;
}