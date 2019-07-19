#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 105;
int a[maxn];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i = 0;i < n; ++i)
	{
		cin>>a[i];
	}
	sort(a,a + n);
	int sum = 0;
	for(int i = n - 1;i >= 0; --i)
	{
		if(sum + a[i] >= m)
		{
			printf("%d\n",n - i);
			return 0;
		}
		sum += a[i];
	}
	return 0;
}