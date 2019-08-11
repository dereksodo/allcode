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
const int maxn = 100005;
int a[maxn];
int main(int argc, char const *argv[])
{
	int n,x,y;
	cin>>n>>x>>y;
	for(int i = 0;i < n; ++i)
	{
		scanf("%d",a + i);
	}
	for(int i = 0;i < n; ++i)
	{
		bool flag = 0;
		for(int j = i - 1;j >= max(i - x,0); --j)
		{
			if(a[i] >= a[j])
			{
				flag = 1;
				break;
			}
		}
		for(int j = i + 1;j <= min(i + y,n - 1); ++j)
		{
			if(a[i] >= a[j])
			{
				flag = 1;
				break;
			}
		}
		if(flag == 0)
		{
			printf("%d\n",i + 1);
			return 0;
		}
	}
	return 0;
}