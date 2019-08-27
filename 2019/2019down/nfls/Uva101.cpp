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
const int maxn = 30;
vector<int> v[maxn];
char pa[maxn],pb[maxn];
int n;
int wa,ca,wb,cb,a,b;
void f()
{
	for(int i = 0;i < n; ++i)
	{
		for(int j = 0;j < v[i].size(); ++j)
		{
			if(v[i][j] == a)
			{
				wa = i,ca = j;
			}
			if(v[i][j] == b)
			{
				wb = i,cb = j;
			}
		}
	}
}
void moon()
{
	for(int i = ca + 1;i < v[wa].size(); ++i)
	{
		v[v[wa][i]].push_back(v[wa][i]);
	}
	for(int i = cb + 1;i < v[wb].size(); ++i)
	{
		v[v[wb][i]].push_back(v[wb][i]);
	}
	v[wa].resize(ca);
	v[wb].resize(cb + 1);
	v[wb].push_back(a);
}
void moov()
{
	for(int i = ca + 1;i < v[wa].size(); ++i)
	{
		v[v[wa][i]].push_back(v[wa][i]);
	}
	v[wa].resize(ca);
	v[wb].push_back(a);
}
void pion()
{
	for(int i = cb + 1;i < v[wb].size(); ++i)
	{
		v[v[wb][i]].push_back(v[wb][i]);
	}
	v[wb].resize(cb + 1);
	for(int i = ca;i < v[wa].size(); ++i)
	{
		v[wb].push_back(v[wa][i]);
	}
	v[wa].resize(ca);
}
void piov()
{
	for(int i = ca;i < v[wa].size(); ++i)
	{
		v[wb].push_back(v[wa][i]);
	}
	v[wa].resize(ca);
}
int main(int argc, char const *argv[])
{
	scanf("%d",&n);
	for(int i = 0;i < n; ++i)
	{
		v[i].push_back(i);
	}
	while(1)
	{
		scanf("%s",pa);
		if(pa[0] == 'q')
		{
			break;
		}
		scanf("%d%s%d",&a,pb,&b);
		f();
		if(wa == wb)
		{
			continue;
		}
		if(pa[0] == 'm')
		{
			if(pb[1] == 'n')
			{
				moon();
			}
			else
			{
				moov();	
			}
		}
		else
		{
			if(pb[1] == 'n')
			{
				pion();
			}
			else
			{
				piov();
			}
		}
	}
	for(int i = 0;i < n; ++i)
	{
		printf("%d:",i);
		for(int j = 0;j < v[i].size(); ++j)
		{
			printf(" %d",v[i][j]);
		}
		printf("\n");
	}
	return 0;
}