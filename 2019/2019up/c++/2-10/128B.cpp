#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;
string to_string(char c)
{
	string ret;
	ret += c;
	return ret;
}
int main(int argc, char const *argv[])
{
	string s;
	cin>>s;
	long long x;
	cin>>x;
	priority_queue< pair<string,int>,vector< pair<string,int> >,greater< pair<string,int> > > q;
	for(int i = 0;i < s.size(); ++i)
	{
		q.push({to_string(s[i]),i});
	}
	--x;
	while(q.size())
	{
		if(x == 0)
		{
			printf("%s\n",q.top().first.c_str());
			return 0;
		}
		pair<string,int> sp = q.top();
		// cout<<sp.first<<endl;
		q.pop();
		if(sp.second < s.size() - 1)
		{
			q.push(make_pair(sp.first + to_string(s[sp.second + 1]),sp.second + 1));
		}
		x--;
	}
	printf("No such line.\n");
	return 0;
}