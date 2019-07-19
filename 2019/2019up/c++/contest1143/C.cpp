#include <iostream>
#include <set>
using namespace std;
const int maxn = 1e5 + 5;
set<int> s;
int flag[maxn];
int c[maxn];
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	for(int i = 1;i <= n; ++i)
	{
		int p;
		scanf("%d%d",&p,&c[i]);
		if(p != -1 && c[i] == 0)
		{
			flag[p] = 1;
		}
	}
	for(int i = 1;i <= n; ++i)
	{
		if(flag[i] == 0 && c[i] == 1)
		{
			s.insert(i);
		}
	}
	if(s.empty())
	{
		printf("-1\n");
	}
	else
	{
		for(auto i = s.begin(); i != s.end(); ++i)
		{
			printf("%d ",*i);
		}
		printf("\n");
	}
	return 0;
}