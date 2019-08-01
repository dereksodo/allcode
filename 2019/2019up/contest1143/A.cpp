#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n] = {0};
	int s = 0;
	for(int i = 0;i < n; ++i)
	{
		scanf("%d",&a[i]);
		if(a[i])
		{
			s++;
		}
	}
	int s2 = n - s;
	for(int i = 0;i < n; ++i)
	{
		if(s == 0 || s2 == 0)
		{
			printf("%d\n",i);
			return 0;
		}
		if(a[i])
		{
			s--;
		}
		else
		{
			s2--;
		}
	}
	return 0;
}