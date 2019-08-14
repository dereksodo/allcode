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
const int base = 23789;
const int mod = 1e5 + 5;
deque<int> f,s;
map< pair<int,int>,int > mp;
int check()
{
	int first = 0;
	for(int i = 0;i < f.size(); ++i)
	{
		first = (first * base + f[i]) % mod;
	}
	int second = 0;
	for(int i = 0;i < s.size(); ++i)
	{
		second = (second * base + s[i]) % mod;
	}
	if(mp[make_pair(first,second)])
	{
		printf("-1\n");
		exit(0);
	}
	mp[make_pair(first,second)] = 1;
	return 1;
}
int main(int argc, char const *argv[])
{
	int n,k1,k2;
	cin>>n;
	cin>>k1;
	mp.clear();
	for(int i = 0;i < k1; ++i)
	{
		int x;
		scanf("%d",&x);
		f.push_back(x);
	}
	cin>>k2;
	for(int i = 0;i < k2; ++i)
	{
		int x;
		scanf("%d",&x);
		s.push_back(x);
	}
	int num = 0;
	while(check())
	{
		if(f.empty() || s.empty())
		{
			printf("%d ",num);
			if(f.empty())
			{
				printf("2\n");
			}
			else
			{
				printf("1\n");
			}
			break;
		}
		int ff = f[0];
		int ss = s[0];
		f.pop_front();
		s.pop_front();
		if(ff > ss)
		{
			f.push_back(ss);
			f.push_back(ff);
		}
		else
		{
			s.push_back(ff);
			s.push_back(ss);
		}
		// for(int i = 0;i < f.size(); ++i)
		// {
		// 	printf("%d ",f[i]);
		// }
		// printf("\n");
		// for(int i = 0;i < s.size(); ++i)
		// {
		// 	printf("%d ",s[i]);
		// }
		// printf("\n");
		num++;
	}
	return 0;
}