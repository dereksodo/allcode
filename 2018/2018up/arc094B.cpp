#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int main()
{
	long long q;
	cin>>q;
	vector<int> v;
	while(q--)
	{
		long long a,b,ans = 0;
		cin>>a>>b;
		if(a > b)
		{
			swap(a,b);
		}
		if(a == b || a == (b - 1))
		{
			ans = 2 * (a - 1);
		}
		else
		{
			long long x = floor(sqrt(a * b));
			if(x * x == a * b)
			{
				x--;
			}
			if(x * (x + 1) >= a * b)
			{
				ans = 2 * (x - 1);
			}
			else
			{
				ans = 2 * x - 1;
			}
		}
		v.push_back(ans);
	}
	for(int i = 0;i < v.size(); ++i)
	{
		printf("%d\n",v[i]);
	}
	return 0;
}