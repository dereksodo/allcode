#include <iostream>
using namespace std;
void print_x(int x)
{
	printf("     %d\n",x);
}
int main()
{
	int n;
	cin>>n;
	int a[n],b[n];
	for(int i = 0;i < n; ++i)
	{
		cin>>a[i];
	}
	for(int i = 0;i < n; ++i)
	{
		cin>>b[i];
	}
	for(int i = 0;i < n; ++i)
	{
		for(int j = 0;j < n; ++j)
		{
			if(a[i] != b[i] && a[j] != b[j] && i != j)
			{
				for(int cnt = 0;cnt < i; ++cnt)
				{
					printf("%d ",a[cnt]);
				}
				printf("%d ",b[i]);
				for(int cnt = i + 1;cnt < j; ++cnt)
				{
					printf("%d ",a[cnt]);
				}
				printf("%d ",a[j]);
				for(int cnt = j + 1;cnt < n; ++cnt)
				{
					printf("%d ",a[cnt]);
				}
				cout<<endl;
				return 0;
			}
		}
	}
	return 0;
}