#include <iostream>
using namespace std;
int a[20],b[20];
int dfs(int x[])
{

}
int main(int argc,char const *argv[])
{
	int n;
	cin>>n;
	int k;
	cin>>k;
	for(int i = 0;i < n; ++i)
	{
		cin>>a[i];
	}
	for(int i = 0;i < k; ++i)
	{
		cin>>b[i];
	}
	printf("%d\n",dfs(a));
	return 0;
} 