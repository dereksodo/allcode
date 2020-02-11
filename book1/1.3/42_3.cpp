#pragma G++ optimize(3)
#pragma GCC optimize(3)
#include <iostream>
using namespace std;
typedef long long ll;
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
const int maxn = 1e5 + 5;
int prime[maxn],a[maxn],plen;
int s;
const int mxn = 15;
int mat[mxn][mxn];
int ok[maxn],ocnt;
int begi[maxn],ed[maxn];
int kk[6] = {1,10,100,1000,10000,100000};
int fg;
int L[mxn],R[mxn];
int dig1,dig2;
inline int sums(int k)
{
	int ret = 0;
	while(k)
	{
		ret += k % 10;
		k /= 10;
	}
	return ret;
}
inline void init()
{
	plen = 0;
	for(int i = 2;i < maxn; ++i)
	{
		if(!a[i])
		{
			prime[plen++] = i;
		}
		for(int j = 0;j < plen && i * prime[j] < maxn; ++j)
		{
			a[i * prime[j]] = 1;
			if(i % prime[j] == 0)
			{
				break;
			}
		}
	}
	for(int j = 0;prime[j] < 100000; ++j)
	{
		if(prime[j] >= 10000 && sums(prime[j]) == s)
		{
			int i = prime[j];
			ed[i % 10000] = ed[i % 1000] = ed[i % 100] = ed[i % 10] = ed[i] = 1;
			begi[i / 10000] = begi[i / 1000] = begi[i / 100] = begi[i / 10] = begi[i] = 1;
		}
	}
}
inline void print()
{
	for(int i = 1;i <= 5; ++i)
	{
		printf("%d\n",L[i]);
	}
	printf("\n");
}
inline void dfs(int x,int y)
{
	if(y == 6)
	{
		y = 1;
		x += 1;
	}
	if(x == 6)
	{
		fg = 1;
		print();
		return;
	}
	else
	{
		int beg = 0,endd = 9;
		if(y == 1)
		{
			beg = 1;
			int t = 0;
			for(int i = 1;i < x; ++i)
			{
				t += mat[i][1];
			}
			endd = min(9,s - t - (5 - x));
		}
		if(y == 5)
		{
			beg = endd = s - mat[x][1] - mat[x][2] - mat[x][3] - mat[x][4];
			if(beg < 0 || beg > 10 || (!(beg & 1)))
			{
				return;
			}
		}
		else if(x == 5)
		{
			beg = endd = s - mat[1][y] - mat[2][y] - mat[3][y] - mat[4][y];
			if(beg < 0 || beg > 10 || (!(beg & 1)))
			{
				return;
			}
		}
		for(int i = beg;i <= endd; ++i)
		{
			int k1 = begi[L[x] * 10 + i];
			int k2 = begi[R[y] * 10 + i];
			int k3 = ((x != y) || (x == y && begi[dig1 * 10 + i]));
			int k4 = ((x + y != 6) || (x + y == 6 && ed[dig2 + i * kk[x - 1]]));
			if(!(k1 && k2 && k3 && k4))
			{
				continue;
			}
			int a1 = L[x],a2 = R[y],a3 = dig1,a4 = dig2;
			L[x] = L[x] * 10 + i;
			R[y] = R[y] * 10 + i;
			if(x == y)
			{
				dig1 = dig1 * 10 + i;
			}
			if(x + y == 6)
			{
				dig2 = dig2 + i * kk[x - 1];
			}
			mat[x][y] = i;
			dfs(x,y + 1);
			L[x] = a1;
			R[y] = a2;
			dig1 = a3;
			dig2 = a4;
		}
	}
}
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0);
	int ks;
	scanf("%d%d",&s,&ks);
	init();
	mat[1][1] = ks;
	L[1] = R[1] = dig1 = ks;
	dfs(1,2);
	if(fg == 0)
	{
		printf("NONE\n");
	}
	return 0;
}