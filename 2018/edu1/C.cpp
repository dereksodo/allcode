#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long double ld;
typedef struct point{
	int x,y;
	point(ld x = 0,ld y = 0):x(x),y(y){};
}Point;
//θ=atan2(v2.y,v2.x)−atan2(v1.y,v1.x)
//需要注意的是：atan2的取值范围是[−π,π]，
//在进行相减之后得到的夹角是在[−2π,2π]，
//因此当得到的结果大于π时，对结果减去2π，
//当结果小于−π时，对结果加上2π
//cosθ = (x1x2+y1y2)/[√[x1^2+y1^2]*√[x2^2+y2^2]];
//return (a.x * b.x + a.y * b.y) / (sqrt(a.x * a.x + a.y * a.y) * sqrt(b.x * b.x + b.y * b.y));
// ld solve(Point a,Point b)
// {
// 	ld ret = atan2(b.y,a.x) - atan2(a.y,b.x);
// 	if(ret < -)
// 	return atan2(b.y,a.x) - atan2(a.y,b.x);
// }
ld solve(Point a,Point b)
{
	return acos((a.x * b.x + a.y * b.y) / (sqrt(a.x * a.x + a.y * a.y) * sqrt(b.x * b.x + b.y * b.y)));
}
vector< pair<ld,int> > k;
int main()
{
	int n;
	cin>>n;
	int ansi = 0,ansj = 0;
	ld ans = 400.0;
	for(int i = 1;i <= n; ++i)
	{
		int x,y;
		cin>>x>>y;
		printf("%LF\n",solve(Point(0,0),Point(x,y)));
		k.push_back(make_pair(solve(Point(0,0),Point(x,y)),i));
	}
	sort(k.begin(),k.end());
	for(int i = 0;i < k.size() - 1; ++i)
	{
		if(k[i + 1].first - k[i].first < ans)
		{
			ans = k[i + 1].first - k[i].first;
			ansi = k[i].second;
			ansj = k[i + 1].second;
		}
	}
	printf("%d %d\n",ansi,ansj);
	return 0;
}