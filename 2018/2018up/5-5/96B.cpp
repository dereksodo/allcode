#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<long long> super_lucky;
long long zhuanhuan(vector<int> s)
{
	long long ret = 0;
	for(int i = 0;i < s.size(); ++i)
	{
		ret = ret * 10 + s[i];
	}
	return ret;
}
void init()
{
	int cnt = 1;
	while(cnt < 6)
	{
		vector<int> cur;
		for(int i = 0;i < cnt; ++i)
		{
			cur.push_back(4);
		}
		for(int i = 0;i < cnt; ++i)
		{
			cur.push_back(7);
		}
		do{
			super_lucky.push_back(zhuanhuan(cur));
		}while(next_permutation(cur.begin(),cur.end()));
		cnt++;
	}
}
int main()
{
	init();
	long long n;
	cin>>n;
	for (int i = 0; i < super_lucky.size(); ++i)
	{
		if(n <= super_lucky[i])
		{
			cout<<super_lucky[i]<<endl;
			return 0;
		}
	}
	return 0;
}