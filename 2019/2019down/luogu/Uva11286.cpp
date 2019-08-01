#include <iostream>
#include <cstring>
#include <cstdlib>
#include <unordered_set>
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
const int mod = 1e9 + 7;
const int ht = 8999;
const int n = 5;
int a[n];
unordered_set<int> v;
int maxp;
map<int,int> mp;
int hash_init()
{
	sort(a,a + n);
	int ret = 0;
	for(int i = 0;i < n; ++i)
	{
		ret = (ret * ht % mod + a[i]) % mod;
	}
	mp[ret]++;
	maxp = max(maxp,mp[ret]);
	v.insert(ret);
	return ret;
}
int main(int argc, char const *argv[])
{
	int k;
	while(cin>>k && k)
	{
		v.clear();
		mp.clear();
		maxp = 0;
		for(int i = 0;i < k; ++i)
		{
			for(int j = 0;j < n; ++j)
			{
				scanf("%d",&a[j]);
			}
			hash_init();
		}
		int ans = 0;
		for(unordered_set<int>::iterator iter = v.begin();iter != v.end(); ++iter)
		{
			if(mp[*iter] == maxp)
			{
				ans += maxp;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}