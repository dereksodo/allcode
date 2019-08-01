#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
const int maxn = 1e6 + 5;
typedef struct{
	int w;
	int h;
}envelope;
typedef struct{
	int w;
	int h;
	int index;
}xx;
int h[maxn],w[maxn];
bool cmp(xx a,xx b)
{
	if(a.w > b.w && a.h > b.h)
	{
		return 0;
	}
	return 1;
}
int main()
{
	envelope p[5010];
	int n,ws,hs;
	cin>>n>>ws>>hs;
	h[hs] = 1;
	w[ws] = 1;
	for(int i = 1;i <= n; ++i)
	{
		cin>>p[i].w>>p[i].h;
	}
	vector<xx> s;
	for(int i = 1;i <= n; ++i)
	{
		if(((p[i].w > ws && p[i].h > hs))
			&& (h[p[i].h] == 0 && w[p[i].w] == 0))
		{
			h[p[i].h] = 1;
			w[p[i].w] = 1;
			xx x;
			x.w = p[i].w;
			x.h = p[i].h;
			x.index = i;
			s.push_back(x);
		}
	}
	sort(s.begin(),s.end(),cmp);
	printf("%d\n",(int)s.size());
	xx last;
	last.index = -1;
	for(int i = 0;i < s.size(); ++i)
	{
		if(last.index == -1)
		{
			last.index = i;
			last.w = s[i].w;
			last.h = s[i].h;
		}
		else
		{
			if(s[i].w < last.w || s[i].h < last.h)
			{
				last.index = i;
				last.w = s[i].w;
				last.h = s[i].h;
				continue;
			}
		}
		printf("%d ",s[i].index);
		last.index = i;
		last.w = s[i].w;
		last.h = s[i].h;
	}
	printf("\n");
	return 0;
}