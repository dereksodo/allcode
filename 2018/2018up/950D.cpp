#include <iostream>
using namespace std;
int main()
{
	long long n,q;
	cin>>n>>q;
	while(q--)
	{
		long long x;
		cin>>x;
		while(x % 2 == 0)
		{
			x += n - (x / 2);
		}
		printf("%lld\n",(x + 1) / 2);
	}
	return 0;
}