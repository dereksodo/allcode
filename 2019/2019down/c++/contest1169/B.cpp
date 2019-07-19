#include <iostream>
#include <cstring>
#include <cstdlib>
#include <set>
#include <vector>
#include <map>
#include <cstdio>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <cassert>
#include <climits>
using namespace std;
typedef long long ll;
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
const int maxn = 3e5 + 5;
pair<int,int> a[maxn];
map<int,int> mp,mp2;
vector<int> v;
vector<int> s[maxn];
int n,m;
void p()
{
	printf("YES\n");
	exit(0);
}
void geta(int x)
{
	vector<int> id;
	for(int i = 1;i < m; ++i)
	{
		if(a[i].first != x && a[i].second != x)
		{
			id.push_back(i);
		}
	}
	if(id.empty())
	{
		p();
	}
	int get1 = a[id[0]].first;
	int get2 = a[id[0]].second;
	int cnt1 = 0,cnt2 = 0;
	for(int i = 0;i < id.size(); ++i)
	{
		int idnow = id[i];
		cnt1 += (a[idnow].first == get1);
		cnt1 += (a[idnow].second == get1);
		cnt2 += (a[idnow].first == get2);
		cnt2 += (a[idnow].second == get2);
	}
	if(cnt1 < id.size() && cnt2 < id.size())
	{
		return;
	}
	p();
}
int main(int argc, char const *argv[])
{
	cin>>n>>m;
	for(int i = 0;i < m; ++i)
	{
		scanf("%d %d",&a[i].first,&a[i].second);
		mp[a[i].first]++;
		mp[a[i].second]++;
		vector<int> s_now;
		s_now.push_back(a[i].first);
		s_now.push_back(a[i].second);
		s[i] = s_now;
	}
	geta(a[0].first);
	geta(a[0].second);
	printf("NO\n");
	return 0;
}