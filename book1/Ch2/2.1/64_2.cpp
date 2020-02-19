//https://loj.ac/problem/10034
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
const int maxn = 30005;
const int base = 257,mod = 1e9 + 7;
char s[maxn];
set<int> ss;
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	while(n--)
	{
		scanf("%s",s);
		getchar();
		int fg = (s[0] == 'a');
		gets(s);
		int len = strlen(s);
		int z = 0;
		for(int i = 0;i < len; ++i)
		{
			z = z * base + s[i];
			z %= mod;
		}
		if(fg)
		{
			ss.insert(z);
		}
		else
		{
			printf("%s\n",(ss.find(z) != ss.end()) ? "yes" : "no");
		}
	}
	return 0;
}