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
const int maxn = 5;
const int inf = 0x3f3f3f3f;
struct node{
	int x,y,z,dep;
	void read()
	{
		scanf("%d%d%d",&x,&y,&z);
		dep = 0;
		if(x > y)
		{
			swap(x,y);
		}
		if(x > z)
		{
			swap(x,z);
		}
		if(y > z)
		{
			swap(y,z);
		}
	}
	bool operator ==(const node &b)const
	{
		return x == b.x && y == b.y && z == b.z;
	}
}a,b,p,q;
node lca(node now,int step)
{
	for(int k = 0;step;now.dep += k)
	{
		int l = now.y - now.x;
		int r = now.z - now.y;
		if(l == r)
		{
			return now;
		}
		if(l > r)
		{
			k = min(step,(l - 1) / r);
			now.y -= r * k;
			now.z -= r * k;
			step -= k;
		}
		else
		{
			k = min(step,(r - 1) / l);
			now.x += k * l;
			now.y += k * l;
			step -= k;
		}
	}
	return now;
}
int main(int argc, char const *argv[])
{
	a.read();
	b.read();
	p = lca(a,inf);
	q = lca(b,inf);
	if(!(p == q))
	{
		printf("NO\n");
		return 0;
	}
	else
	{
		printf("YES\n");
	}
	if(p.dep < q.dep)
	{
		swap(a,b);
		swap(p,q);
	}
	a = lca(a,p.dep - q.dep);
	int l = 0,r = inf;
	while(l <= r)
	{
		int mid = l + r >> 1;
		if(lca(a,mid) == lca(b,mid))
		{
			r = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
	}
	printf("%d\n",p.dep - q.dep + l * 2);
	return 0;
}