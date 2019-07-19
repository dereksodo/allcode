#include <iostream>
#include <cstring>
using namespace std;
int main(int argc,char const *Argv[])
{
	string input;
	cin>>input;
	int ans = 0;
	for(int i = 0;i < input.size(); ++i)
	{
		int sum = 0,xcnt = 0;
		for(int j = i;j < input.size(); ++j)
		{
			if(input[j] == '(')
			{
				sum++;
			}
			else if(input[j] == ')')
			{
				if(sum)
				{
					sum--;
				}
				else if(xcnt)
				{
					sum++,xcnt--;
				}
				else
				{
					break;
				}
			}
			else
			{
				if(sum)
				{
					sum--,xcnt++;
				}
				else
				{
					sum++;
				}
			}
			if(sum == 0)
			{
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}