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
map<int,int> mp;
int a[3005];
int main(int argc, char const *argv[])
{
	int n;
	while(cin>>n)
	{
		mp.clear();
		for(int i = 1;i <= n; ++i)
		{
			scanf("%d",&a[i]);
		}
		for(int j = 1;j <= n - 1; ++j)
		{
			mp[abs(a[j + 1] - a[j])]++;
		}
		int flag = 1;
		for(int i = 1;i <= n - 1; ++i)
		{
			if(mp[i] != 1)
			{
				printf("Not jolly\n");
				flag = 0;
				break;
			}
		}
		if(flag)
		{
			printf("Jolly\n");
		}
	}
	return 0;
}