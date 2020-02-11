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
const int maxn = 1005;
int b[maxn];
int main(int argc, char const *argv[])
{
	freopen("berries.in","r",stdin);
	freopen("berries.out","w",stdout);
	int n,k;
	cin>>n>>k;
	k /= 2;
	int mm = 0;
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d",&b[i]);
		mm = max(mm,b[i]);
	}
	int ans = 0;
	for(int i = 1;i <= mm; ++i)
	{
		// printf("i = %d\n",i);
		int sum = 0;
		priority_queue<int> pq;
		for(int j = 1;j <= n; ++j)
		{
			pq.push(b[j] % i);
			int x = b[j] / i;
			while(x--)
			{
				pq.push(i);
			}
		}
		// printf("\n");
		int k2 = k;
		// printf("k = %d\n",k);
		while(k-- && !pq.empty())
		{
			pq.pop();
		}
		auto p2 = pq;
		while(!p2.empty())
		{
			// printf("%d ",p2.top());
			p2.pop();
		}
		k = k2;
		while(k-- && !pq.empty())
		{
			sum += pq.top();
			pq.pop();
		}
		k = k2;
		ans = max(ans,sum);
	}
	cout<<ans<<endl;
	return 0;
}