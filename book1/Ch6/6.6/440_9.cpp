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
const int maxn = 10005;
int cnt[maxn],a[maxn],prime[maxn],tot;
int n,m;
struct lnum{
	static const int base = 1000;
	vector<int> a;
	int siz;
	int stringtoint(string s)
	{
		int ret = 0;
		for(int i = 0;i < s.size(); ++i)
		{
			ret = ret * 10 + s[i] - '0';
		}
		return ret;
	}
	lnum()
	{
		a.clear();
		siz = 0;
	}
	template <typename T>
	lnum(T n)
	{
		a.clear();
		lnum ret;
		if(!n)
		{
			a.push_back(0);
		}
		while(n)
		{
			a.push_back(n % base);
			n /= base;
		}
		siz = a.size();
	}
	lnum(string s)
	{
		a.clear();
		int pos = 0;
		for(int i = 0;i < s.size(); ++i)
		{
			if(s[i] > '0' && s[i] <= '9')
			{
				pos = i;
				break;
			}
		}
		s = s.substr(pos);
		int len = s.length();
		int k = len % 3,p = len / 3;
		lnum ret;
		if(k)
		{
			a.push_back(stringtoint(s.substr(0,k)));
		}
		int pos2 = k;
		while(p--)
		{
			a.push_back(stringtoint(s.substr(pos2,3)));
			pos2 += 3;
		}
		reverse(a.begin(),a.end());
		siz = a.size();
	}
	bool operator <(const lnum &b)
	{
		if(siz > b.siz)
		{
			return 0;
		}
		else if(siz < b.siz)
		{
			return 1;
		}
		for(int i = siz - 1;i >= 0; --i)
		{
			if(a[i] != b.a[i])
			{
				return a[i] < b.a[i];
			}
		}
		return 0;
	}
	bool operator ==(const lnum &b)
	{
		if(siz != b.siz)
		{
			return 0;
		}
		for(int i = 0;i < siz; ++i)
		{
			if(a[i] != b.a[i])
			{
				return 0;
			}
		}
		return 1;
	}
	lnum operator *(const lnum &b)
	{
		lnum ret;
		ret.a.assign(siz + b.siz,0);
		for(int i = 0;i < siz; ++i)
		{
			int carry = 0;
			for(int j = 0;j < b.siz || carry; ++j)
			{
				int bj = (j > b.siz - 1 ? 0 : b.a[j]);
				ret.a[i + j] += a[i] * bj + carry;
				carry = ret.a[i + j] / base;
				ret.a[i + j] %= base;
			}
		}
		while(ret.a.size() > 1 && !ret.a.back())
		{
			ret.a.pop_back();
		}
		ret.siz = ret.a.size();
		return ret;
	}
	lnum operator -(const lnum &b)
	{
		lnum ret;
		int large = max((int)siz,(int)b.siz);
		ret.a.assign(large,0);
		int carry = 0;
		for(int i = 0;i < large || carry; ++i)
		{
			int ai = (i > siz - 1 ? 0 : a[i]);
			int bi = (i > b.siz - 1 ? 0 : b.a[i]);
			ret.a[i] = ai - bi - carry;
			if(ret.a[i] < 0)
			{
				ret.a[i] += base;
				carry = 1;
			}
			else
			{
				carry = 0;
			}
		}
		while(ret.a.size() > 1 && !ret.a.back())
		{
			ret.a.pop_back();
		}
		ret.siz = ret.a.size();
		return ret;
	}
	string to_string()
	{
		string ret2;
		for(int i = siz - 1;i >= 0; --i)
		{
			char ret[10];
			if(i == siz - 1)
			{
				sprintf(ret,"%d",a[i]);
			}
			else
			{
				sprintf(ret,"%03d",a[i]);
			}
			ret2 += string(ret);
		}
		return ret2;
	}
	void print()
	{
		printf("%s\n",to_string().c_str());
	}
};
void init()
{
	for(int i = 2;i <= n + m; ++i)
	{
		if(!a[i])
		{
			a[i] = prime[++tot] = i;
		}
		for(int j = 1;j <= tot; ++j)
		{
			if(i * prime[j] > m + n || prime[j] > a[i])
			{
				break;
			}
			a[i * prime[j]] = prime[j];
		}
	}
}
void add(int num)
{
	while(num ^ 1)
	{
		++cnt[a[num]];
		num /= a[num];
	}
}
void del(int num)
{
	while(num ^ 1)
	{
		--cnt[a[num]];
		num /= a[num];
	}
}
lnum mypow(lnum a,int b)
{
	lnum ret = lnum(1);
	while(b)
	{
		if(b & 1)
		{
			ret = ret * a;
		}
		a = a * a;
		b >>= 1;
	}
	return ret;
}
lnum C(int n,int m)
{
	lnum ans = lnum(1);
	for(int i = 1;i <= tot; ++i)
	{
		cnt[prime[i]] = 0;
	}
	for(int i = n - m + 1;i <= n; ++i)
	{
		add(i);
	}
	for(int i = 1;i <= m; ++i)
	{
		del(i);
	}
	for(int i = 1;i <= tot; ++i)
	{
		ans = ans * mypow(lnum(prime[i]),cnt[prime[i]]);
	}
	return ans;
}
int main(int argc, char const *argv[])
{
	scanf("%d%d",&n,&m);
	init();
	(C(n + m,m) - C(n + m,m - 1)).print();
	return 0;
}