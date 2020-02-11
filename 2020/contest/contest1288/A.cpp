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
int main(int argc, char const *argv[])
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,d;
		cin>>n>>d;
		int upper = sqrt(d);
		bool flag = 0;
		for(int i = 0;i < upper + 5; ++i)
		{
			if(i + (d + i) / (i + 1) <= n)
			{
				flag = 1;
				break;
			}
		}
		if(flag)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}