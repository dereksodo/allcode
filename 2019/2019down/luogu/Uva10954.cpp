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
	int n;
	while(cin>>n && n)
	{
		priority_queue< int,vector<int>,greater<int> > pq;
		int x;
		for(int i = 1;i <= n; ++i)
		{
			scanf("%d",&x);
			pq.push(x);
		}
		ll ans = 0;
		while(1)
		{
			x = pq.top();
			pq.pop();
			x += pq.top();
			pq.pop();
			ans += x;
			if(pq.empty())
			{
				break;
			}
			pq.push(x);
		}
		cout<<ans<<endl;
	}
	return 0;
}