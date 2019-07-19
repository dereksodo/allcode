#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
typedef struct{
	int s[10];
}mys;
vector<mys> square;
int n;
void init()
{
	mys p;
	for(int i = 1;i * i <= n; ++i)
	{
		int su = i * i;
		memset(p.s,0x00,sizeof(p.s));
		while(su)
		{
			p.s[su % 10]++;
			su /= 10;
		}
		square.push_back(p);
	}
}
int main()
{
	cin>>n;
	init();
	mys p;
	memset(p.s,0x00,sizeof(p.s));
	while(n)
	{
		p.s[n % 10]++;
		n /= 10;
	}
	int ans = 10000;
	for(int i = 0;i < square.size(); ++i)
	{
		if(i == 8)
		{
			printf("square:\n");
			for (int x = 0; x < 10; ++x)
			{
				printf("%d ",square[i].s[x]);
			}
			cout<<endl;
			printf("p:\n");
			for (int x = 0; x < 10; ++x)
			{
				printf("%d ",p.s[x]);
			}
		}
		int ret = 0;
		bool flag = 1;
		for(int j = 0;j < 10; ++j)
		{
			if(p.s[j] >= square[i].s[j])
			{
				ret += p.s[j] - square[i].s[j];
			}
			else
			{
				flag = 0;
				break;
			}
		}
		if(flag)
		{
			printf("i = %d\n",i);
			ans = min(ans,ret);
			printf("ans = %d\n",ans);
		}
	}
	printf("\n%d\n",ans);
	return 0;
}