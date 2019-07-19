#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i = 0;i < n; ++i)
	{
		cin>>a[i];
	}
	int ans = 0;
	for(int i = 0;i < n; ++i)
	{
		ans = max(ans,min(1000000 - a[i],a[i] - 1));
	}
	printf("%d\n",ans);
	return 0;
}