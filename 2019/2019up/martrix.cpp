#include <iostream>
#include <cstring>
#include <cstdlib>
#include <set>
#include <vector>
#include <map>
#include <cstdio>
#include <utility>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
using namespace std;
static const int maxn = 1000;
int a[maxn][maxn];
// #define DEBUG
void MARTRIX_ROTATE_LEFT(int n)
{
	for(int i = 0;i < n; ++i)
	{
		for(int j = i + 1;j < n; ++j)
		{
			swap(a[i][j],a[j][i]);
		}
	}
	for(int i = 0;i < n / 2; ++i)
	{
		swap(a[i],a[n - i - 1]);
	}
}
void MARTRIX_ROTATE_RIGHT(int n)
{
	for(int i = 0;i < n; ++i)
	{
		for(int j = 0;j < n - i; ++j)
		{
			swap(a[i][j],a[n - j - 1][n - i - 1]);
		}
	}
	for(int i = 0;i < n / 2; ++i)
	{
		swap(a[i],a[n - i - 1]);
	}
}
int b[maxn][maxn];
void MARTRIX_ROTATE_LEFT2(int n)
{
	for(int i = 0;i < n; ++i)
	{
		for(int j = 0;j < n; ++j)
		{
			b[n - j - 1][i] = a[i][j];
		}
	}
}
void MARTRIX_ROTATE_RIGHT2(int n)
{
	for(int i = 0;i < n; ++i)
	{
		for(int j = 0;j < n; ++j)
		{
			b[j][n - i - 1] = a[i][j];
		}
	}
}
int main(int argc, char const *argv[])
{
	#ifdef DEBUG
		freopen("in.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	for(int i = 0;i < n; ++i)
	{
		for(int j = 0;j < n; ++j)
		{
			scanf("%d",a[i] + j);
		}
	}
	MARTRIX_ROTATE_RIGHT2(n);
	for(int i = 0;i < n; ++i)
	{
		for(int j = 0;j < n; ++j)
		{
			printf("%d ",b[i][j]);
		}
		cout<<endl;
	}
	return 0;
}