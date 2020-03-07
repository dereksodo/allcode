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
const int a[4] = {0,23,28,33};
int b[4];
int d;
void exgcd(int a,int b,int &x,int &y)
{
	if(!b)
	{
		d = a,x = 1,y = 0;
		return;
	}
	exgcd(b,a % b,y,x);
	y -= a / b * x;
}
int M;
int IntChina(int r)
{
	M = 1;
	int ans = 0;
	for(int i = 1;i <= r; ++i)
	{
		M *= a[i];
	}
	int x,y;
	for(int i = 1;i <= r; ++i)
	{
		int now = M / a[i];
		exgcd(now,a[i],x,y);
		ans = (ans + now * x * b[i]) % M;
	}
	return (ans + M) % M;
}
int main(int argc, char const *argv[])
{
	int sum = 0;
	int dd;
	while(~scanf("%d%d%d%d",&b[1],&b[2],&b[3],&dd) && b[1] != -1)
	{
		int k = (IntChina(3) - dd + M) % M;
		if(k == 0)
		{
			k = M;
		}
		printf("Case %d: the next triple peak occurs in %d days.\n",++sum,k);
	}
	return 0;
}