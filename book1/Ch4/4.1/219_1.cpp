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
const int maxn = 5e5 + 5;
int sum[maxn],n;
void update(int pos,int x)
{
	for(int i = pos;i <= n;i += i & (-i))
	{
		sum[i] += x;
	}
}
int query(int pos)
{
	int ret = 0;
	for(int i = pos;i;i -= i & (-i))
	{
		ret += sum[i];
	}
	return ret;
}
int main(int argc, char const *argv[])
{
	int m;
	scanf("%d%d\n",&n,&m);
	for(int i = 1;i <= m; ++i)
	{
		char type;
		scanf(" %c",&type);
		if(type == 'A')
		{
			int pos;
			scanf("%d",&pos);
			printf("%d\n",query(pos));
		}
		else if(type == 'B')
		{
			int pos,x;
			scanf("%d%d",&pos,&x);
			update(pos,x);
		}
		else if(type == 'C')
		{
			int pos,x;
			scanf("%d%d",&pos,&x);
			update(pos,-x);
		}
	}
	return 0;
}