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
typedef long long ll;
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
ll n,m;
const ll maxn = 1e5 + 5;
ll life[maxn],nowleft;
void input()
{
	scanf("%lld%lld",&n,&m);
	for(ll i = 1;i <= n; ++i)
	{
		scanf("%lld",&life[i]);
	}
	sort(life + 1,life + n + 1);
	nowleft = n;
}
ll p;
void pnow()
{
	ll k = nowleft;
	if(k == 0)
	{
		return;
	}
	for(ll i = n - k + 1;i <= n; ++i)
	{
		p += nowleft * life[i] - 1;
		life[i] = 0;
		nowleft--;
	}
}
int main(int argc, char const *argv[])
{
	input();
	while(nowleft >= 3 && m >= 1)
	{
		m--;
		for(ll i = 1;i <= n; ++i)
		{
			if(life[i] >= 2)
			{
				life[i]--;
			}
			else if(life[i] == 1)
			{
				life[i]--,nowleft--;
			}
		}
		p += nowleft;
	}
	if(m == 0)
	{
		pnow();
	}
	else
	{
		if(nowleft == 1)
		{
			while(nowleft >= 1 && m >= 1)
			{
				life[n] -= 2;
				if(life[n] <= 0)
				{
					break;
				}
				else
				{
					++p;
				}
			}
			if(m == 0)
			{
				pnow();
			}
		}
		else if(nowleft == 2)
		{
			if((life[n] == life[n - 1]) && (life[n] == 1) && m > 0)
			{
				printf("%lld\n",p);
				return 0;
			}
			else
			{
				while(nowleft >= 1 && m >= 1)
				{
					if(life[n - 1] == 1)
					{
						nowleft--;
						p++;
						life[n - 1] = 0;
						break;
					}
					m--;
					life[n - 1] -= 2;
					if(life[n - 1] <= 0)
					{
						nowleft--;
						p += nowleft;
						break;
					}
					else
					{
						p += nowleft;
					}
				}
				if(m == 0)
				{
					pnow();
				}
				while(nowleft >= 1 && m >= 1)
				{
					if(life[n] == 1)
					{
						p += nowleft;
						nowleft--;
						life[n] = 0;
						break;
					}
					m--;
					life[n] -= 2;
					if(life[n] <= 0)
					{
						nowleft--;
						break;
					}
					else
					{
						p += nowleft;
					}
				}
				if(m == 0)
				{
					pnow();
				}
			}
		}
	}
	printf("%lld\n",p);
	return 0;
}