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
lnum mypow(lnum a,int t)
{
	if(t == 0)
	{
		return lnum(1);
	}
	if(t == 1)
	{
		return a;
	}
	lnum ret = mypow(a,t / 2);
	return ret * ret * mypow(a,t % 2);
}
int main(int argc, char const *argv[])
{
	// freopen("test.txt","r",stdin);
	int s1;
	string ss2;
	// printf("hi\n");
	while(~scanf("%d\n",&s1))
	{
		cin>>ss2;
		lnum s2 = lnum(ss2);
		// printf("%d ",s1);
		// cout<<s2<<endl;
		ll left = 1,right = 1e9 + 7;
		while(left < right)
		{
			ll mid = left + right >> 1;
			lnum mid2 = lnum(mid);
			lnum now = mypow(mid2,s1);
			if(now < s2)
			{
				left = mid + 1;
			}
			else
			{
				right = mid;
			}
			// printf("%lld %lld\n",left,right);
		}
		cout<<right<<endl;
	}
	return 0;
}