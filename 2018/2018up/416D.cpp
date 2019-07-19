#include <iostream>
using namespace std;
int main(int argc,char const *Argv[])
{
	int n;
	cin>>n;
	int a[n];
	for(int i = 0;i < n; ++i)
	{
		cin>>a[i];
	}
	if(n == 1)
	{
		printf("1\n");
		return 0;
	}
	if(n == 2)
	{
		if(a[0] != a[1])
		{
			printf("1\n");
		}
		else
		{
			printf("2\n");
		}
	}
	bool flag = 1;
	int k = 0;
	int pos = 0;
	int ans = 1;
	for(int i = 0;i < n; ++i)
	{
		if(a[i] != -1 && flag)
		{
			if(i == n - 1)
			{
				break;
			}
			flag = 0;
			pos = i;
			int j = i + 1;
			for(;j < n; ++j)
			{
				if(a[j] != -1)
				{
					break;
				}
			}
			if((a[i] - a[j]) % (j - i) != 0)
			{
				ans++;
			}
			k = (a[i] - a[j]) / (j - i);
			// printf("a[%d - 1] = %d,a[%d] = %d,k = %d,j = %d\n",i,a[i - 1],i,a[i],k,j);
			if(a[i - 1] == -1)
			{
				if(k < 0 && a[i] + k <= 0)
				{
					++ans;
				}
				else if(k > 0 && a[i] - k <= 0)
				{
					++ans;
				}
			}
			if(a[j + 1] == -1)
			{
				if(k < 0 && a[j] + k <= 0)
				{
					++ans;
				}
				else if(k > 0 && a[j] - k <= 0)
				{
					++ans;
				}
			}
			i = j;
		}
		else if(a[i] != -1)
		{
			if(a[i] != a[pos] - ((i - pos) * k))
			{
				ans++;
				flag = 1;
				--i;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}