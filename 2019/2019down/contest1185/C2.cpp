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
const int maxn = 2e5 + 5;
int t[maxn],cnt[maxn];
int main(int argc, char const *argv[])
{
	int n,m;
	cin>>n>>m;
	for(int i = 0;i < n; ++i)
	{
		scanf("%d",t + i);
	}
	int sum = 0;
	for(int i = 0;i < n; ++i)
	{
		int d = sum + t[i] - m;
		int k = 0;
		if(d > 0)
		{
			for(int j = 100;j > 0; --j)
			{
				int x = j * cnt[j];
				if(d <= x)
				{
					k += (d + j - 1) / j;
					break;
				}
				k += cnt[j];
				d -= x;
			}
		}
		sum += t[i];
		cnt[t[i]]++;
		cout<<k<<" ";
	}
	cout<<endl;
	return 0;
}