#include <iostream>
#include <cstring>
#include <list>
using namespace std;
typedef long long ll;
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
string s;
int main(int argc, char const *argv[])
{
	while(cin>>s)
	{
		list<char> ret;
		list<char>::iterator iter = ret.begin();
		for(int i = 0;i < s.size(); ++i)
		{
			if(s[i] == '[')
			{
				iter = ret.begin();
			}
			else if(s[i] == ']')
			{
				iter = ret.end();
			}
			else
			{
				ret.insert(iter,s[i]);
			}
		}
		for(iter = ret.begin();iter != ret.end(); ++iter)
		{
			printf("%c",*iter);
		}
		printf("\n");
	}
	return 0;
}