#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define long unsigned long long
const int maxn = 105;
long a[maxn];
bool is_ok[maxn];
map<long,bool> mp;
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	for(int i = 0;i < n; ++i)
	{
		cin>>a[i];
		if(a[i] % 3 == 0)
		{
			is_ok[a[i]] = 1;
		}
		mp[a[i]] = 1;
	}
	for(int i = 0;i < n; ++i)
	{
		long prev = a[i];
		bool flag = 1;
		vector<int> ans;
		ans.push_back(prev);
		while(1)
		{
			if(!mp[prev])
			{
				flag = 0;
				break;
			}
			if(is_ok[prev])
			{
				prev /= 3;
			}
			else
			{
				prev *= 2;
			}
			ans.push_back(prev);
		}
		printf("---\n");
		for(int i = 0;i < ans.size(); ++i)
		{
			printf("%d ",ans[i]);
		}
		printf("\n");
		if(flag)
		{
			for(int i = 0;i < ans.size(); ++i)
			{
				printf("%d ",ans[i]);
			}
			printf("\n");
			return 0;
		}
	}
	return 0;
}