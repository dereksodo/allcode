#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn];
int main()
{
	int n,k;
	cin>>n>>k;
	n--;
	for(int i = 1;i <= n; ++i)
	{
		cin>>a[i];
		a[i] += a[i - 1];//前缀和加快速度
	}
	int ans = 1e9;
	for(int i = 0;i <= n - k; ++i)
	{
		ans = min(ans,a[i + k] - a[i]);
	}
	printf("%d\n",ans);
	return 0;
}