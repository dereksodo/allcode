#include <iostream>
#include <cstring>
#include <sstream>
#include <cstdio>
using namespace std;
const int maxn = 305;
int G[maxn][maxn];//邻接矩阵
int leaf[maxn];//叶子编号
int vis[maxn];//vis[]
int ans[maxn * 2];//路径
int n,c;
//a->father,b->son
int go(int a,int b) 
{
	if(a == b) 
	{
		return 1;//如果已经到达叶子节点或根节点,回溯
	}
	vis[a] = 1;//被vis过了
	int i = 1;
	for(;i <= n; ++i)
	{
		if(G[a][i] && !vis[i])//联通但没有vis过
		{
			if(go(i,b))//增加从i->b的路径
			{
				G[a][i] = 0;//已经被访问过了一次了
				ans[c] = a;//把父节点放入ans中
				c++;//下一个坐标
				break;
			}
		}	
	}
	return i <= n;//有子节点
}
int main(int argc,char const *argv[]) 
{
	scanf("%d\n",&n);
	for(int i = 1;i < n; ++i) 
	{
		int a,b;
		scanf("%d %d\n",&a,&b);
		G[a][b] = G[b][a] = 1;
	}
	leaf[0] = 1;
	int k = 1;
	while (EOF != scanf("%d",&leaf[k]))//读入叶子节点
	{
		k++;
	}
	leaf[k] = 1;
	int i = k;
	for(;i; --i) 
	{
		if(!go(leaf[i - 1],leaf[i]))//?
		{
			break;
		}
		memset(vis,0x00,sizeof(vis));
	}
	if(i)
	{
		printf("-1\n");
		return 0;
	}
	for(int i = c - 1;i >= 0; --i) 
	{
		printf("%d ",ans[i]);
	}
	printf("1\n");
	return 0;
}