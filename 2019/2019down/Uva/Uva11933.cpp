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
// #define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
int a[50],b[50];
int main(int argc, char const *argv[])
{
	int n;
	while(cin>>n && n)
	{
		int now = 0,alen = 0,blen = 0;
		int n2 = n;
		memset(a,0x00,sizeof(a));
		memset(b,0x00,sizeof(b));
		int cnt = 0;
		while(n2)
		{
			if(n2 & 1)
			{
				if(now % 2 == 0)
				{
					a[cnt] = 1;
					alen = cnt;
				}
				else
				{
					b[cnt] = 1;
					blen = cnt;
				}
				now++;
			}
			n2 >>= 1;
			cnt++;
		}
		int ret = 0;
		for(int i = alen;i >= 0; --i)
		{
			debug("a[%d] = %d\n",i,a[i]);
			ret = (ret << 1) + a[i];
			debug("ret = %d\n",ret);
		}
		printf("%d ",ret);
		ret = 0;
		for(int i = blen;i >= 0; --i)
		{
			debug("b[%d] = %d\n",i,b[i]);
			ret = (ret << 1) + b[i];
			debug("ret = %d\n",ret);
		}
		printf("%d\n",ret);
	}
	return 0;
}