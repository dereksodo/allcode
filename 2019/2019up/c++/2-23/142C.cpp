#include <iostream>
#include <cstring>
#include <ctime>
using namespace std;
const double sec = 2000;
const int maxn = 10;
int vis[maxn][maxn];
int artuaans[maxn][maxn] = {{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,1,1,2,2,3,3,4},{0,0,0,1,2,2,3,4,4,5},{0,0,0,2,2,4,4,5,6,7},{0,0,0,2,3,4,5,6,7,8},{0,0,0,3,4,5,6,8,9,10},{0,0,0,3,4,6,7,9,10,11},{0,0,0,4,5,7,8,10,12,13}};
//										...									.									.									.		
//										 .									.								  ...									...
//									     .								   ...									.									.
pair<int,int> target[][5] = {{{-1,-1},{-1,0},{-1,1},{1,0},{0,0}},{{1,-1},{1,0},{1,1},{-1,0},{0,0}},{{0,-1},{0,1},{-1,1},{1,1},{0,0}},{{0,1},{-1,-1},{1,-1},{0,-1},{0,0}}};
int n,m,aans,bg;
char ans[maxn][maxn],rans[maxn][maxn];
int check(int x,int y)
{
	return x >= 1 && x <= n && y >= 1 && y <= m && !vis[x][y];
}
int Left = 0;
int ok(int x,int y,int p)
{
	// printf("aax = %d,y = %d\n",x,y);
	int i = p;
	{
		bool flag = 1;
		for(int j = 0;j < 5; ++j)
		{
			if(!check(x + target[i][j].first,y + target[i][j].second))
			{
				flag = 0;
				break;
			}
		}
		if(flag)
		{
			return 1;
		}
	}
	return 0;
}
int chAr = 'A';
void display()
{
	printf("************\n");
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 1;j <= m; ++j)
		{
			printf("%c",rans[i][j]);
		}
		printf("\n");
	}
	printf("************\n");
}
void aaaend()
{
	printf("%d\n",aans);
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 1;j <= m; ++j)
		{
			printf("%c",rans[i][j]);
		}
		printf("\n");
	}
	exit(0);
}
void go(int x,int y,int sum)
{
	if(sum > aans)
	{
		aans = sum;
		for(int i = 1;i <= n; ++i)
		{
			for(int j = 1;j <= m; ++j)
			{
				rans[i][j] = ans[i][j];
			}
		}
	}
	if(aans == artuaans[n][m])
	{
		aaaend();
	}
	if(Left / 5 + sum <= aans)
	{
		return;
	}
	for(int i = 0;i < 4; ++i)
	{
		if(ok(x,y,i))
		{
			// printf("x = %d,y = %d\n",x,y);
			for(int j = 0;j < 5; ++j)
			{
				vis[x + target[i][j].first][y + target[i][j].second] = 1;
				ans[x + target[i][j].first][y + target[i][j].second] = chAr;
			}
			chAr++;
			Left -= 5;
			for(int nx = 1;nx <= n; ++nx)
			{
				for(int ny = 1;ny <= m; ++ny)
				{
					if(!vis[nx][ny])
					{
						go(nx,ny,sum + 1);
					}
				}
			}
			Left += 5;
			chAr--;
			for(int j = 0;j < 5; ++j)
			{
				vis[x + target[i][j].first][y + target[i][j].second] = 0;
				ans[x + target[i][j].first][y + target[i][j].second] = '.';
			}
		}
	}
	// display();
}
void dfs()
{
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 1;j <= m; ++j)
		{
			ans[i][j] = '.';
			rans[i][j] = '.';
		}
	}
	aans = 0;
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 1;j <= m; ++j)
		{
			memset(vis,0x00,sizeof(vis));
			for(int i = 1;i <= n; ++i)
			{
				for(int j = 1;j <= m; ++j)
				{
					ans[i][j] = '.';
				}
			}
			Left = n * m;
			go(i,j,0);
		}
	}
	aaaend();
}
int main(int argc, char const *argv[])
{
	bg = clock();
	// for(int j = 0;j < 4; ++j)
	// {
	// 	int dx = 1,dy = 1;
	// 	int asdf[3][3] = {0};
	// 	asdf[dx][dy] = 1;
	// 	for(int i = 0;i < 5; ++i)
	// 	{
	// 		asdf[dx + target[j][i].first][dy + target[j][i].second] = 1;
	// 	}
	// 	for(int i = 0;i < 3; ++i)
	// 	{
	// 		for(int k = 0;k < 3; ++k)
	// 		{
	// 			if(asdf[i][k])
	// 			{
	// 				debug(".");
	// 			}
	// 			else
	// 			{
	// 				debug(" ");
	// 			}
	// 		}
	// 		cout<<endl;
	// 	}
	// }
	scanf("%d%d",&n,&m);
// 	if(n == 7 && m == 8)
// 	{
// 		cout<<R"(9
// AAA.BBB.
// .ACCCBD.
// .AEC.BD.
// EEECFDDD
// G.EHFFFI
// GGGHFIII
// G.HHH..I)";
// 		cout<<endl;
// 		return 0;
// 	}
// 	if(n == 8 && m == 9)
// 	{
// 		cout<<R"(12
// A.EEE.JJJ
// AAAEHHHJ.
// AB.EFHKJ.
// .BFFFHKKK
// BBBDFIK..
// CDDDGIIIL
// CCCDGILLL
// C..GGG..L)"<<endl;
// 		return 0;
// 	}
// 	if(n == 9 && m == 9)
// 	{
// 		cout<<R"(13
// AAABCCCD.
// .A.B.C.D.
// EABBBCDDD
// EEE.FG...
// EHFFFGGGI
// .HHHFGIII
// JH.KLLLMI
// JJJK.L.M.
// J.KKKLMMM)"<<endl;
// 		return 0;
// 	}
	// n = stoi(argv[1]);
	// m = stoi(argv[2]);
	dfs();
	return 0;
}