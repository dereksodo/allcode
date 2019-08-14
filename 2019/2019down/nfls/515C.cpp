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
using namespace std;
typedef long long ll;
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
int cnt[10];
void check(int index)
{
	if(index == 2)
	{
		cnt[2]++;
	}
	else if(index == 3)
	{
		cnt[3]++;
	}
	else if(index == 4)
	{
		cnt[2] += 2;
	}
	else if(index == 5)
	{
		cnt[5]++;
	}
	else if(index == 6)
	{
		cnt[2]++;
		cnt[3]++;
	}
	else if(index == 7)
	{
		cnt[7]++;
	}
	else if(index == 8)
	{
		cnt[2] += 3;
	}
	else if(index == 9)
	{
		cnt[3] += 2;
	}
}
void display()
{
	printf("%d %d %d %d\n",cnt[7],cnt[5],cnt[3],cnt[2]);
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	for(int i = 1;i <= n; ++i)
	{
		int x;
		scanf("%01d",&x);
		for(int j = 2;j <= x; ++j)
		{
			check(j);
		}
	}
	while(cnt[7])
	{
		printf("7");
		cnt[7]--;
		cnt[2] -= 4;
		cnt[3] -= 2;
		cnt[5]--;
	}
	while(cnt[5])
	{
		printf("5");
		cnt[5]--;
		cnt[2] -= 3;
		cnt[3]--;
	}
	while(cnt[3])
	{
		printf("3");
		cnt[3]--;
		cnt[2]--;
	}
	while(cnt[2])
	{
		printf("2");
		cnt[2]--;
	}
	printf("\n");
	return 0;
}