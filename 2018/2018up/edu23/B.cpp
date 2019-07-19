#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <climits>
using namespace std;
const int maxn = 1e5 + 5;
map<long long,long long> mp;
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	long long a[n];
	for(int i = 0;i < n; ++i)
	{
		cin>>a[i];
		mp[a[i]]++;
	}
	sort(a,a + n);
	int x = a[0],y = a[1],z = a[2];
	if(z != y)
	{
		printf("%lld\n",mp[z]);
	}
	else if(z == y && x != z)
	{
		//									//A(2,2)
		printf("%lld\n",mp[z] * (mp[z] - 1) / 2);
	}
	else
	{
		//												//A(3,3)
		printf("%lld\n",mp[z] * (mp[z] - 1) * (mp[z] - 2) / 6);
	}
	return 0;
}