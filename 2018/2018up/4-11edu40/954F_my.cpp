#include <iostream>
#include <utility>
#include <vector>
using namespace std;
typedef unsigned long long ull;
int n;
ull m;
const int mod = 1e9 + 7;
vector< pair<ull,ull> > obs;
#define op(x,y) 3 * y - 3 + x
bool find_it(int x,int y)
{
	int p = op(x,y);
	for(int i = 0;i < obs.size(); ++i)
	{
		if(p >= obs[i].first && p <= obs[i].second && (p - obs[i].first) % 3 == 0)
		{
			return 0;
		}
	}
	return 1;
}
//x为列，y为行
inline int dfs(int x,int y)
{
	if(y == m)
	{
		return x == 2;
	}
	++y;
	int ret = 0;
	bool f1 = (find_it(x,y) == 1);
	bool f2 = (find_it(x + 1,y) == 1);
	bool f3 = (find_it(x - 1,y) == 1);
	if(f1)
	{
		ret += dfs(x,y);
	}
	ret %= mod;
	if(x == 1)
	{
		if(f2)
		{
			ret += dfs(x + 1,y);
		}
		ret %= mod;
	}
	else if(x == 2)
	{
		if(f3)
		{
			ret += dfs(x - 1,y);
		}
		ret %= mod;
		if(f2)
		{
			ret += dfs(x + 1,y);
		}
		ret %= mod;
	}
	else if(x == 3)
	{
		if(f3)
		{
			ret += dfs(x - 1,y);
		}
		ret %= mod;
	}
	return ret;
}
int main()
{
	ios::sync_with_stdio(false);
	// 这个是什么意思？
	cin.tie(0);
	cout.tie(0);
	scanf("%d%lld",&n,&m);
	for(int i = 0;i < n; ++i)
	{
		ull x,y,z;
		scanf("%llu%llu%llu",&x,&y,&z);
		// printf("\n");
		// for(;y <= z; ++y)
		// {
		// 	obs.insert(3 * y - 3 + x);
		// 	printf("%llu,",3 * y - 3 + x);
		// }
		obs.push_back(make_pair(3 * y - 3 + x,3 * z - 3 + x));
	}
	// for(unordered_set<ull>::iterator iter = obs.begin();iter != obs.end(); ++iter)
	// {
	// 	printf("%llu ",*iter);
	// }
	printf("%d\n",dfs(2,1));
	return 0;
}