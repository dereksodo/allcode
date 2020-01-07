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
string s[] = {"","Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy","Sue"};
const int maxn = 10;
map<string,int> mp1;
map<int,string> mp2;
pair<int,int> input[maxn];
void init()
{
	sort(s + 1,s + 9);
	for(int i = 1;i <= 8; ++i)
	{
		mp1[s[i]] = i;
		mp2[i] = s[i];
	}
}
int indexx[maxn];
map<int,int> mp3;
int n;
bool check()
{
	for(int i = 1;i <= 8; ++i)
	{
		mp3[indexx[i]] = i;
	}
	for(int i = 1;i <= n; ++i)
	{
		if(abs(mp3[input[i].first] - mp3[input[i].second]) != 1)
		{
			return 0;
		}
	}
	return 1;
}
int main(int argc, char const *argv[])
{
	init();
	freopen("lineup.in","r",stdin);
	freopen("lineup.out","w",stdout);
	cin>>n;
	getchar();
	char s1[100],s2[100];
	for(int i = 1;i <= n; ++i)
	{
		scanf("%s must be milked beside %s\n",s1,s2);
		input[i].first = mp1[string(s1)];
		input[i].second = mp1[string(s2)];
	}
	// for(int i = 1;i <= n; ++i)
	// {
	// 	printf("%s %s\n",mp2[input[i].first].c_str(),mp2[input[i].second].c_str());
	// }
	for(int i = 1;i <= 8; ++i)
	{
		indexx[i] = i;
	}
	do{
		if(check())
		{
			for(int i = 1;i <= 8; ++i)
			{
				printf("%s\n",mp2[indexx[i]].c_str());
			}
			return 0;
		}
	}while(next_permutation(indexx + 1,indexx + 9));
	return 0;
}