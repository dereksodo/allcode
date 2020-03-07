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
const int maxn = 2005;
const int mod = 1e8;
int a[maxn],b[maxn];//only minus & div 2
void init(int *s)
{
	string str;
	cin>>str;
	int len = str.size();
	int cnt = 0,ans = 0;
	int t = 1,y = 1;
	for(int i = len - 1;i >= 0; --i)
	{
		++cnt;
		ans += t * (str[i] - '0');
		t *= 10;
		if(cnt == 8)
		{
			s[y++] = ans;
			ans = 0,cnt = 0,t = 1;
		}
	}
	if(cnt)
	{
		s[y] = ans;
	}
	s[0] = (len + 7) / 8;
}
bool com()
{
	if(a[0] != b[0])
	{
		return a[0] > b[0];
	}
	for(int i = a[0];i; --i)
	{
		if(a[i] != b[i])
		{
			return a[i] > b[i];
		}
	}
	return 1;
}
void sub(int *a,int *b)
{
	for(int i = 1;i <= a[0]; ++i)
	{
		a[i] -= b[i];
		if(a[i] < 0)
		{
			a[i] += mod;
			a[i + 1]--;
		}
	}
	while(a[a[0]] == 0 && a[0])
	{
		--a[0];
	}
}
void div2(int *a)
{
	for(int i = a[0];i >= 1; --i)
	{
		a[i - 1] += (a[i] & 1) * mod;
		a[i] /= 2;
	}
	while(a[a[0]] == 0 && a[0])
	{
		--a[0];
	}
}
void mul(int *a,int m)
{
	int carry = 0;
	for(int i = 1;i <= a[0]; ++i)
	{
		int x = a[i] * m + carry;
		a[i] = x % mod;
		carry = x / mod;//x / mod, not a[i] / mod
		if(i == a[0] && carry)
		{
			++a[0];
		}
	}
}
void print(int *a)
{
	for(int i = a[0];i; --i)
	{
		if(i == a[0])
		{
			printf("%d",a[i]);
		}
		else
		{
			printf("%08d",a[i]);
		}
	}
}
int main(int argc, char const *argv[])
{
	init(a),init(b);
	int carry = 1;
	while(1)
	{
		if(!(a[1] & 1) && !(b[1] & 1))
		{
			div2(a),div2(b);
			carry *= 2;
		}
		else if(!(a[1] & 1))
		{
			div2(a);
		}
		else if(!(b[1] & 1))
		{
			div2(b);
		}
		else
		{
			if(com())
			{
				swap(a,b);
			}
			sub(b,a);
			if(b[0] == 0)
			{
				mul(a,carry);
				print(a);
				break;
			}
		}
	}
	printf("\n");
	return 0;
}