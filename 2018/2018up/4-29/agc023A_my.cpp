#include <iostream>
#include <map>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn];
long long sum[maxn];
map<long long,int> mp;
long long c(long long n)
{
	if(n < 2)
	{
		return 0;
	}
	return n * (n - 1) / 2;
}
int main()
{
	int n;
	cin>>n;
	for(int i = 1;i <= n; ++i)
	{
		cin>>a[i];
		sum[i] = a[i] + sum[i - 1];
		mp[sum[i]]++;
	}
	long long ans = 0;
	for(map<long long,int> ::iterator iter = mp.begin();iter != mp.end(); ++iter)
	{
		if(iter->first == 0)
		{
			ans += (c(iter->second)) + (iter->second);
		}
		else
		{
			if(iter->second >= 2)
			{
				ans += c(iter->second);
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}