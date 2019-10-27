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
const int maxn = 8005;
int n,q,p;
struct BIT{
	unsigned char tr[maxn][maxn];
	BIT()
	{
		memset(tr,0x00,sizeof(tr));
	}
	int lowbit(int x)
	{
		return x & -x;
	}
	void add(int x,int y,int num)
	{
		// num %= p;
		for(int i = x;i <= n;i += lowbit(i))
		{
			for(int j = y;j <= n; j += lowbit(j))
			{
				int x = int(tr[i][j]) + num;
				x %= p;
				tr[i][j] = x;
			}
		}
	}
	int query(int x,int y)
	{
		int res = 0;
		for(int i = x;i >= 1;i -= lowbit(i))
		{
			for(int j = y;j >= 1;j -= lowbit(j))
			{
				res += int(tr[i][j]);
				res %= p;
			}
		}
		return res;
	}
}A,Ai,Aj,Aij;
int read()
{
	char c;
	while((c = getchar()) < 48 || c > 57);
	int res = c - 48;
	while((c = getchar()) > 47 && c < 58)
	{
		res = ((res << 3) + (res << 1)) + c - 48;
	}
	return res;
}
int Ans(int x,int y)
{
	int ret = (1ll * A.query(x,y) * (x * y + x + y + 1) % p + p
			- 1ll * Ai.query(x,y) * (y + 1) % p + p
			- 1ll * Aj.query(x,y) * (x + 1) % p
			+ 1ll * Aij.query(x,y)) % p;
	return ret;
}
void Add(int x,int y,int num)
{
	A.add(x,y,1ll * num % p);
	Ai.add(x,y,1ll * x * num % p);
	Aj.add(x,y,1ll * y * num % p);
	Aij.add(x,y,1ll * num * x % p * y % p);
}
int main(int argc, char const *argv[])
{
	n = read(),q = read(),p = read();
	int r = 0;
	while(q--)
	{
		int type,w,x,y,z;
		type = read(),w = read(),x = read(),y = read(),z = read();
		int a = (w + r) % n;
		int b = (x + r) % n;
		int c = (y + r) % n;
		int d = (z + r) % n;
		if(b < a)
		{
			swap(a,b);
		}
		if(d > c)
		{
			swap(c,d);
		}
		// printf("c = %d,d = %d\n",c,d);
		//x1,y1,x2,y2
		//a  d  b  c
		a++,b++,c++,d++;
		int ta = a,tb = b,tc = c,td = d;
		a = min(ta,tb);
		b = min(tc,td);
		c = max(ta,tb);
		d = max(tc,td);
		// printf("a = %d,b = %d,c = %d,d = %d\n",a,b,c,d);
		if(type == 1)
		{
			Add(a,b,1);
			Add(a,d + 1,p - 1);
			Add(c + 1,b,p - 1);
			Add(c + 1,d + 1,1);
		}
		else
		{
			int now = (Ans(c,d) - Ans(a - 1,d) + p - Ans(c,b - 1) + p + Ans(a - 1,b - 1)) % p;
			r += now;
			printf("%d\n",now);
		}
	}
	return 0;
}