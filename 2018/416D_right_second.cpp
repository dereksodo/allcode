#include <iostream>
using namespace std;
long long a[200005],d;
int n,ans;
int main(int argc,char const *argv[])
{
	cin>>n;
	int i,j;
	for(i = 1;i <= n; ++i)
	{
		cin>>a[i];
	}
	int k = 1;
	while(k <= n)
	{
		ans++;
		for(i = k;a[i] == -1; ++i);
		for(j = i + 1;a[j] == -1; ++j);
		if(j > n)
		{
			break;
		}
		d = (a[j] - a[i]) / (j - i);
		if((a[j] - a[i]) % (j - i) || a[j] - d * (j - k) <= 0)
		{
			k = j;
			continue;
		}
		k = j + 1;
		while(k <= n && a[j] + d * (k - j) > 0 && (a[k] == -1 || a[k] == a[j] + d * (k - j)))
		{
			++k;
		}
	}
	cout<<ans<<endl;
	return 0;
}