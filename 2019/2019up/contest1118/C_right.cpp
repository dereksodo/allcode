#include <iostream>
#include <utility>
#include <vector>
#include <map>
using namespace std;
const int maxn = 1005;
int a[20][20];
vector< pair< int,pair<int,int> > > vp;
int mp[maxn];
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	for(int i = 0;i < n * n; ++i)
	{
		int x;
		scanf("%d",&x);
		mp[x]++;
	}
	for(int i = 0;i < (n + 1) / 2; ++i)
	{
		for(int j = 0;j < (n + 1) / 2; ++j)
		{
			if(i != n - i - 1 && j != n - j - 1)
			{
				vp.push_back({4,{i,j}});
			}
			else if((i != n - i - 1) ^ (j != n - j - 1))
			{
				vp.push_back({2,{i,j}});
			}
			else
			{
				vp.push_back({1,{i,j}});
			}
		}
	}
	for(int cur : {4,2,1})
	{
		int last = 1;
		for(auto it : vp)
		{
			if(it.first == cur)
			{
				int i = it.second.first;
				int j = it.second.second;
				while(last < maxn && mp[last] < cur)
				{
					last++;
				}
				if(last == maxn)
				{
					printf("NO\n");
					return 0;
				}
				a[i][j] = a[n - i - 1][j] = a[i][n - j - 1] = a[n - i - 1][n - j - 1] = last;
				mp[last] -= cur;
			}
		}
	}
	printf("YES\n");
	for(int i = 0;i < n; ++i)
	{
		for(int j = 0;j < n; ++j)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}