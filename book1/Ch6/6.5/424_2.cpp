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
const int maxn = 5050;
int f[maxn][30],n,m,k;
int nxt[maxn],mth[maxn][50];
char md[maxn];
void kmp()
{
	nxt[0] = -1;
	for(int i = 1;i <= m; ++i)
	{
		int j = nxt[i - 1];
		while(j != -1 && md[j + 1] != md[i])
		{
			j = nxt[j];
		}
		nxt[i] = j + 1;
	}
	nxt[0] = 0;
	for(int i = 0;i < m; ++i)
	{
		for(int j = '0';j <= '9'; ++j)
		{
			int tmp = i;
			while(md[tmp + 1] != j && tmp > 0)
			{
				tmp = nxt[tmp];
			}
			if(md[tmp + 1] == j)
			{
				++tmp;
			}
			if(tmp < m)
			{
				mth[i][tmp]++;
			}
		}
	}
}
struct mat{
	int a[23][23];
	mat()
	{
		memset(a,0x00,sizeof(a));
	}
	mat operator *(const mat &b)
	{
		mat ret;
		for(int i = 0;i < m; ++i)
		{
			for(int j = 0;j < m; ++j)
			{
				for(int p = 0;p < m; ++p)
				{
					ret.a[i][j] += a[i][p] * b.a[p][j];
					ret.a[i][j] %= k;
				}
			}
		}
		return ret;
	}
}m1,m2;
mat mypow(mat a,int p)
{
	mat ret;
	for(int i = 0;i <= m; ++i)
	{
		ret.a[i][i] = 1;
	}
	for(;p;p >>= 1,a = a * a)
	{
		if(p & 1)
		{
			ret = ret * a;
		}
	}
	return ret;
}
int main(int argc, char const *argv[])
{
	scanf("%d%d%d",&n,&m,&k);
	scanf("%s",md + 1);
	kmp();
	m1.a[0][0] = 1;
	for(int i = 0;i <= m; ++i)
	{
		for(int j = 0;j <= m; ++j)
		{
			m2.a[i][j] = mth[i][j];
		}
	}
	m2 = mypow(m2,n);
	m1 = m1 * m2;
	int ans = 0;
	for(int i = 0;i < m; ++i)
	{
		(ans += m1.a[0][i]) %= k;
	}
	printf("%d\n",ans);
	return 0;
}