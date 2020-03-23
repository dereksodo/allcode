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
map<int,int> mp; 
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		mp.clear();
		int n;
		scanf("%d",&n);
		for(int i = 0,x;i < n; ++i)
		{
			scanf("%d",&x);
			mp[x] = 1;
		}
		printf("%d\n",(int)mp.size());
	}
	return 0;
}