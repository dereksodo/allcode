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
	int n,a,b,c;
	scanf("%d%d%d%d",&n,&a,&b,&c);
	int ans = 0;
	for(int i = 0;i <= n; ++i)
	{
		for(int j = 0;j <= n; ++j)
		{
			if(a * i + b * j <= n)
			{
				if((n - a * i - b * j) % c == 0)
				{
					ans = max(ans,i + j + (n - a * i - b * j) / c);
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}