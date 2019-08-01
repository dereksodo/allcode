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
const int maxn = 1000005;
namespace kmp{
	char a[maxn];
	int nxt[maxn],n;
	void buildnxt()
	{
		int j = 0;
		for(int i = 2;i <= n; ++i)
		{
			while(j && a[i] != a[j + 1])
			{
				j = nxt[j];
			}
			if(a[j + 1] == a[i])
			{
				++j;
			}
			nxt[i] = j;
		}
	}
	void geta()
	{
		cin>>n;
		cin>>a + 1;
	}
	int main()
	{
		geta();
		buildnxt();
		printf("%d\n",n - nxt[n]);
		return 0;
	}
};
int main(int argc, char const *argv[])
{
	kmp::main();
	return 0;
}