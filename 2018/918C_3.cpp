#include <iostream>
#include <cstring>
using namespace std;

long long ans;

int main()
{
	char s[5050];
	scanf("%s", s);
	int L = strlen(s);
	for(int i=0; i<L; ++i)
	{
		int num=0, now = 0;
		for(int j=i; j<L; ++j)
		{
			if(s[j] == '(')
				now += 1;
			else if(s[j] == ')')
			{
				if(now)
					now -= 1;
				else if(num)//now =0 or <0
					num -= 1, now += 1;
				else break;
			}
			else
			{
				if(now)
					now -= 1, num += 1;
				else 
					now += 1;
			}
			if(!now) 
				ans++;
		}
	}
	printf("%lld\n",ans);
	
	return 0;
}