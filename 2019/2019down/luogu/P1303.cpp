#include <iostream>
#include <cstring>
#include <cstdlib>
#include <set>
#include <vector>
#include <map>
#include <cstdio>
#include <utility>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
using namespace std;
typedef vector<int> lnum;
static const int base = 1000;
#define p(n) printf("%d\n",n)
// #define DEBUG
bool operator <(const lnum &a,const lnum &b)
{
	if(a.size() > b.size())
	{
		return 0;
	}
	else if(a.size() < b.size())
	{
		return 1;
	}
	for(int i = a.size() - 1;i >= 0; --i)
	{
		if(a[i] != b[i])
		{
			return a[i] < b[i];
		}
	}
	return 0;
}
lnum operator +(const lnum &a,const lnum &b)
{
	lnum ret;
	int large = max((int)a.size(),(int)b.size());
	ret.assign(large + 1,0);
	int carry = 0;
	for(int i = 0;i < large; ++i)
	{
		int ai = (i > a.size() - 1 ? 0 : a[i]);
		int bi = (i > b.size() - 1 ? 0 : b[i]);
		ret[i] = ai + bi + carry;
		carry = ret[i] / base;
		ret[i] %= base;
	}
	while(ret.size() > 1 && !ret.back())
	{
		ret.pop_back();
	}
	return ret;
}
lnum operator *(const lnum &a,const lnum &b)
{
	lnum ret;
	ret.assign(a.size() + b.size(),0);
	for(int i = 0;i < a.size(); ++i)
	{
		int carry = 0;
		for(int j = 0;j < b.size() || carry; ++j)
		{
			int bj = (j > b.size() - 1 ? 0 : b[j]);
			ret[i + j] += a[i] * bj + carry;
			carry = ret[i + j] / base;
			ret[i + j] %= base;
		}
	}
	while(ret.size() > 1 && !ret.back())
	{
		ret.pop_back();
	}
	return ret;
}
lnum operator -(const lnum &a,const lnum &b)
{
	lnum ret;
	int large = max((int)a.size(),(int)b.size());
	ret.assign(large,0);
	int carry = 0;
	for(int i = 0;i < large; ++i)
	{
		int ai = (i > a.size() - 1 ? 0 : a[i]);
		int bi = (i > b.size() - 1 ? 0 : b[i]);
		ret[i] = ai - bi - carry;
		if(ret[i] < 0)
		{
			ret[i] += base;
			carry = 1;
		}else
		{
			carry = 0;
		}
	}
	while(ret.size() > 1 && !ret.back())
	{
		ret.pop_back();
	}
	return ret;
}
void Print(lnum a)
{
	for(int i = a.size() - 1;i >= 0; --i)
	{
		if(i == a.size() - 1)
		{
			printf("%d",a[i]);
		}else
		{
			printf("%03d",a[i]);
		}
	}
	printf("\n");
}
int stringtoint(string s)
{
	int ret = 0;
	for(int i = 0;i < s.size(); ++i)
	{
		ret = ret * 10 + s[i] - '0';
	}
	return ret;
}
lnum fromint(int n)
{
	lnum ret;
	if(!n)
	{
		ret.push_back(0);
		return ret;
	}
	while(n)
	{
		ret.push_back(n % base);
		n /= base;
	}
	return ret;
}
lnum fromstring(string s)
{
	int p__ = 0;
	for(int i = 0;i < s.size(); ++i)
	{
		if(s[i] > '0' && s[i] <= '9')
		{
			p__ = i;
			break;
		}
	}
	s = s.substr(p__);
	int len = s.length();
	int k = len % 3,p = len / 3;
	lnum ret;
	if(k)
	{
		ret.push_back(stringtoint(s.substr(0,k)));
	}
	int pos = k;
	while(p--)
	{
		ret.push_back(stringtoint(s.substr(pos,3)));
		pos += 3;
	}
	reverse(ret.begin(),ret.end());
	return ret;
}
int main(int argc, char const *argv[])
{
	string a,b;
	cin>>a>>b;
	Print(fromstring(a) * fromstring(b));
	return 0;
}