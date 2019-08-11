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
	bool operator <=(const lnum &b)
	{
		return *this < b || *this == b;
	}
	bool operator >(const lnum &b)
	{
		return !(*this <= b);
	}
	bool operator >=(const lnum &b)
	{
		return *this > b || *this == b;
	}
	bool operator !=(const lnum &b)
	{
		return !(*this == b);
	}
	lnum operator +(const lnum &b)
	{
		lnum ret;
		int large = max(siz,b.siz);
		ret.a.assign(large + 1,0);
		int carry = 0;
		for(int i = 0;i < large || carry; ++i)
		{
			int ai = (i > siz - 1 ? 0 : a[i]);
			int bi = (i > b.siz - 1 ? 0 : b.a[i]);
			ret.a[i] = ai + bi + carry;
			carry = ret.a[i] / base;
			ret.a[i] %= base;
		}
		while(ret.a.size() > 1 && !ret.a.back())
		{
			ret.a.pop_back();
		}
		ret.siz = ret.a.size();
		return ret;
	}
	lnum operator +=(const lnum &b)
	{
		*this = *this + b;
		return *this;
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
	lnum operator *=(const lnum &b)
	{
		*this = *this * b;
		return *this;
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
	lnum operator -=(const lnum &b)
	{
		*this = *this - b;
		return *this;
	}
	void print(const lnum b)
	{
		for(int i = siz - 1;i >= 0; --i)
		{
			if(i == siz - 1)
			{
				printf("%d",b.a[i]);
			}
			else
			{
				printf("%03d",b.a[i]);
			}
		}
		printf("\n");
	}
};
ostream& operator <<(ostream &os,const lnum &b)
{
	for(int i = b.siz - 1;i >= 0; --i)
	{
		if(i == b.siz - 1)
		{
			os<<b.a[i];
		}
		else
		{
			if(b.a[i] < 10)
			{
				os<<"00"<<b.a[i];
			}
			else if(b.a[i] < 100)
			{
				os<<"0"<<b.a[i];
			}
			else
			{
				os<<b.a[i];
			}
		}
	}
	return os;
}
istream& operator >>(istream &is,lnum &b)
{
	string s;
	while(s.empty())
	{
		is>>s;
	}
	b = lnum(s);
	return is;
}
int main(int argc, char const *argv[])
{
	lnum a,b;
	cin>>a>>b;
	cout<<a<<endl<<b<<endl;
	char op;
	cin>>op;
	if(op == '*')
	{
		cout<<(a * b)<<endl;
	}
	else if(op == '+')
	{
		cout<<(a + b)<<endl;
	}
	else
	{
		cout<<(a - b)<<endl;
	}
	return 0;
}