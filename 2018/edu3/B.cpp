#include <iostream>
using namespace std;
int a[15];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i = 0;i < n; ++i)
	{
		int x;
		cin>>x;
		a[x]++;
	}
	int sum = 0;
	for(int i = 1;i <= m; ++i)
	{
		for(int j = i + 1;j <= m; ++j)
		{
			sum += a[i] * a[j];
		}
	}
	printf("%d\n",sum);
	return 0;
}