#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <set>
using namespace std;
const int maxn = 2 * 1e5 + 5;;
map<int,int> mp;
set<int> s;
int main()
{
	int n,k;
	cin>>n>>k;
	for(int i = 0;i < n; ++i)
	{
		int x;
		cin>>x;
		s.insert(x);
		mp[x]++;
	}
	if(k == 0)
	{
		if(mp[1] == 0)
		{
			printf("1\n");
		}
		else
		{
			printf("-1\n");
		}
		return 0;
	}
	int res = 0;
	for(set<int>::iterator iter = s.begin();iter != s.end(); ++iter)
	{
		res += mp[*iter];
		// printf("res = %d\n",res);
		if(res == k)
		{
			printf("%d\n",*iter);
			return 0;
		}
		else if(res > k)
		{
			break;
		}
	}
	printf("-1\n");
	return 0;
}