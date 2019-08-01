#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int main(int argc,char const *argv[])
{
	int n;
	cin>>n;
	vector<int> v[n + 5];
	memset(v,0x00,sizeof(v));
	for(int i = 0;i < n - 1; ++i)
	{
		int x,y;
		cin>>x>>y;
		v[x - 1].push_back(y);
		v[y - 1].push_back(x);
	}
	int ans = 0;
	for(int i = 0;i < n; ++i)
	{
		for(int j = 0;j < v[i].size(); ++j)
		{
			ans += v[v[i][j] - 1].size() - 1;
		}
		// printf("ans = %d,i = %d\n",ans,i);
	}
	printf("%d\n",ans / 2);
	return 0;
}