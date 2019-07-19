#include <iostream>
#include <map>
#include <cstring>
using namespace std;
map<int,int> mp;
const int maxn = 2e5 + 5;
int n,a[maxn],par[maxn],d[maxn];
void show(int index)
{
	if(~par[index])
	{
		show(par[index]);
	}
	cout<<index + 1<<" ";
}
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	memset(par,-1,sizeof(par));
	for(int i = 0;i < n; ++i)
	{
		cin>>a[i];
		if(mp.count(a[i] - 1))
		{
			d[i] = d[mp[a[i] - 1]] + 1;
			par[i] = mp[a[i] - 1];
		}
		else
		{
			d[i] = 1;
		}
		mp[a[i]] = i;
	}
	int maxx = 0;
	for(int i = 0;i < n; ++i)
	{
		maxx = max(maxx,d[i]);
	}
	cout<<maxx<<endl;
	for(int i = 0;i < n; ++i)
	{
		if(maxx == d[i])
		{
			show(i);
			cout<<"\n";
			break;
		}
	}
	return 0;
}