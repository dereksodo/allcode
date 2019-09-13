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
string s,ls;
char word[10];
char check[10];
map<char,int> two;
map<char,int> tone;
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	cin>>s;
	for(int i = 1;i <= n - 1; ++i)
	{
		cin>>s;
		word[i] = s[0];
	}
	for(int i = 1;i <= n - 1; ++i)
	{
		for(int j = 1;j <= n; ++j)
		{
			cin>>s;
			if(j != 1 && j != 2)
			{
				if(s == ls)
				{
					printf("ERROR!\n");
					return 0;
				}
			}
			ls = s;
			if(s.size() == 2)
			{
				two[word[i]]++;
				tone[s[1]]++;
			}
		}
	}
	for(int i = 1;i <= n - 1; ++i)
	{
		if(two[word[i]] != n - 2 - tone[word[i]])
		{
			printf("ERROR!\n");
			return 0;
		}
	}
	for(int i = 1;i <= n - 1; ++i)
	{
		printf("%c=%d ",word[i],two[word[i]]);
	}
	printf("\n%d\n",n - 1);
	return 0;
}