#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 5e5 + 5;
typedef pair<int,int> pii;
int n;
int used[maxn],a[maxn];
int l[maxn],r[maxn];
int ans[maxn];
pii t[maxn << 2];
void update(int x,int l,int r,int g,int y)
{
	if(l == r)
	{
		t[x] = {y,a[l]};
		return;
	}
	int mid = l + r >> 1;
	if(g <= mid)
	{
		update(x << 1,l,mid,g,y);
	}
	else
	{
		update(x << 1 | 1,mid + 1,r,g,y);
	}
	t[x] = max(t[x << 1],t[x << 1 | 1]);
}
pii query(int x,int l,int r,int ql,int qr)
{
	if(ql > qr)
	{
		return {0,0};
	}
	if(l == ql && r == qr)
	{
		return t[x];
	}
	int mid = l + r >> 1;
	return max(query(x << 1,l,mid,ql,min(mid,qr)),query(x << 1 | 1,mid + 1,r,max(mid + 1,ql),qr));
}
int main(int argc, char const *argv[])
{
	cin>>n;
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d",&a[i]);
		l[i] = used[a[i]];
		used[a[i]] = i;
	}
	for(int i = 1;i < maxn; ++i)
	{
		used[i] = n + 1;
	}
	vector< pair<int,pii> > v;
	for(int i = n;i > 0; --i)
	{
		r[i] = used[a[i]];
		used[a[i]] = i;
		v.push_back({l[i],{r[i],i}});
	}
	sort(v.begin(),v.end());
	int q;
	cin>>q;
	vector< pair<int,pii> > u;
	for(int i = 1;i <= q; ++i)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		u.push_back({l,{r,i}});
	}
	sort(u.begin(),u.end());
	int cnt = 0;
	for(auto cur : u)
	{
		while(cnt < v.size() && v[cnt].first < cur.first)
		{
			update(1,1,n,v[cnt].second.second,v[cnt].second.first);
			cnt++;//***
		}
		pii ret = query(1,1,n,cur.first,cur.second.first);
		if(ret.first > cur.second.first)
		{
			ans[cur.second.second] = ret.second;
		}
	}
	for(int i = 1;i <= q; ++i)
	{
		printf("%d\n",ans[i]);
	}
	return 0;
}