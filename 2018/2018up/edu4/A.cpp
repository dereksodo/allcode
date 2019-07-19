#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
int main(int argc, char const *argv[])
{
	int n,p,q;
	scanf("%d %d %d\n",&n,&p,&q);
	string s;
	cin>>s;
	vector<string> output;
	for(int i = 0;i <= 100; ++i)
	{
		for(int j = 0;j <= 100; ++j)
		{
			if(p * i + q * j == n)
			{
				int pos = 0;
				for(int k = 1;k <= i; ++k)
				{
					output.push_back(s.substr(pos,p));
					pos += p;
				}
				for(int m = 1;m <= j; ++m)
				{
					output.push_back(s.substr(pos,q));
					pos += q;
				}
				printf("%d\n",(int)output.size());
				for(int i = 0;i < output.size(); ++i)
				{
					printf("%s\n",output[i].c_str());
				}
				return 0;
			}
		}
	}
	printf("-1\n");
	return 0;
}