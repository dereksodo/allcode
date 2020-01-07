#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 5e4 + 5;
struct Input{
	int w,x,d;
	bool operator <(const Input b)const
	{
		return x < b.x;
	}
	void scan()
	{
		scanf("%d%d%d",&w,&x,&d);
	}
}a[maxn];
int n,l;
void init()
{
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	freopen("meetings.in","r",stdin);
	freopen("meetings.out","w",stdout);
	scanf("%d%d",&n,&l);
	for(int i = 0;i < n; ++i)
	{
		a[i].scan();
	}
	sort(a,a + n);
}
int getTime()
{
	vector<int> lt,r;
	for(int i = 0;i < n; ++i)
	{
		if(a[i].d == -1)
		{
			lt.push_back(a[i].x);
		}
		else
		{
			r.push_back(a[i].x);
		}
	}
	vector< pair<int,int> > vp;
	for(int i = 0;i < lt.size(); ++i)
	{
		vp.push_back({lt[i],a[i].w});
	}
	for(int i = 0;i < r.size(); ++i)
	{
		vp.push_back({l - r[i],a[lt.size() + i].w});
	}
	sort(vp.begin(),vp.end());
	int tot = 0;
	for(int i = 0;i < vp.size(); ++i)
	{
		tot += vp[i].second;
	}
	for(int i = 0;i < vp.size(); ++i)
	{
		tot -= 2 * vp[i].second;
		if(tot <= 0)
		{
			return vp[i].first;
		}
	}
}
int main(int argc, char const *argv[])
{
	init();
	int t = getTime();
//	printf("OK\n");
	queue<int> r;
	int ans = 0;
	for(int i = 0;i < n; ++i)
	{
		if(a[i].d == -1)
		{
			while(!r.empty() && r.front() + 2 * t < a[i].x)
			{
				r.pop();
			}
			ans += r.size();
		}
		else
		{
			r.push(a[i].x);
		}
	}
	cout<<ans<<endl;
	return 0;
}
