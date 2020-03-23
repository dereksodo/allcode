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
int check(int x)
{
	int x2 = x;
	while(x2)
	{
		if(x2 % 10 != 0 && x % (x2 % 10) == 0)
		{
			return 0;
		}
		x2 /= 10;
	}
	return 1;
}
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--)
	{
		int x;
		cin>>x;
		if(x == 1)
		{
			printf("-1\n");
		}
		else
		{
			printf("4");
			for(int i = 0;i < x - 1; ++i)
			{
				printf("3");
			}
			printf("\n");
		}
	}
	return 0;
}