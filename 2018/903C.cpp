#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(int a,int b)
{
	return a > b;
}
int main(int argc,char const *Argv[])
{
	int n;
	cin>>n;
	int a[n];
	bool flag[n];
	for(int i = 0;i < n; ++i)
	{
		cin>>a[i];
		flag[i] = 1;
	}
	sort(a,a + n,cmp);
	int ans = n;
	for(int i = 0;i < n; ++i)
	{
		for(int j = i + 1;j < n; ++j)
		{
			if(a[j] < a[i] && flag[j])
			{
				ans--;
				flag[j] = 0;
				break;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}