#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long double ld;
#define f first
#define s second
pair<ld,int> D[100005];
int main()
{
    long double a360 = atan(1) * 8;
    long double a180 = atan(1) * 4;
	int n;
	cin>>n;
	for(int i = 1;i <= n; ++i)
	{
		ld x,y;//*****ld,not int
		cin>>x>>y;
		if(!x)
        {
            if(y > 0)
            {
            	D[i].f = atan(1) * 2;
            }
            else 
            {
            	D[i].f = atan(1) * 6;
            }
        }
        else
        {
            if(x > 0 && y >= 0)
            {
            	D[i].f = atan(y / x);
            }
            else if(x > 0 && y < 0)
            {
            	D[i].f = a360 + atan(y / x);
            }
            else 
            {
            	D[i].f = a180 + atan(y / x);
            }
        }
        D[i].s = i;
	}
	sort(D + 1,D + n + 1);
	D[n + 1] = D[1];
    D[n + 1].f += a360;
	ld ans = a180 + a360;
	int pos = 0;
	for(int i = 1;i <= n; ++i)
	{
		if(D[i + 1].f - D[i].f < ans)
		{
			ans = D[i + 1].f - D[i].f;
			pos = i;
		}
	}
	printf("%d %d\n",D[pos].s,D[pos + 1].s);
	return 0;
}