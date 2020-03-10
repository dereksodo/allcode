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
const int maxn = 100;
const int mod = 2009;
int n,m,t;
struct mat{
	int r,c;
	int a[maxn + 5][maxn + 5];
	mat(){};
	mat(const int &s,const int &b):r(s),c(b)
	{
		memset(a,0x00,sizeof(a));
	}
	void clear()
	{
		memset(a,0x00,sizeof(a));
		for(int i = 1;i <= r; ++i)
		{
			a[i][i] = 1;
		}
	}
	mat operator *(const mat &b)
	{
		mat res(r,b.c);
		for(int i = 1;i <= r; ++i)
		{
			for(int j = 1;j <= b.c; ++j)
			{
				for(int k = 1;k <= c; ++k)
				{
					res.a[i][j] += a[i][k] * b.a[k][j];
				}
				res.a[i][j] %= mod;
			}
		}
		return res;
	}
	mat operator ^(int p)
	{
		mat res(r,c);
		res.clear();
		mat x = *this;
		for(;p;p >>= 1,x = x * x)
		{
			if(p & 1)
			{
				res = res * x;
			}
		}
		return res;
	}
}f;
int pos(int u,int i)
{
	return u + i * n;
}
int main(int argc, char const *argv[])
{
	scanf("%d%d",&n,&t);
	m = n * 9;
	f = mat(m,m);
	int x;
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 1;j < 9; ++j)
		{
			f.a[pos(i,j)][pos(i,j - 1)] = 1;
		}
		for(int j = 1;j <= n; ++j)
		{
			scanf("%1d",&x);
			if(x)
			{
				f.a[i][pos(j,x - 1)] = 1;
			}
		}
	}
	f = f ^ t;
	printf("%d\n",f.a[1][n]);
	return 0;
}