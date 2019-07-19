#include <iostream>
#include <map>
using namespace std;
const int maxn = 2 * 1e5 + 5;
map<int,int> mp;
int a[maxn];
int main()
{
	int n;
	cin>>n;
	int v = 0,maxx = 0;
	for(int i = 1;i <= n; ++i)
	{
		cin>>a[i];
		mp[a[i]] = mp[a[i] - 1] + 1;
		int x = mp[a[i]];
		if(x > maxx)
		{
			maxx = x;
			v = a[i];
		}
	}
	v = v - maxx + 1;
	printf("%d\n",maxx);
	for(int i = 1;i <= n; ++i)
	{
		if(a[i] == v)
		{
			printf("%d ",i);
			v++;
		}
	}
	printf("\n");
	return 0;
}