#include <iostream>
using namespace std;
int fibs[15] = {1,2,3,5,8,13,21,34,55,89,144,233,377,610,987};
int main(int argc,char const *argv[])
{
	bool flagf[1001] = {0};
	for(int i = 0;i < 15; ++i)
	{
		flagf[fibs[i]] = 1;
	}
	int n;
	cin>>n;
	string s;
	for(int i = 0;i < n; ++i)
	{
		s += 'o';
	}
	for(int i = 0;i < s.size(); ++i)
	{
		if(flagf[i + 1])
		{
			s[i] = 'O';
		}
	}
	cout<<s<<endl;
	return 0;
}