#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	vector<int> ss;
	while(n--)
	{
		string s;
		cin>>s;
		if(s == "add")
		{
			int p;
			cin>>p;
			ss.insert(lower_bound(ss.begin(),ss.end(),p),p);
		}
		else if(s == "sum")
		{
			long long sum = 0;
			for(int i = 2;i < ss.size(); i += 5)
			{
				sum += ss[i];
			}
			cout<<sum<<endl;
		}
		else
		{
			int p;
			cin>>p;
			ss.erase(lower_bound(ss.begin(),ss.end(),p));
		}
	}
	return 0;
}