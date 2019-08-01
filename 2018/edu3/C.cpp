#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 5;
int n,v[maxn];
int a,b;
int main()
{
	int sum = 0;
	cin>>n;
	for(int i = 0;i < n; ++i)
	{
		cin>>v[i];
		sum += v[i];
	}
	int ave = sum / n;
	sort(v,v + n);
	for(int i = 0;i < n; ++i)
	{
		a += max(0,ave - v[i]);
	}
	for(int i = n - 1;i >= 0; --i)
	{
		b += max(0,v[i] - ave - 1);
	}
	printf("%d\n",max(a,b));
	return 0;
}