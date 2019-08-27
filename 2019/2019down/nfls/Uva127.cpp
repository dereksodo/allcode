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
const int maxn = 100;
stack<string> ss[maxn];
bool same(string s1,string s2)
{
	return s1[1] == s2[1] || s1[0] == s2[0];
}
int main(int argc, char const *argv[])
{
	char c;
	while(scanf("%c",&c) && c != '#')
	{
		for(int i = 1;i <= 53; ++i)
		{
			while(!ss[i].empty())
			{
				ss[i].pop();
			}
		}
		int cnt = 1;
		string s;
		s = "";
		s += c;
		for(int i = 1;i <= 52 * 3 - 1; ++i)
		{
			scanf("%c",&c);
			if(s.size() != 2)
			{
				s += c;
			}
			else
			{
				// printf("s = %s\n",s.c_str());
				ss[cnt++].push(s);
				s = "";
			}
		}
		int flag = 1;
		while(flag)
		{
			flag = 0;
			for(int i = 1;i <= 52; ++i)
			{
				if(!ss[i].empty())
				{
					string u = ss[i].top();
					if(i > 3)
					{
						if(same(u,ss[i - 3].top()))
						{
							ss[i].pop();
							ss[i - 3].push(u);
							flag = 1;
							break;
						}
					}
					if(i > 1)
					{
						if(same(u,ss[i - 1].top()))
						{
							ss[i].pop();
							ss[i - 1].push(u);
							flag = 1;
							break;
						}
					}
				}
				else
				{
					for(int j = i + 1;j <= 52; ++j)
					{
						if(!ss[j].empty())
						{
							flag = 1;
							break;
						}
					}
					if(flag == 0)
					{
						break;
					}
					for(int j = i;j <= 52; ++j)
					{
						ss[j] = ss[j + 1];
					}
					break;
				}
			}
		}
		vector<int> v;
		v.clear();
		for(int i = 1;i <= 52; ++i)
		{
			if(!ss[i].empty())
			{
				v.push_back(int(ss[i].size()));
			}
		}
		if(v.size() == 1)
		{
			printf("1 pile remaining:");
		}
		else
		{
			printf("%d piles remaining:",v.size());
		}
		for(int i = 0;i < v.size(); ++i)
		{
			printf(" %d",v[i]);
		}
		printf("\n");
	}
	return 0;
}