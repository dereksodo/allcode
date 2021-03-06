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
const int maxn = 100005;
namespace kmp{
	char a[maxn],b[maxn];
	int nxt[maxn];
	int lena,lenb;
	void buildnxt()
	{
		int j = 0;
		for(int i = 2;i <= lenb; ++i)
		{
			while(j && b[i] != b[j + 1])
			{
				j = nxt[j];
			}
			if(b[j + 1] == b[i])
			{
				++j;
			}
			nxt[i] = j;
		}
	}
	void geta()
	{
		cin>>a + 1;
		cin>>b + 1;
	}
	int main()
	{
		geta();
		lena = strlen(a + 1);
		lenb = strlen(b + 1);
		buildnxt();
		int j = 0;
		bool flag = 0;
		for(int i = 1;i <= lena; ++i)
		{
			while(j && b[j + 1] != a[i])
			{
				j = nxt[j];
			}
			if(b[j + 1] == a[i])
			{
				++j;
			}
			if(j == lenb)
			{
				printf("%d ",i - lenb + 1);
				j = nxt[j];
				flag = 1;
			}
		}
		if(!flag)
		{
			printf("No Such Position!\n");
		}
		else
		{
			printf("\n");
		}
		return 0;
	}
};
namespace manacher{
	static const int maxn = 1e5 + 5;
	char a[maxn],s[maxn << 1];
	int pal[maxn << 1];
	int n;
	int manacher()
	{
		s[0] = '~';
		s[1] = '#';
		for(int i = 0;i < n; ++i)
		{
			s[i * 2 + 2] = a[i];
			s[i * 2 + 3] = '#';
		}
		n = n * 2 + 2;
		// printf("%s\n",s);
		int maxright = 0,mid = 0;
		int ans = 0;
		for(int i = 1;i < n; ++i)
		{
			if(i < maxright)
			{
				pal[i] = min(pal[(mid << 1) - i],maxright - i);
			}
			else
			{
				pal[i] = 1;
			}
			while(s[i + pal[i]] == s[i - pal[i]])
			{
				pal[i]++;
			}
			if(pal[i] + i > maxright)
			{
				maxright = pal[i] + i;
				mid = i;
			}
			ans = max(ans,pal[i]);
			// printf("pal[%d] = %d\n",i,pal[i]);
		}
		return ans - 1;
	}
	int main()
	{
		scanf("%s",a);
		n = strlen(a);
		printf("%d\n",manacher());
	}
};
int main(int argc, char const *argv[])
{
	kmp::main();
	return 0;
}