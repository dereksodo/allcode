#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
typedef struct{
	double a;
	double t;
}tap;
bool cmp(tap a,tap b)
{
	return a.t < b.t;
}
int main()
{
	int n,T;
	cin>>n>>T;
	tap tp[n];
	for(int i = 0;i < n; ++i)
	{
		cin>>tp[i].a;
	}
	double cur = 0;
	for(int i = 0;i < n; ++i)
	{
		cin>>tp[i].t;
		tp[i].t -= T;
		cur += tp[i].a * tp[i].t;
	}
	if(cur < 0)//全部装入如果小于零，装入温度高的水，如果大于零则先装入温度低的水
	{
		for(int i = 0;i < n; ++i)
		{
			tp[i].t = T-tp[i].t;
		}
	}
	sort(tp,tp + n,cmp);
	double sum = 0,ans = 0;
	//value = (ai*xi)/xi
	for(int i = 0;i < n; ++i)
	{
		if(sum + tp[i].a * tp[i].t <= 0)
		{
			sum += tp[i].a * tp[i].t;
			ans += tp[i].a;
		}
		else
		{
			ans -= sum / (tp[i].t);
			break;
		}
	}
	printf("%.12lf\n",fabs(ans));
	return 0;
}