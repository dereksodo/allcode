#include <iostream>
using namespace std;
char s[200005];
int main(int argc, char const *argv[])
{
	int n,t;
	cin>>n>>t;
	scanf("%s",s + 1);
	s[0] = '0';
	for(int i = 0;i <= n; ++i)
	{
		if(s[i] == '.')
		{
			for(int j = i + 1;j <= n; ++j)
			{
				if(s[j] >= '5')
				{
					s[j] = 0;
					int roundup = 1;
					t--;
					for(int k = j - 1;k > i; --k)
					{
						if(roundup)
						{
							s[k]++;
							if(s[k] >= '5' && t)
							{
								s[k] = 0;
								t--;
								roundup = 1;
							}
							else
							{
								roundup = 0;
							}
						}
					}
					if(roundup)
					{
						s[i] = 0;
						for(int k = i - 1;k >= 0; --k)
						{
							s[k]++;
							if(s[k] <= '9')
							{
								break;
							}
							else
							{
								s[k] = '0';
							}
						}
					}
					break;
				}
			}
		}
	}
	if(s[0] != '0')
	{
		printf("%s\n",s);
	}
	else
	{
		printf("%s\n",s + 1);
	}
	return 0;
}