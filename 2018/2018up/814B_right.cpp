#include <iostream>
using namespace std;
int a[1010],b[1010],used[1010],cnt1 = 0,cnt2 = 0;
int main()
{
	int n;
	cin>>n;
	for(int i = 1;i <= n; ++i)
	{
		cin>>a[i];
		++used[a[i]];
	}
	for(int i = 1;i <= n; ++i)
	{
		cin>>b[i];
		if(a[i] != b[i])
		{
			if(!cnt1)
			{
				cnt1 = i;
			}
			else
			{
				cnt2 = i;
			}
		}
	}
	if(cnt2)
	{
		if(used[a[cnt1]] == 2 && !used[b[cnt1]])
		{
			a[cnt1] = b[cnt1];
		}
		else
		{
			a[cnt2] = b[cnt2];
		}
	}
	else
	{
		int i = 1;
		for(;used[i]; ++i);
		a[cnt1] = i;
	}
	for(int i = 1;i <= n; ++i)
	{
		printf("%d ",a[i]);
	}
	cout<<endl;
	return 0;
}