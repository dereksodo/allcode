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
	int t;
	cin>>t;
	while(t--)
	{
		int n,X;
		scanf("%d%d",&n,&X);
		map<int,int> mp;
		while(n--)
		{
			int x;
			scanf("%d",&x);
			mp[x] = 1;
		}
		int cnt = 1;
		int ans = X;
		for(map<int,int>::iterator iter = mp.begin();iter != mp.end(); ++iter)
		{
			int l = iter->first - cnt;
			if(l <= X)
			{
				ans = max(ans,iter->first + X - l);
			}
			// printf("%d %d %d\n",cnt,iter->first,ans);
			cnt++;
		}
		cout<<ans<<endl;
	}
	return 0;
}