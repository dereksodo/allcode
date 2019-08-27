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
		int a,b,c,d,e;
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
		int ans = 0;
		for(int i = 0;i <= c && 2 * i <= a; ++i)
		{
			int pricenow = i * e;
			int bunnow = a - 2 * i;
			int beefbur = min(bunnow / 2,b);
			ans = max(ans,pricenow + beefbur * d);
		}
		cout<<ans<<endl;
	}
	return 0;
}