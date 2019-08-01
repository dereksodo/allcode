#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int n;
	cin>>n;
	cin.ignore();
	string s;
	getline(cin,s);
	int ans = 0;
	for(int i = 1;i < s.size(); ++i)
	{
		if(s[i] != s[i - 1])
		{
			ans++;
			i++;
		}
	}
	cout<<n - ans<<endl;
	return 0;
}