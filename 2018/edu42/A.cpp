#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n];
	int sum = 0;
	for(int i = 0;i < n; ++i)
	{
		cin>>a[i];
		sum += a[i];
	}
	int now_ret = 0;
	int res = (sum % 2 == 0) ? sum / 2 : (sum + 1) / 2;
	for(int i = 0;i < n; ++i)
	{
		now_ret += a[i];
		if(now_ret >= res)
		{
			printf("%d\n",i + 1);
			return 0;
		}
	}
	return 0;
}