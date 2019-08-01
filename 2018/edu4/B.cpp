#include <iostream>
#import <cmath>
using namespace std;
const int maxn = 2 * 1e5 + 5;
int a[maxn];
int main()
{
	int n;
	cin>>n;
	for(int i = 1;i <= n; ++i)
	{
		int x;
		cin>>x;
		a[x] = i;
	}
	long long ret = 0;
	for(int i = 2;i <= n; ++i)
	{
		ret += abs(a[i] - a[i - 1]);
	}
	printf("%lld\n",ret);
	return 0;
}