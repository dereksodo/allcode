#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
using namespace std;
long long f(long long p)
{
	int ret = 0;
	while(p)
	{
		ret += p % 10;
		p /= 10;
	}
	return ret;
}
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0);
	long long n,s;
	scanf("%lld %lld",&n,&s);
	long long ans = 0;
	for(long long i = s;i <= n && i <= (s + 1000); ++i)
	{
		if(i - f(i) >= s)
		{
			ans++;
		}
	}
	ans += n - min(n,s + 1000);
	cout<<ans<<endl;
	return 0;
}