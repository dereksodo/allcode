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
priority_queue< int,vector<int>,less<int> > pq1,pq2;
int n,cnta,cntb,x;
int a[100005],b[100005];
int main(int argc, char const *argv[])
{
	int T;
	cin>>T;
	while(T--)
	{
		scanf("%d%d%d",&n,&cnta,&cntb);
		while(cnta--)
		{
			scanf("%d",&x);
			pq1.push(x);
		}
		while(cntb--)
		{
			scanf("%d",&x);
			pq2.push(x);
		}
		while(!pq1.empty() && !pq2.empty())
		{
			for(int i = 0;i < n && !pq1.empty() && !pq2.empty(); ++i)
			{
				a[i] = pq1.top();
				pq1.pop();
				b[i] = pq2.top();
				pq2.pop();
				if(a[i] >= b[i])
				{
					a[i] -= b[i];
					b[i] = 0;
				}
				if(b[i] > a[i])
				{
					b[i] -= a[i];
					a[i] = 0;
				}
			}
			for(int i = 0;i < n; ++i)
			{
				if(a[i])
				{
					pq1.push(a[i]);
				}
				if(b[i])
				{
					pq2.push(b[i]);
				}
				a[i] = b[i] = 0;
			}
		}
		if(pq1.empty() && pq2.empty())
		{
			printf("green and blue died\n");
		}
		else if(pq1.empty())
		{
			printf("blue wins\n");
			while(!pq2.empty())
			{
				printf("%d\n",pq2.top());
				pq2.pop();
			}
		}
		else
		{
			printf("green wins\n");
			while(!pq1.empty())
			{
				printf("%d\n",pq1.top());
				pq1.pop();
			}
		}
		if(T)
		{
			printf("\n");
		}
	}
	return 0;
}