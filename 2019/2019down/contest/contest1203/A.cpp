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
int a[205];
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	while(n--)
	{
		int k;
		scanf("%d",&k);
		int pos = 0;
		for(int j = 1;j <= k; ++j)
		{
			scanf("%d",&a[j]);
			if(a[j] == 1)
			{
				pos = j;
			}
		}
		bool flag = 0;
		for(int j = pos;j <= k; ++j)
		{
			if(a[j] != j - pos + 1)
			{
				flag = 1;
				break;
			}
		}
		for(int j = 1;j < pos; ++j)
		{
			if(a[j] != k - pos + j + 1)
			{
				flag = 1;
				break;
			}
		}
		if(!flag)
		{
			printf("YES\n");
			continue;
		}
		reverse(a + 1,a + k + 1);
		pos = 0;
		for(int j = 1;j <= k; ++j)
		{
			if(a[j] == 1)
			{
				pos = j;
				break;
			}
		}
		flag = 0;
		for(int j = pos;j <= k; ++j)
		{
			if(a[j] != j - pos + 1)
			{
				flag = 1;
				break;
			}
		}
		for(int j = 1;j < pos; ++j)
		{
			if(a[j] != k - pos + j + 1)
			{
				flag = 1;
				break;
			}
		}
		if(!flag)
		{
			printf("YES\n");
			continue;
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}