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
map<int,int> indeg;
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	for(int i = 0;i < n - 1; ++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		indeg[x]++;
		indeg[y]++;
	}
	for(auto iter = indeg.begin();iter != indeg.end(); ++iter)
	{
		if(iter->second == 2)
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}