#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 1e5 + 5;
typedef struct{
	int still;
}snow;
int main(int argc,char const *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	snow s[n];
	int temp[n];
	int mi[n];
	for(int i = 0;i < n; ++i)
	{
		cin>>s[i].still;
	}
	for(int i = 0;i < n; ++i)
	{
		mi[i] = 0;
		cin>>temp[i];
		for(int j = 0;j <= i; ++j)
		{
			if(s[j].still >= temp[i])
			{
				s[j].still -= temp[i];
				mi[i] += temp[i];
			}
			else
			{
				mi[i] += s[j].still;
				s[j].still = 0;
			}
		}
	}
	for(int i = 0;i < n; ++i)
	{
		printf("%d ",mi[i]);
	}
	printf("\n");
	return 0;
}