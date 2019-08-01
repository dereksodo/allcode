#include <iostream>
using namespace std;
const int SIZET = 1e5 + 10;
int water = -1;
char input[2][SIZET];
bool used[2][SIZET];
int n,k;
bool dfs(int i,int j)
{
	if(j > n)
	{
		return 1;
	}
	if(input[i][j] == 'X' || water >= j || used[i][j])
	{
		return 0;
	}
	used[i][j] = 1;
	water++;
	bool ret = dfs(1 - i,j + k) || dfs(i,j + 1) || dfs(i,j - 1);
	water--;
	return ret;
}
int main(int argc,char const *Argv[])
{
	cin>>n>>k;
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin>>input[i][j];
		}
	}
	if(dfs(0,0))
	{
		cout<<"YES"<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}
	return 0;
}