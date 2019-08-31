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
const int maxn = 25;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,1,0,-1};
FILE *in;
struct point{
	int x,y;
	point(int xx = 0,int yy = 0)
	{
		x = xx,y = yy;
	}
	bool operator <(const point &b)const
	{
		if(b.x != x)
		{
			return x < b.x;
		}
		return y < b.y;
	}
	bool operator ==(const point &b)const
	{
		return x == b.x && y == b.y;
	}
	void scan()
	{
		scanf("%d%d",&x,&y);
		++x,++y;
	}
	void print()
	{
		printf("x = %d,y = %d\n",x - 1,y - 1);
	}
};
int n,m;
char a[maxn][maxn];
map<int,int> dis[maxn][maxn];
int last_pos[maxn][maxn];
map<int,int> mp_recr;
int turn;
point st,ed,K_s;
int dr,kase,ans;
int flag_si;
map< pair<point,int>,int > mp_check;
map< pair<point,point>,int> mp_check2;
map<int,point> mpp;
int check(point now)
{
	if(mp_check[make_pair(now,dr)])
	{
		return 1;
	}
	mp_check[make_pair(now,dr)] = 1;
	return 0;
}
int check(point ap,point bp)
{
	if(mp_check2[make_pair(ap,bp)])
	{
		return 1;
	}
	mp_check2[make_pair(ap,bp)] = 1;
	return 0;
}
void bfs1()
{
	int cnt = 0;
	for(int i = 0;i < 4; ++i)
	{
		if(a[K_s.x + dx[i]][K_s.y + dy[i]] != '.')
		{
			cnt++;
		}
	}
	if(cnt == 4)
	{
		turn = 1;
		mpp[1] = K_s;
		return;
	}
	point now = K_s;
	while(1)
	{
		if(a[now.x][now.y] == '?')
		{
			mpp[-1] = mpp[turn - 1];
			return;
		}
		if(check(now))
		{
			mpp[-1] = mpp[turn - 1];
			return;
		}
		dis[now.x][now.y][turn] = 1;
		last_pos[now.x][now.y] = turn;
		mpp[turn] = now;
		while(a[now.x + dx[dr]][now.y + dy[dr]] == '#')
		{
			dr--;
			if(dr == -1)
			{
				dr = 3;
			}
		}
		point cur = point(now.x + dx[dr],now.y + dy[dr]);
		now = cur;
		++dr;
		if(dr == 4)
		{
			dr = 0;
		}
		++turn;
	}
}
bool check_t(point lastpos,point pos,int t)
{
	t %= turn;
	if(mpp[t - 1] == pos && mpp[t] == lastpos)
	{
		return 1;
	}
	if(mpp[t] == pos)
	{
		return 1;
	}
	return 0;
}
int check_qual(point pp)
{
	return pp.x >= 1 && pp.x <= n && pp.y >= 1 && pp.y <= m && a[pp.x][pp.y] != '#';
}
void bfs2()
{
	queue< pair<point,point> > q;
	//				    step,have waited
	q.push(make_pair(point(0,0),st));
	int cnt = 0;
	while(!q.empty() && cnt < 300000)
	{
		++cnt;
		point nowpos = q.front().second;
		point os = q.front().first;
		q.pop();
		if(os.y > turn)
		{
			continue;
		}
		if(nowpos.x == ed.x && nowpos.y == ed.y)
		{
			ans = os.x;
			return;
		}
		if(check(nowpos,os))
		{
			continue;
		}
		os.x++;
		for(int i = 0;i < 4; ++i)
		{
			point newpos = point(nowpos.x + dx[i],nowpos.y + dy[i]);
			if(check_qual(newpos))
			{
				if(!check_t(nowpos,newpos,os.x))
				{
					q.push(make_pair(point(os.x,os.y),newpos));
				}
			}
		}
		if(!check_t(nowpos,nowpos,os.x))
		{
			q.push(make_pair(point(os.x,os.y + 1),nowpos));
		}
	}
	ans = -1;
}
int main(int argc, char const *argv[])
{
	// freopen("test.txt","r",stdin);
	int T;
	scanf("%d",&T);
	map<char,int> mp_a;
	mp_a['U'] = 0;
	mp_a['R'] = 1;
	mp_a['D'] = 2;
	mp_a['L'] = 3;
	while(T--)
	{
		memset(last_pos,0x00,sizeof(last_pos));
		mp_check.clear();
		mp_check2.clear();
		flag_si = 0;
		mp_recr.clear();
		scanf("%d%d",&n,&m);
		turn = 0;
		for(int i = 0;i < maxn; ++i)
		{
			for(int j = 0;j < maxn; ++j)
			{
				dis[i][j].clear();
				a[i][j] = '?';
			}
		}
		st.scan();
		ed.scan();
		K_s.scan();
		char dir;
		scanf(" %c",&dir);
		dr = mp_a[dir];
		turn = 0;
		for(int i = 1;i <= n; ++i)
		{
			scanf("%s",a[i] + 1);
			a[i][0] = '?';
			a[i][m + 1] = '?';
		}
		if(a[ed.x][ed.y] == '#')
		{
			printf("Maze %d: %d\n",++kase,-1);
			continue;
		}
		bfs1();
		bfs2();
		printf("Maze %d: %d\n",++kase,ans);
	}
	printf("\n");
	return 0;
}