#include <iostream>
#include <queue>
using namespace std;
int main(int argc, char const *argv[])
{
	priority_queue<int> pq;
	int n;
	cin>>n;
	for(int i = 0;i < n; ++i)
	{
		int x;
		scanf("%d",&x);
		pq.push(x);
	}
	int ans = 0;
	while(pq.size() != 1)
	{
		int x = pq.top();
		pq.pop();
		int y = pq.top();
		pq.pop();
		ans += x + y;
		printf("ans += %d + %d\n",x,y);
		pq.push(x + y);
	}
	cout<<ans<<endl;
	return 0;
}