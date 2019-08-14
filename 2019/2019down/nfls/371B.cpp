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
int gcd_(int a,int b)
{
	return b == 0 ? a : gcd_(b,a % b);
}
int main(int argc, char const *argv[])
{
	int n,m;
	cin>>n>>m;
	int gcd = gcd_(n,m);
	n = n / gcd;
	int cnt = 0;
	while(n != 1 && n % 5 == 0)
	{
		n /= 5;
		cnt++;
	}
	while(n != 1 && n % 3 == 0)
	{
		n /= 3;
		cnt++;
	}
	while(n != 1 && n % 2 == 0)
	{
		n /= 2;
		cnt++;
	}
	if(n != 1)
	{
		printf("-1\n");
		return 0;
	}
	n = m / gcd;
	while(n != 1 && n % 5 == 0)
	{
		n /= 5;
		cnt++;
	}
	while(n != 1 && n % 3 == 0)
	{
		n /= 3;
		cnt++;
	}
	while(n != 1 && n % 2 == 0)
	{
		n /= 2;
		cnt++;
	}
	if(n != 1)
	{
		printf("-1\n");
		return 0;
	}
	printf("%d\n",cnt);
	return 0;
}