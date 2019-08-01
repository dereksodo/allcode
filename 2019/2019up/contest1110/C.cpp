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
int a[30];
int gcd(int a,int b)
{
	return b == 0 ? a : gcd(b,a % b);
}
vector<int> solve(int n)
{
	vector<int> v;
	v.clear();
	int ans = 0,pos = 0;
	for(int b = 1;b < n; ++b)
	{
		int now = gcd(b & n,b ^ n);
		if(now == ans)
		{
			v.push_back(b);
		}
		if(now > ans)
		{
			v.clear();
			ans = now;
			pos = b;
			v.push_back(b);
		}
	}
	return v;
}
int x;
int output(int n)
{
	int now = gcd(x & n,x ^ n);
	printf("%d\n",now);
}
void pre()
{
	a[0] = 1;
	for(int i = 1;i <= 26; ++i)
	{
		a[i] = a[i - 1] * 2;
	}
}
int check(int n)
{
	int n2 = n + 1;
	for(int i = 0;i <= 26; ++i)
	{
		if(a[i] == n2)
		{
			return 1;
		}
	}
	return 0;
}
int check2(int n)
{
	for(int i = 0;i <= 26; ++i)
	{
		if(a[i] - 1 > n)
		{
			return a[i - 1] - 1;
		}
	}
	return -1;
}
int b[] = {0,0,1,1,5,1,21,1,85,73,341,89,1365,1,5461,4681,21845,1,87381,1,349525,299593,1398101,178481,5592405,1082401};
int main(int argc, char const *argv[])
{
	pre();
	int T;
	cin>>T;
	while(T--)
	{
		scanf("%d",&x);
		// for(int x = 1;x <= 100; ++x)
		// {
		// 	vector<int> v = solve(x);
		// 	printf("x = %d::",x);
		// 	for(int u : v)
		// 	{
		// 		printf("%d ",u);
		// 	}
		// 	printf("\n");
		// }
		if(check(x))
		{
			for(int i = 0;i <= 26; ++i)
			{
				if(a[i] - 1 == x)
				{
					printf("%d\n",b[i]);
					break;
				}
			}
		}
		else
		{
			int p = check2(x);
			p = p * 2 + 1;
			output(p - x);
		}
	}
	return 0;
}