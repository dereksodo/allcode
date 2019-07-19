#include <iostream>
#include <cstring>
using namespace std;
int dpmin[105][105][2];
int dpmax[105][105][2];
int main(int argc, char const *argv[])
{
	string s;
	int n;
	cin>>s>>n;
	int m = s.size();
	memset(dpmin,0x3f,sizeof(dpmin));
	memset(dpmax,0xc0,sizeof(dpmax));
	dpmin[0][0][0] = dpmax[0][0][0] = 0;
	for(int i = 0;i < m; ++i)
	{
		for(int j = 0;j <= n; ++j)
		{
			for(int op = 0;op < 2; ++op)
			{
				int pos = (s[i] != 'F') ? (j + 1) : j;
				int ss = op;
				int dx = op ? -1 : 1;
				dpmin[i + 1][pos][ss] = min(dpmin[i + 1][pos][ss],dpmin[i][j][op] + dx);
				dpmax[i + 1][pos][ss] = max(dpmax[i + 1][pos][ss],dpmax[i][j][op] + dx);

				pos = (s[i] != 'T') ? (j + 1) : j;
				ss = op ^ 1;
				dx = 0;
				dpmin[i + 1][pos][ss] = min(dpmin[i + 1][pos][ss],dpmin[i][j][op] + dx);
				dpmax[i + 1][pos][ss] = max(dpmax[i + 1][pos][ss],dpmax[i][j][op] + dx);
			}
		}
	}
	int ansmin = 0x3f3f3f3f,ansmax = -0x3f3f3f3f;
	for(int j = n % 2;j <= n; j += 2)
	{
		for(int op = 0;op < 2; ++op)
		{
			ansmin = min(ansmin,dpmin[m][j][op]);
			ansmax = max(ansmax,dpmax[m][j][op]);
		}
	}
	int ans = max(abs(ansmin),abs(ansmax));
	printf("%d\n",ans);
	return 0;
}