#include <iostream>
#include <utility>
#include <cstring>
using namespace std;
#define FOR(i,a,b) for(int i = (a),_b = (b); i <= b; ++i)
#define FORD(i,a,b) for(int i = (A),_b = (b); i >= _b; --i)
#define REP(i,a) for(int i = 0,_a = (a); i < _a; ++i)
const int di[4] = {-1,1,0,0};
const int dj[4] = {0,0,-1,1};
int res = 0;
bool good[11][11],vis[11][11];
pair<int,int> a[111];
int qu[111],qv[111],first,last;
int targetADD,maxVal,target;
bool usedRow[11][11],usedCol[11][11];
int n;
void attemptADD(int i,int cur)
{
	if(i > n)
	{
		++res;
		return;
	}
	int u = qu[i],v = qv[i];
	if(i == n)
	{
		int need = targetADD - cur;
		if(need > 0 && need <= maxVal && !usedRow[u][need] && !usedCol[v][need])
		{
			++res;
		}
		return;
	}
	FOR(val,1,maxVal)
	{
		if(!usedRow[u][val] && !usedCol[v][val])
		{
			if(cur + val > targetADD)
			{
				continue;
			}
			int left = n - i;
			if(cur + val + left > targetADD)
			{
				continue;
			}
			if(cur + val + left * 9 < targetADD)
			{
				continue;
			}
			usedRow[u][val] = 1;
			usedCol[v][val] = 1;
			attemptADD(i + 1,val + cur);
			usedRow[u][val] = 0;
			usedCol[v][val] = 0;
		}
	}
}
char op;
void attemptMult(int i,long long cur)
{
	if(i > n)
	{
		if(cur == target)
		{
			++res;
		}
		return;
	}
	int u = qu[i],v = qv[i];
	if(i == n)
	{
		if(target % cur)
		{
			return;
		}
		int need = target / cur;
		if(need > 0 && need <= maxVal && !usedRow[u][need] && !usedCol[v][need])
		{
			++res;
		}
		return;
	}
	FOR(val,1,maxVal)
	{
		if(!usedRow[u][val] && !usedCol[v][val])
		{
			if(target % (cur * val))
			{
				continue;
			}
			usedRow[u][val] = 1;
			usedCol[v][val] = 1;
			attemptMult(i + 1,(op == '+') ? (val + cur) : (val * cur));
			usedRow[u][val] = 0;
			usedCol[v][val] = 0;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>maxVal>>n>>target>>op;
	memset(good,0x00,sizeof(good));
	FOR(i,1,n)
	{
		cin>>a[i].first>>a[i].second;
		good[a[i].first][a[i].second] = 1;
	}
	random_shuffle(a + 1,a + n + 1);
	if(op == '-')
	{
		int res = 0;
		FOR(i,1,maxVal)
		{
			FOR(j,1,maxVal)
			{
				if(i != j)
				{
					if(i - j == target)
					{
						res += 2;
					}
				}
			}
		}
		cout<<res<<endl;
		return 0;
	}
	if(op == '/')
	{
		int res = 0;
		FOR(i,1,maxVal)
		{
			FOR(j,1,maxVal)
			{
				if(i != j)
				{
					if(i % j == 0 && i / j == target)
					{
						res += 2;
					}
				}
			}
		}
		cout<<res<<endl;
		return 0;
	}
	first = last = 1;
	qu[1] = a[1].first;
	qv[1] = a[1].second;
	memset(vis,0x00,sizeof(vis));
	vis[a[1].first][a[1].second] = 1;
	while(first <= last)
	{
		int u = qu[first],v = qv[first];
		++first;
		REP(dir,4)
		{
			int uu  = u + di[dir],vv = v + dj[dir];
			if(uu < 1 || uu > maxVal || vv < 1 || vv > maxVal)
			{
				continue;
			}
			if(!good[uu][vv])
			{
				continue;
			}
			if(!vis[uu][vv])
			{
				vis[uu][vv] = 1;
				++last;
				qu[last] = uu;
				qv[last] = vv;
			}
		}
	}
	res = 0;
	if(op == '+')
	{
		targetADD = target;
		attemptADD(1,0);
	}
	if(op == '*')
	{
		attemptADD(1,1LL);
	}
	cout<<res<<endl;
	return 0;
}