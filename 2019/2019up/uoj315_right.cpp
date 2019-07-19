#include <iostream>
using namespace std;
typedef long long ll;
namespace io{
	const int BUFSIZE = 1 << 20;
	char ibuf[BUFSIZE],*is = ibuf,*it = ibuf;
	char read_char()
	{
		if(is == it)
		{
			it = (is = ibuf) + fread(ibuf,1,BUFSIZE,stdin);
		}
		return *is++;
	}
	int read_int()
	{
		int x = 0,f = 1;
		char c = read_char();
		while(!isdigit(c))
		{
			if(c == '-')
			{
				f = -1;
			}
		}
		c = read_char();
		while(isdigit(c))
		{
			x = x * 10 + c - '0';
			c = read_char();
		}
		return x * f;
	}
};
using io::read_char;
using io::read_int;
const int P = 10000019;
const int N = 2e5 + 5;
const int M = 20000000;
const int mod = 998244353;
const int limit = 50;
const ll base = 7;
struct hash_table_t{
	int total,head[P],next[M],value[M];
	ll to[M];
	void modify(ll x,int v)
	{
		int ind = x % P;
		for(int i = head[ind];i;i = next[i])
		{
			if(to[i] == x)
			{
				value[i] += v;
				return;
			}
		}
		++total;
		to[total] = x;
		next[total] = head[ind];
		value[total] = v;
		head[ind] = total;
	}
	int query(ll x)
	{
		for(int i = head[x % P];i;i = next[i])
		{
			if(to[i] == x)
			{
				return value[i];
			}
		}
		return 0;
	}
}hash_table;
int n,m,pre[N],str[N],suf[N],s[M];
ll power[N];
int main(int argc, char const *argv[])
{
	n = read_int();
	m = read_int();
	for(int i = 1;i <= n; ++i)
	{
		str[i] = read_int();
		hash_table.modify(str[i],1);
	}
	power[0] = 1;
	for(int i = 1;i <= limit; ++i)
	{
		power[i] = power[i - 1] * base;
	}
	return 0;
}