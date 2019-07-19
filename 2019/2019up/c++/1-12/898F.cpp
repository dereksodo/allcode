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
const int maxn = 1e6 + 6;
const int mod = 998244353;
string s;
int n;
struct hash_table_t{
	int H[maxn],power[maxn];
	void pre()
	{
		H[0] = 0;
		for(int i = 1;i <= n; ++i)
		{
			H[i] = (H[i - 1] * 10 + (s[i - 1] - '0')) % mod;
		}
		power[0] = 1;
		for(int i = 1;i <= n; ++i)
		{
			power[i] = (power[i - 1] * 10) % mod;
		}
	}
	void out()
	{
		for(int i = 1;i <= n; ++i)
		{
			printf("H[%d] = %d\n",i,H[i]);
		}
		for(int i = 1;i <= n; ++i)
		{
			printf("power[%d] = %d\n",i,power[i]);
		}
	}
	int get(int from,int to)
	{
		from++,to++;
		return (H[to] - H[from - 1] * power[to - from + 1] % mod) % mod;
	}
}hash_table;
void print(int first,int second)
{
	for(int i = 0;i < first; ++i)
	{
		printf("%c",s[i]);
	}
	printf("+");
	for(int i = first;i <= second; ++i)
	{
		printf("%c",s[i]);
	}
	printf("=");
	for(int i = second + 1;i < n; ++i)
	{
		printf("%c",s[i]);
	}
	printf("\n");
}
int main(int argc, char const *argv[])
{
	cin>>s;
	n = s.size();
	hash_table.pre();
	hash_table.out();
	for(int i = 1;i < n / 2; ++i)
	{
		//(i) (n - i - i - 1) (i + 1)
		if(hash_table.get(0,i - 1) + hash_table.get(i,n - i - 1) == hash_table.get(n - i,n - 1))
		{
			print(i,n - i - 1);
		}
		//(i) ((n - i) / 2) ((n - i) / 2 + 1)
		if((n - i) & 1)
		{
			if(hash_table.get(0,i - 1) + hash_table.get(i,(n - i) / 2 + i) == hash_table.get((n - i) / 2 + i + 1,n - 1))
			{
				print(i,(n - i) / 2 + i);
			}
		}
		else//(i) ((n - i) / 2) ((n - i) / 2)
		{
			if(hash_table.get(0,i - 1) + hash_table.get(i,(n - i) / 2 + i) == hash_table.get((n - i) / 2 + i + 1,n - 1))
			{
				print(i,(n - i) / 2 + i);
			}
		}
		//(i) (n - i - i) (i)
		if(hash_table.get(0,i - 1) + hash_table.get(i,n - i) == hash_table.get(n - i + 1,n - 1))
		{
			print(i,n - i);
		}

	}
	printf("NO\n");
	return 0;
}