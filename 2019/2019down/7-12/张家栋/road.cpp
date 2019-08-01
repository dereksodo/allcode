#include <bits/stdc++.h>
using namespace std;
const long long maxn = 100005;
long long a[maxn];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long sum = 0;
	int n;
	cin>>n;
	for(int i = 0;i < n; ++i)
	{
		scanf("%lld",&a[i]);
	}
	sum = a[0];
	for(int i = 1;i < n; ++i)
	{
		if(a[i] > a[i - 1])
		{
			sum += a[i] - a[i - 1];
		}
	}
	cout<<sum<<endl;
	return 0;
}
