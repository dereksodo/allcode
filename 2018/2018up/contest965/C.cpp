#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	long long n,k,m,d;
	cin>>n>>k>>m>>d;
	long long maxn = 0;
	long long cur = 1;
	for(int i = 1;i <= d; ++i)
	{
		maxn = max(maxn,i * min(n / cur,m));
		cur += k;
		if(cur > n)
		{
			break;
		}
	}
	printf("%lld\n",maxn);
	return 0;
}