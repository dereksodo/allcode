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
const int maxn = 2e5 + 5;
int a[maxn];
map<int,int> mp,mp2;
priority_queue< int,vector<int>,greater<int> > v[maxn];
int n,k;
int output = 0x3f3f3f3f;
int out(int p)
{
	int cnt = 0;
	int ret = 0;
	while(cnt < k)
	{
		ret += v[p].top();
		cnt++;
		v[p].pop();
	}
	return ret;
}
int main(int argc, char const *argv[])
{
	cin>>n>>k;
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d",&a[i]);
		int a2 = a[i];
		int now = 0;
		while(a2)
		{
			mp[a2]++;
			v[a2].push(now++);
			a2 /= 2;
		}
	}
	output = 0x3f3f3f3f;
	for(map<int,int>::iterator iter = mp.begin();iter != mp.end(); ++iter)
	{
		// auto pi = v[iter->first];
		// while(!pi.empty())
		// {
		// 	printf("%d ",pi.top());
		// 	pi.pop();
		// }
		// printf("\n");
		// printf("iter->first = %d,iter->second = %d\n",iter->first,iter->second);
		if(iter->second >= k && !mp2[iter->first])
		{
			output = min(output,out(iter->first));
			mp2[iter->first] = 1;
		}
	}
	cout<<output<<endl;
	return 0;
}