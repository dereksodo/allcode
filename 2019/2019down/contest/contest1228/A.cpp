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
int vis[15];
int check(int s)
{
	memset(vis,0x00,sizeof(vis));
	while(s)
	{
		vis[s % 10]++;
		s /= 10;
	}
	for(int i = 0;i <= 9; ++i)
	{
		if(vis[i] > 1)
		{
			return 0;
		}
	}
	return 1;
}
int main(int argc, char const *argv[])
{
	int l,r;
	cin>>l>>r;
	int ans = 0;
	for(int i = l;i <= r; ++i)
	{
		if(check(i))
		{
			printf("%d\n",i);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}