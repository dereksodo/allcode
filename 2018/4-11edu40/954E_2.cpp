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

//高温先加
bool cmp2(tap a,tap b)
{
	return a.t > b.t;
}
int main()
{
	int n,T;
	cin>>n>>T;
	tap tp[n];
	int flag=1;
	for(int i = 0;i < n; ++i)
	{
		cin>>tp[i].a;
	}
	double cur = 0;
	double total=0.0;
	for(int i = 0;i < n; ++i)
	{
		cin>>tp[i].t;
		//tp[i].t -= T;
		cur += tp[i].a * tp[i].t;
		total+=tp[i].a;
	}
	if(cur <= total*T)//全部装入如果小，先装入温度高的水，如果大于零则先装入温度低的水
	{
		flag=0;
		sort(tp,tp + n,cmp2);
	}
	else
	{
		flag=1;//低温优先
		sort(tp,tp + n,cmp);
	}
	double suma = 0,sum=0,ans = 0;

	//value = (ai*xi)/xi
	for(int i = 0;i < n; ++i)
	{
		sum += tp[i].a * tp[i].t;
		suma+=tp[i].a;
			
		//printf("%lf\n",sum / suma);
		ans += tp[i].a;
		double bb = fabs(((sum/suma-T)*(suma-tp[i].a))/(tp[i].t+T-sum/suma));
		if(flag)
		{
			if(sum/suma - T > 0)
			{
				printf("diff1=%.12lf\n",sum/suma-T);
				ans -= bb;
				break;
			}
		}
		else
		{
			if(sum/suma - T < 0)
			{
				printf("diff2=%.12lf\n",sum/suma-T);
				ans -= bb;
				break;
			}
		}

		
	}
	printf("%.12lf\n",fabs(ans));
	return 0;
}