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
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	map<int,int> mp;
	while(t--)
	{
		int n;
		cin>>n;
		mp.clear();
		for(int i = 0;i < n; ++i)
		{
			int x;
			scanf("%d",&x);
			x %= 3;
			mp[x]++;
		}
		int ans = 0;
		ans += mp[0];
		int p = min(mp[1],mp[2]);
		ans += p;
		mp[1] -= p;
		mp[2] -= p;
		ans += (mp[1] + mp[2]) / 3;
		cout<<ans<<endl;
	}
	return 0;
}