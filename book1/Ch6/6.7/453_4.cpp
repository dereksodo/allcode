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
const int maxn = 10005;
int sg[maxn],a[105];
int hsh[maxn];
void SG(int *s,int t)
{
	memset(sg,0x00,sizeof(sg));
	for(int i = 1;i < maxn; ++i)
	{
		memset(hsh,0x00,sizeof(hsh));
		int j;
		for(j = 0;j < t; ++j)
		{
			if(i >= s[j])
			{
				hsh[sg[i - s[j]]] = 1;
			}
		}
		for(j = 0;j < maxn; ++j)
		{
			if(!hsh[j])
			{
				break;
			}
		}
		sg[i] = j;
	}
}
int main(int argc, char const *argv[])
{
	int n;
	while(~scanf("%d",&n) && n)
	{
		for(int i = 0;i < n; ++i)
		{
			scanf("%d",&a[i]);
		}
		sort(a,a + n);
		SG(a,n);
		int m;
		scanf("%d",&m);
		while(m--)
		{
			int num,sum = 0;
			scanf("%d",&num);
			for(int i = 1;i <= num; ++i)
			{
				int v;
				scanf("%d",&v);
				sum ^= sg[v];
			}
			if(sum)
			{
				printf("W");
			}
			else
			{
				printf("L");
			}
		}
		printf("\n");
	}
	return 0;
}