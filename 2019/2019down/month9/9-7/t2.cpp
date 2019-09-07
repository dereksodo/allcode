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
#define rep(i,n) for(int i = 0;i < (n); ++i)
#define REP(i,n) for(int i = 1;i <= (n); ++i)
const ll Inf = 1e18 + 5;
const int maxn = 1005;
ll f[maxn][maxn][2][2],g[maxn][maxn][2][2][3],sumg[maxn][maxn][2][2][3],k,n,m;
char s[maxn];
void Add(ll &a,ll b)
{
	a += b;
	a = min(a,Inf);
}
int main(int argc, char const *argv[])
{
	scanf("%lld%lld%lld",&n,&m,&k);
	g[1][0][0][0][1] = g[1][0][1][1][1] = 1;
	rep(c1,2)rep(c2,2)g[2][c1 != c2][c1][c2][c1 < c2 ? 0 : c1 == c2 ? 1 : 2] = 1;
	REP(i,n - 2)rep(j,m + 1)rep(c1,2)rep(c2,2)rep(f1,3){
		ll cur = g[i][j][c1][c2][f1];
		if(!cur){
			continue;
		}
		rep(c3,2)rep(c4,2){
			int tmp = c3 < c4 ? 0 : c3 == c4 ? 1 : 2;
			if(j + (c1 != c3) + (c2 != c4) <= m){
				Add(g[i + 2][j + (c1 != c3) + (c2 != c4)][c3][c4][tmp == 1 ? f1 : tmp],cur);
			}
		}
	}
	REP(i,n)rep(j,m + 1)rep(c1,2)rep(c2,2)rep(f1,3){
		if(j){
			sumg[i][j][c1][c2][f1] = sumg[i][j - 1][c1][c2][f1];
		}
		Add(sumg[i][j][c1][c2][f1],g[i][j][c1][c2][f1]);
	}
	ll tot = 0;
	rep(c1,2)rep(c2,2)Add(tot,sumg[n][m][c1][c2][0] + sumg[n][m][c1][c2][1]);
	if(k > tot){
		printf("NO SUCH STRING\n");
		return 0;
	}
	int now = 0;
	rep(i,n){
		if(i < n / 2){
			int cnow = now + (i > 0 && s[i - 1] != 'I');
			ll way = 0;
			if((!(n & 1)) && (i == n / 2 - 1)){
				rep(j,m + 1)rep(c1,2){
					if(i == 0){
						if(j > 0){
							continue;
						}
						way++;
					}else{
						rep(c2,2){
							int nj = cnow + j + (c1 != 0) + (c2 != c1);
							if(nj <= m){
								Add(way,f[i][j][c2][0] + f[i][j][c2][1]);
							}
						}
					}
				}
			}else{
				rep(j,m + 1)rep(c1,2)rep(c2,2)rep(c3,2){
					if((n & 1) && (i == n / 2 - 1) && (c1 != c2)){
						continue;
					}
					if(i == 0){
						if(j > 0){
							continue;
						}
						int nj = cnow + j + (c1 != 0) + (c2 != c3);
						if(nj <= m){
							Add(way,sumg[n - 2 * (i + 1)][m - nj][c1][c2][0] + sumg[n - 2 * (i + 1)][m - nj][c1][c2][1]);
							if(c3 > 0){
								Add(way,sumg[n - 2 * (i + 1)][m - nj][c1][c2][2]);
							}
						}
					}else{
						rep(c4,2){
							int nj = cnow + j + (c1 != 0) + (c2 != c3) + (c3 != c4);
							if(nj <= m){
								ll g0 = sumg[n - 2 * (i + 1)][m - nj][c1][c2][0];
								ll g1 = sumg[n - 2 * (i + 1)][m - nj][c1][c2][1];
								ll g2 = sumg[n - 2 * (i + 1)][m - nj][c1][c2][2];
								if(g0 + g1 + g2 > 0 && f[i][j][c4][0] > Inf / (g0 + g1 + g2)){
									way = Inf;
								}else{
									Add(way,f[i][j][c4][0] * (g0 + g1 + g2));
								}
								if(c3 > 0){
									if(g0 + g1 + g2 > 0 && f[i][j][c4][1] > Inf / (g0 + g1 + g2)){
										way = Inf;
									}else{
										Add(way,f[i][j][c4][1] * (g0 + g1 + g2));
									}
								}else{
									if(g0 + g1 > 0 && f[i][j][c4][1] > Inf / (g0 + g1)){
										way = Inf;
									}else{
										Add(way,f[i][j][c4][1] * (g0 + g1));
									}
								}
							}
						}
					}
				}
			}
			int res;
			if(k > way){
				k -= way;
				s[i] = 'X',res = 1;
			}else{
				s[i] = 'I',res = 0;
			}
			if(i == 0){
				rep(c1,2){
					if(c1 < res){
						continue;
					}
					f[1][0][c1][c1 == res] = 1;
				}
			}else{
				rep(j,m + 1)rep(c1,2)rep(f1,2){
					ll cur = f[i][j][c1][f1];
					if(cur == 0){
						continue;
					}
					rep(c2,2){
						if(f1 == 1 && c2 < res){
							continue;
						}
						if(j + (c1 != c2) <= m){
							Add(f[i + 1][j + (c1 != c2)][c2][f1 && (c2 == res)],cur);
						}
					}
				}
			}
		}else{
			int cnow = now + (i > 0 && s[i - 1] != 'I');
			s[i] = 'I';
			bool ok = true;
			for(int j1 = n - 1 - i,j2 = i;j1 <= i;j1++,j2--){
				if(s[j1] != s[j2]){
					if(s[j1] > s[j2]){
						ok = false;
					}
					break;
				}
			}
			ll way = 0;
			if(i == n - 1){
				way = (ok && cnow <= m) ? 1 : 0;
			}else{
				rep(j,m + 1)rep(c1,2){
					int nj = cnow + j + (c1 != 0);
					if(nj <= m){
						Add(way,f[n - 1 - i][j][c1][0]);
						if(ok){
							Add(way,f[n - 1 - i][j][c1][1]);
						}
					}
				}
			}
			if(k > way){
				k -= way,s[i] = 'X';
			}else{
				s[i] = 'I';
			}
		}
		if(i > 0 && s[i] != s[i - 1]){
			now++;
		}
	}
	printf("%s\n",s);
	return 0;
}