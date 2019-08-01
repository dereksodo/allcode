#include <iostream>
using namespace std;
const int mod = 1000000000;
const int maxn = 1005;
int n,v,x;
typedef struct dps{
	int pos;
	int cost;
	int cost_per_unit;
}damage_section;
damage_section ds[maxn];
dps make(int a,int b,int c)
{
	dps ret;
	ret.pos = a,ret.cost = b,ret.cost_per_unit = c;
	return ret;
}
int dfs(int rest,int )
{

}
int main(int argc, char const *argv[])
{
	while(cin>>n>>v>>x && n && v && x)
	{
		memset(ds,0x00,sizeof(ds));
		for(int i = 0;i < n; ++i)
		{
			int a,b,c;
			cin>>a>>b>>c;
			ds[i] = make(a - x,b,c);
		}
		printf("%d\n",dfs() % mod);
	}
	return 0;
}