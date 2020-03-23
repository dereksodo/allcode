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
#include <numeric>
#include <sstream>
using namespace std;
// #define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
#define ll int64_t
#define maxf(a,b) (max(a.first,b.first))
#define mins(a,b) (min(a.second,b.second))
#define mp make_pair
#define wr(a) (a.first > a.second)
typedef pair<ll,ll> pll;
template <typename T>
T input()
{
	T res;
	cin>>res;
	return res;
}
struct type{
	ll x,y,z;
	type(ll _x = INT64_MAX,ll _y = INT64_MAX,ll _z = INT64_MAX):x(_x),y(_y),z(_z){};
};
struct equ{
	pll S,a,b,c;
};
vector<type> list;
equ operator +(const equ &e1,const equ &e2)
{
	equ res;
	res.S = mp(maxf(e1.S,e2.S),mins(e1.S,e2.S));
	res.a = mp(maxf(e1.a,e2.a),mins(e1.a,e2.a));
	res.b = mp(maxf(e1.b,e2.b),mins(e1.b,e2.b));
	res.c = mp(maxf(e1.c,e2.c),mins(e1.c,e2.c));
	return res;
}
type get_sol(const equ &eq)
{
	if(wr(eq.S) || wr(eq.a) || wr(eq.b) || wr(eq.c))
	{
		return type(INT64_MAX,INT64_MAX,INT64_MAX);
	}
	if((eq.a.first + eq.b.first + eq.c.first > eq.S.second)
		|| (eq.a.second + eq.b.second + eq.c.second < eq.S.first))
	{
		return type(INT64_MAX,INT64_MAX,INT64_MAX);
	}
	type res;
	res = type(eq.a.first,eq.b.first,eq.c.first);
	ll del = max(int64_t(0),eq.S.first - res.x - res.y - res.z);

	res.x += min(del,eq.a.second - eq.a.first);
	del -= min(del,eq.a.second - eq.a.first);

	res.y += min(del,eq.b.second - eq.b.first);
	del -= min(del,eq.b.second - eq.b.first);

	res.z += min(del,eq.c.second - eq.c.first);
	del -= min(del,eq.c.second - eq.c.first);
	// assert(del == 0);
	return res;
}
ll div2(ll arg)
{
	return (arg - (arg & 1)) / 2;
}
type can(ll mid)
{
	equ eq;
	eq.S = eq.a = eq.b = eq.c = mp(INT64_MIN,INT64_MAX);
	for(const type &crd: list)
	{
		equ now;
		now.S = mp( crd.x + crd.y + crd.z - mid, crd.x + crd.y + crd.z + mid);
		now.a = mp(-crd.x + crd.y + crd.z - mid,-crd.x + crd.y + crd.z + mid);
		now.b = mp( crd.x - crd.y + crd.z - mid, crd.x - crd.y + crd.z + mid);
		now.c = mp( crd.x + crd.y - crd.z - mid, crd.x + crd.y - crd.z + mid);
		eq = eq + now;
		debug("%d %d\n%d %d\n%d %d\n%d %d\n",eq.S.first,eq.S.second,eq.a.first,eq.a.second,eq.b.first,eq.b.second,eq.c.first,eq.c.second);
	}
	for(int64_t r = 0;r <= 1; ++r)//remainder
	{
		equ tr = eq;
		tr.S = mp(div2(tr.S.first - 3 * r + 1),div2(tr.S.second - 3 * r));
		tr.a = mp(div2(tr.a.first - r + 1),div2(tr.a.second - r));
		tr.b = mp(div2(tr.b.first - r + 1),div2(tr.b.second - r));
		tr.c = mp(div2(tr.c.first - r + 1),div2(tr.c.second - r));
		type sol = get_sol(tr);
		if(sol.x != INT64_MAX)
		{
			type ans;
			ans = type(r + sol.y + sol.z,r + sol.x + sol.z,r + sol.x + sol.y);
			return ans;
		}
	}
	return type(INT64_MAX,INT64_MAX,INT64_MAX);
}
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	list.reserve(100000);
	for(size_t T = input<size_t>();T != 0; --T)
	{
		list.resize(input<size_t>());
		for(type &crd: list)
		{
			cin>>crd.x>>crd.y>>crd.z;
		}
		ll l = -1,r = 3 * int64_t(1000 * 1000 * 1000) * int64_t(1000 * 1000 * 1000) + 10;
		while(r - l > 1)
		{
			ll mid = l + (r - l) / 2;
			if(can(mid).x != INT64_MAX)
			{
				r = mid;
			}
			else
			{
				l = mid;
			}
		}
		type ans = can(r);
		cout<<ans.x<<" "<<ans.y<<" "<<ans.z<<"\n";
	}
	return 0;
}