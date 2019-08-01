#include <iostream>
using namespace std;
int main()
{
	long long n,m,times,x = 0,y = 0;
	cin>>n>>m>>times;
	if(times < n)
	{
		x = 1,y = times + 1;
	}
	else if(times >= n && times <= n + m - 2)
	{
		x = n,y = times - m + 2;
	}
	else
	{
		times -= (n + m - 2);
		long long cur = (times / (2 * m - 2));
		printf("cur = %lld\n",cur);
		if(cur * 2 - 1 >= 0)
		{
			x = cur * 2 - 1;
			times -= max(1ll,(cur - 1)) * (2 * m - 2) + 1;
		}
		else
		{
			x = n - 1;
			times -= 1;
		}
		y = m;
		printf("x = %lld,y = %lld\ntimes = %lld\n",x,y,times);
		if(times <= 0)
		{
			printf("%lld %lld\n",x,y);
			return 0;
		}
		else if(times < m)
		{
			y -= times;
		}
		else if(times == m)
		{
			x -= 2,y -= 2;
		}
		else if(times > m)
		{
			times %= m;
			x -= (times / m),y = 3 + times;
		}
	}
	printf("%lld %lld\n",x,y);
	return 0;
}