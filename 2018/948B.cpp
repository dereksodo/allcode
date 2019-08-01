#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
const long long maxn = 1e6 + 5;
bool prime[maxn];
long long ans[maxn];
bool is_prime(int x)
{
	if(x == 1)
	{
		return 0;
	}
	if(x == 2 || x == 3)
	{
		return 1;
	}
	if(x % 2 == 0 || x % 3 == 0)
	{
		return 0;
	}
	for(int i = 5;i <= sqrt(x); ++i)
	{
		if(x % i == 0)
		{
			return 0;
		}
	}
	return 1;
}
void fill_prime()
{
	for(int i = 1;i < maxn; ++i)
	{
		prime[i] = is_prime(i);
	}
}
long long small_prime(int x)
{
	for(long long i = x;i >= 0; --i)
	{
		if(prime[i])
		{
			return i;
		}
	}
	return 0;
}
int main(int argc,char const *argv[])
{
	fill_prime();
	long long x,y;
	// for(int i = 0;i < 10; ++i)
	// {
	// 	printf("prime[%d] = %d\n",i,prime[i]);
	// }
	for(long long i = 4;i < 30; ++i)
	{
		x = small_prime(i);
		while(x <= i)
		{
			x += x;
		}
		y = small_prime(x);
		while(y <= x)
		{
			y += y;
		}
		printf("x = %lld,y = %lld\n",x,y);
		if(!ans[y])
		{
			ans[y] = i;
		}
	}
	cin>>x;
	printf("%lld\n",ans[x]);
	return 0;
}