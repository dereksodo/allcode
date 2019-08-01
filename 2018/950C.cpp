#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<int> v[200010];
int main()
{
	string s;
	cin>>s;
	int k = 0,m = 0;
	for(int i = 0;i < s.size(); ++i)
	{
		if(s[i] == '0')
		{
			v[++k].push_back(i + 1);
		}
		else
		{
			if(k == 0)
			{
				printf("-1\n");
				return 0;
			}
			v[k--].push_back(i + 1);
		}
		m = max(m,k);
	}
	if(m != k)
	{
		printf("-1\n");
		return 0;
	}
	printf("%d\n",m);
	for(int i = 1;i <= m; ++i)//attention
	{
		printf("%d ",(int)v[i].size());
		for(int j = 0;j < v[i].size(); ++j)
		{
			printf("%d ",v[i][j]);
		}
		printf("\n");
	}
	return 0;
}