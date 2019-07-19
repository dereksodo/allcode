#include <iostream>
#include <cstring>
using namespace std;
int a[105][55][205][3];
int best;
string s;
void dfs(int pos,int change,int x,int dx)
{
	if(a[pos][change][x + 100][dx + 1])
	{
		return;
	}
	a[pos][change][x + 100][dx + 1] = 1;
	if(pos == s.size())
	{
		if(change == 0)
		{
			best = max(best,abs(x));
		}
		return;
	}
	for(int i = 0;i <= change; ++i)
	{
		int val = (s[pos] == 'F');
		if(i % 2)
		{
			val ^= 1;
		}
		dfs(pos + 1,change - i,x + (val == 1 ? dx : 0),dx * (val == 0 ? -1 : 1));
	}
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>s>>n;
	dfs(0,n,0,1);
	cout<<best<<endl;
	return 0;
}