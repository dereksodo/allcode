#include <stdio.h>

#define N 301

int x[N][N];//邻接矩阵
int l[N];//叶子编号
int v[N];//vis[]
int p[2*N];//路径
int n,c;
//a->father,b->son
int go(int a,int b) {
	if (a==b) return 1;//如果已经到达叶子节点或根节点,回溯
	v[a]=1;//已经被
	int i = 1;
	for (;i<=n;i++)
		if (x[a][i]&&!v[i])
			if (go(i,b)) {
				x[a][i]=0;
				p[c++]=a;
				break;
			}
	return i<=n;
}
int main() {
	int i,k,a,b;
	scanf("%d\n",&n);
	for (i=1;i<n;i++) {
		scanf("%d %d\n",&a,&b);
		x[a][b]=x[b][a]=1;//临接矩阵x填充
	}
	l[0]=1;//叶子
	k=1;//叶子总数
	while (EOF!=scanf("%d",&l[k])) k++;
	l[k]=1;
	for (i=k;i;i--) {
		if (!go(l[i-1],l[i])) break;
		int j;
		for (j=1;j<=n;j++) v[j]=0;
	}
	if (i) printf("-");
	else for (i=c-1;i>=0;i--) printf("%d ",p[i]);
	printf("1\n");
	return 0;
}