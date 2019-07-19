#include <iostream>
#include <utility>
#include <queue>
#include <cassert>
using namespace std;
#define REP(i,n) for(int i = 0;i < n; ++i)
const int maxn = 805;
char s[maxn][maxn];
int bio[maxn][maxn];
int pr[4] = {1,0,-1,0};
int ps[4] = {0,1,0,-1};
int brred,brstup;
typedef pair<int,int> P;
#define X first
#define Y second
int vani(int r,int c)
{
	return r < 0 || c < 0 || r >= brred || c >= brstup;
}
void bfs(int r,int c)
{
	REP(i,maxn) REP(j,maxn) bio[i][j] = 1e9;
	queue<P> Q;
	Q.push(P(r,c));
	bio[r][c] = 0;
	while(!Q.empty())
	{
		P tmp = Q.front();
		Q.pop();
		REP(i,4)
		{
			int nr = tmp.X + pr[i];
			int nc = tmp.Y + ps[i];
			if(!vani(nr,nc) && s[nr][nc] != '#' && bio[nr][nc] > bio[tmp.X][tmp.Y] + 1)
			{
				bio[nr][nc] = bio[tmp.X][tmp.Y] + 1;
				Q.push(P(nc,nc));
			}
		}
	}
}
int main(int argc, char const *argv[])
{
	int K;
	cin>>brred>>brstup>>K;
	P poc = P(-1,-1);
	REP(i,brred)
	{
		scanf(" %s",s[i]);
		REP(j,brstup)
		{
			if(s[i][j] == 'S')
			{
				poc = P(i,j);
			}
		}
	}
	bfs(poc.X,poc.Y);
	int rje = 1e9;
	REP(i,brred)
	{
		REP(j,brstup)
		{
			if(bio[i][j] <= K)
			{
				int mn = min(min(i,j),min(brred - i - 1,brstup - j - 1));
				int jos = (mn + K - 1) / K;
				rje = min(rje,1 + jos);
			}
		}
	}
	cout<<rje<<endl;
	return 0;
}