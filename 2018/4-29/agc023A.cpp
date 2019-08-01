#include <iostream>
#include <map>
using namespace std;
map<long long,int> mp;
int main()
{
	int n;
	cin>>n;
	long long ret = 0,sum = 0;
	mp[0] = 1;
	for(int i = 0;i < n; ++i)
	{
		long long a;
		cin>>a;
		sum += a;
		ret += mp[sum];
		mp[sum]++;
	}
	printf("%lld\n",ret);
	return 0;
}