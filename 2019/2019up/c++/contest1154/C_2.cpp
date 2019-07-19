#include <iostream>
using namespace std;
typedef long long ll;
const int day[] = {-1,0,1,2,0,1,2,0};
int main(int argc, char const *argv[])
{
	ll a,b,c;
	cin>>a>>b>>c;
	ll ret = 0;
	for(int i = 1;i <= 7; ++i)
	{
		ll A,B,C;
		A = a,B = b,C = c;
		ll ans = 0;
		for(int j = i;j <= 7; ++j)
		{
			if(day[j] == 0)
			{
				A--;
			}
			else if(day[j] == 1)
			{
				B--;
			}
			else
			{
				C--;
			}
		}
		if(A >= 0 && B >= 0 && C >= 0)
		{
			ans += 8 - i;
		}
		else
		{
			continue;
		}
		ll now = min(A / 3,min(B / 2,C / 2));
		A -= now * 3,B -= now * 2,C -= now * 2;
		ans += now * 7;
		for(int j = 1;j <= 7; ++j)
		{
			if(day[j] == 0)
			{
				A--;
			}
			else if(day[j] == 1)
			{
				B--;
			}
			else
			{
				C--;
			}
			if(A < 0 || B < 0 || C < 0)
			{
				break;
			}
			ans++;
		}
		if(ret < ans)
		{
			ret = ans;
		}
	}
	cout<<ret<<endl;
	return 0;
}