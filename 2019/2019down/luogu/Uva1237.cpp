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
struct node_{
	string name;
	int l,r;
};
node_ node[10005];
int main(int argc, char const *argv[])
{
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		for(int i = 0;i < n; ++i)
		{
			cin>>node[i].name>>node[i].l>>node[i].r;
		}
		int q;
		cin>>q;
		while(q--)
		{
			int x;
			scanf("%d",&x);
			string ans;
			int cnt = 0;
			for(int i = 0;i < n; ++i)
			{
				if(x >= node[i].l && x <= node[i].r)
				{
					cnt++;
					ans = node[i].name;
				}
			}
			if(cnt != 1)
			{
				printf("UNDETERMINED\n");
			}
			else
			{
				printf("%s\n",ans.c_str());
			}
		}
		if(T)
		{
			printf("\n");
		}
	}
	return 0;
}