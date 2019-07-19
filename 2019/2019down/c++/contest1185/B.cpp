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
using namespace std;
typedef long long ll;
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	cin.get();
	while(n--)
	{
		string s1,s2;
		cin>>s1>>s2;
		int cnt = 0;
		int flag = 1;
		vector< pair<int,char> > v1,v2;
		for(int i = 0;i < s1.size();)
		{
			int cnt = 0;
			char ch = s1[i];
			while(i < s1.size() && ch == s1[i])
			{
				cnt++;
				++i;
			}
			v1.push_back({cnt,s1[i - 1]});
		}
		for(int i = 0;i < s2.size();)
		{
			int cnt = 0;
			char ch = s2[i];
			while(i < s2.size() && ch == s2[i])
			{
				cnt++;
				++i;
			}
			v2.push_back({cnt,s2[i - 1]});
		}
		if(v1.size() == v2.size())
		{
			int flag = 1;
			for(int i = 0;i < v1.size(); ++i)
			{
				if(!(v1[i].second == v2[i].second
					&& v1[i].first <= v2[i].first))
				{
					flag = 0;
					break;
				}
			}
			if(flag)
			{
				printf("YES\n");
			}
			else
			{
				printf("NO\n");
			}
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}