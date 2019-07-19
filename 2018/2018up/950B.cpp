#include <iostream>
#include <cstring>
using namespace std;
const int SIZE = 1e5 + 60;
int a[SIZE],b[SIZE];
int main(int argc,char const *argv[])
{
	int n,m;
	cin>>n>>m;
	for(int i = 0;i < n; ++i)
	{
		cin>>a[i];
	}
	for(int i = 0;i < m; ++i)
	{
		cin>>b[i];
	}
	int ansa = a[0],ansb = b[0];
	int ans = 0;
	for(int i = 0,j = 0;;)
	{
		if(ansa == ansb)
		{
			ans++;
			ansa = a[i + 1];
			i++;
			ansb = b[j + 1];
			j++;
		}
		if(ansa < ansb)
		{
			ansa += a[i + 1];
			i++;
		}
		if(ansb < ansa)
		{
			ansb += b[j + 1];
			j++;
		}
		if(i >= n || j >= m)
		{
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}