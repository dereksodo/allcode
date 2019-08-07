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
const int maxn = 4e5 + 5;
int nxt[maxn];
set<int> s;
int n,siz;
int a[maxn],b[maxn],cnt;
int check(int p,int pos)
{
	int dif = p - pos + 1;
	int ct = 0;
	printf("dif = %d\n",dif);
	fflush(stdout);
	for(int now = 1;now < dif; now *= 2)
	{
		++ct;
	}
	if(n * ct <= siz * 8)
	{
		return 1;
	}
	return 0;
}
int main(int argc, char const *argv[])
{
	cin>>n>>siz;
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d",&a[i]);
		s.insert(a[i]);
	}
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n; ++i)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	for(set<int>::iterator iter = s.begin();iter != s.end(); ++iter)
	{
		b[cnt++] = *iter;
		printf("%d,",*iter);
	}
	printf("\n");
	int ret = 0x3f3f3f3f;
	for(int i = 0;i < cnt; ++i)
	{
		int l = i,r = cnt;
		while(l < r)
		{
			int mid = l + r >> 1;
			printf("******pos1 = %d,pos2 = %d\n",i,mid);
			if(check(mid,i))
			{
				l = mid + 1;
			}
			else
			{
				r = mid;
			}
		}
		int pos1 = lower_bound(a + 1,a + n + 1,b[i]) - a;
		int pos2 = upper_bound(a + 1,a + n + 1,l - 1) - a - 1;
		ret = min(ret,pos1 + n - pos2 - 1);
		printf("pos1 = %d,pos2 = %d,ret = %d\n",pos1,pos2,ret);
	}
	cout<<ret<<endl;
	return 0;
}