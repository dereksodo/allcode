#include <algorithm>
#include <iostream>
using namespace std;
int a[10];
int cnt(int n)
{
	int j = 0;
	int b = n;
	while(b)
	{
		a[j++] = b % 10;
		b /= 10;
	}
	for(int i = j;i < 4; ++i)
	{
		a[j++] = 0;
	}
	sort(a,a + j);
	int sum = 0;
	for(int i = 0;i < j; ++i)
	{
		sum = sum * 10 + a[i];
	}
	int sum2 = 0;
	reverse(a,a + j);
	for(int i = 0;i < j; ++i)
	{
		sum2 = sum2 * 10 + a[i];
	}
	printf("%d-%d=%d\n",sum2,sum,sum2 - sum);
	// getchar();
	return sum2 - sum;
}
int main()
{
	int n;
	cin>>n;
	while(n != 6174)
	{
		n = cnt(n);
	}
	return 0;
}