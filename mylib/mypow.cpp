#include <cstdio>
#include <cstring>
typedef long long ll;
ll mypow(ll a,ll b,ll c)
{
	ll res = 1;
	for(;b;b >>= 1,a = a * a % c)
	{
		if(b & 1)
		{
			res = res * a % c;
		}
	}
	return res;
}
ll toll(const char *s)
{
	ll res = 0;
	int len = strlen(s);
	for(int i = 0;i < len; ++i)
	{
		res = res * 10 + s[i] - '0';
	}
	return res;
}
int main(int argc,char const *argv[])
{
	if(argv[1][0] == '-')
	{
		printf("input 3 number(< 1e18)\nouput a ^ b %c c\n",'%');
		return 0;
	}
	if(argc != 4)
	{
		printf("see --help\n");
		return 0;
	}
	ll a = toll(argv[1]);
	ll b = toll(argv[2]);
	ll c = toll(argv[3]);
	printf("%lld ^ %lld %c %lld = %lld\n",a,b,'%',c,mypow(a,b,c));
	return 0;
}