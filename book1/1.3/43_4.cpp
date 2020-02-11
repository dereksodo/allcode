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
const int n = 9;
const int maxn = 15;
int a[maxn][maxn];
int col[maxn][maxn];
int row[maxn][maxn];
int gt[maxn][maxn],getmax[maxn * maxn];
int getid2[maxn][maxn],getid[maxn][maxn],mp[maxn];
pair<int,int> p[maxn * maxn];
int p_len;
int ok(int x,int y,int value)
{
	return (col[x][value] == 0) 
			&& (row[y][value] == 0)
			&& (gt[getid[x][y]][value] == 0); 
}
void set_ok(int x,int y,int value,int flag)
{
	if(flag == 0)
	{
		col[x][value] = 0;
		row[y][value] = 0;
		gt[getid[x][y]][value] = 0;
		a[x][y] = 0;
	}
	else
	{
		col[x][value] = 1;
		row[y][value] = 1;
		gt[getid[x][y]][value] = 1;
		a[x][y] = value;
	}
}
void print_matrix()
{
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 1;j <= n; ++j)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
int ans = -1;
int ret = 0;
void init()
{
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 1;j <= n; ++j)
		{
			int x = i,y = j;
			int sum1 = 2;
			if(x <= 3)
			{
				sum1 = 0;
			}
			else if(x <= 6)
			{
				sum1 = 1;
			}
			int sum2 = 3;
			if(y <= 3)
			{
				sum2 = 1;
			}
			else if(y <= 6)
			{
				sum2 = 2;
			}
			getid[i][j] = sum1 * 3 + sum2;
			getid2[i][j] = n + 1 - max(abs(x - 5),abs(y - 5));
			int p = i * 9 - 9 + j;
			getmax[p] = getmax[p - 1];
			if(p <= 1)
			{
				getmax[p] += 10 * 9;
			}
			else if(p <= 9)
			{
				getmax[p] += 9 * 9;
			}
			else if(p <= 25)
			{
				getmax[p] += 8 * 9;
			}
			else if(p <= 49)
			{
				getmax[p] += 7 * 9;
			}
			else
			{
				getmax[p] += 6 * 9;
			}
		}
	}
}
void search(int value,int pos)
{
	// print_matrix();
	if(getmax[p_len - pos + 1] + value <= ans)
	{
		return;
	}
	if(pos == p_len + 1)
	{
		ans = max(ans,value);
		// print_matrix();
		// printf("ans = %d\n",ans + ret);
		return;
	}
	int x = p[pos].first;
	int y = p[pos].second;
	for(int i = 1;i <= n; ++i)
	{
		if(ok(x,y,i))
		{
			set_ok(x,y,i,1);
			search(value + getid2[x][y] * i,pos + 1);
			set_ok(x,y,i,0);
		}
	}
}
map<int,int> mp2;
int cmp(int a,int b)
{
	return mp2[a] < mp2[b];
}
int main(int argc, char const *argv[])
{
	init();
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 1;j <= n; ++j)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j] == 0)
			{
				mp2[i]++;
			}
			else
			{
				ret += getid2[i][j] * a[i][j];
				set_ok(i,j,a[i][j],1);
			}
		}
	}
	for(int i = 1;i <= n; ++i)
	{
		mp[i] = i;
	}
	sort(mp + 1,mp + 1 + n,cmp);
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 1;j <= n; ++j)
		{
			if(a[mp[i]][j] == 0)
			{
				p[++p_len] = make_pair(mp[i],j);
				// printf("%d %d\n",mp[i],j);
			}
		}
	}
	search(0,1);
	if(ans == -1)
	{
		printf("-1\n");
		return 0;
	}
	cout<<(ans + ret)<<endl;
	return 0;
}