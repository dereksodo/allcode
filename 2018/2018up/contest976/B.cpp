#include <iostream>
using namespace std;
long long n,m,times;
long long x,y;
pair<long long,long long> solve2(long long &x,long long &y,long long &times)
{
	printf("times = %lld\n",times);
	if(times <= 0)
	{
		return make_pair(x,y);
	}
	if(times < m)
	{
		y -= times;
	}
	else if(times == m)
	{
		x -= 2,y -= 2;
	}
	else if(times > m)
	{
		times -= m;
		x += 20,y += times;
	}
	return make_pair(x,y);
}
pair<long long,long long> solve(long long &x,long long &y,long long &times)
{
	if(times < n)
	{
		x = 1,y = times + 1;
		return make_pair(x,y);
	}
	else if(times >= n && times <= n + m - 2)
	{
		x = n,y = times - m + 1;
		return make_pair(x,y);
	}
	else
	{
		times -= (n + m - 2);
		long long cur = (times / (2 * m - 2));
		printf("cur = %lld\n",cur);
		if(cur * 2 - 1 >= 0)
		{
			x = cur * 2 - 1;
		}
		else
		{
			x = n;
		}
		y = m;
		times -= cur * (2 * m - 2);
		printf("x = %lld,y = %lld\n",x,y);
		printf("times = %lld\n",times);
		if(x == n)
		{
			if(times <= 0)
			{
				return make_pair(x,y);
			}
			if(times == 1)
			{
				x--;
			}
			else if(times < m)
			{
				x--,y -= times - 1;
			}
			else if(times == m)
			{
				x -= 2,y -= m - times + 2;
			}
			else if(times > m)
			{
				times -= m;
				x -= 2,y += times;
			}
			return make_pair(x,y);
		}
		else
		{
			return solve2(x,y,times);
		}
	}
}
int main()
{
	cin>>n>>m>>times;
	pair<long long,long long> p = solve(n,m,times);
	printf("%lld %lld\n",p.first,p.second);
	return 0;
}