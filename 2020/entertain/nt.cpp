#include "robotcard.hpp"
//用户大量模拟对抗，并计算最佳参数
const int maxP = 10;
const int maxRound = 30;
int cnt = 10;
robot rt[maxP + 5];
robot best;
hand h1[maxRound + 5][10],h2[maxRound + 5][10];
void setvis(int i,int j,int k,int fg)
{
	if(i == 1)
	{
		now.vis[h1[j][k].pre1.index()] = now.vis[h1[j][k].pre2.index()] = now.vis[h1[j][k].pre3.index()] = fg;
	}
	else
	{
		now.vis[h2[j][k].pre1.index()] = now.vis[h2[j][k].pre2.index()] = now.vis[h2[j][k].pre3.index()] = fg;
	}
}
bool sortm(robot x,robot y)
{
	return x.money > y.money;
}
void run(int i1,int i2)
{
	int sum = i1 + i2;
	for(int j = 1;j <= maxRound; ++j)
	{
		now.clear();
		int winner = (rand() & 1) ? i1 : i2;
		int lastmy = 0,my = 5;
		for(int k = 1;k <= 9; ++k)
		{
			rt[i1].h = h1[j][k];
			rt[i2].h = h2[j][k];
			if(k > 1)
			{
				setvis(1,j,k - 1,1);
				setvis(2,j,k - 1,1);
			}
			int last = winner;
			while(1)
			{
				int m = rt[last].nxthand(my);
				if(m >= maxMoney)
				{
					m = -2;
				}
				if(m == -1)
				{
					rt[last].money -= lastmy;
					rt[sum - last].money += lastmy;
					break;
				}
				else if(m == -2)
				{
					if(rt[sum - last].h < rt[last].h)
					{
						my *= -1;
					}
					rt[last].money -= my;
					rt[sum - last].money += my;
					break;
				}
				else
				{
					last = sum - last;
					lastmy = my;
					my = m;
				}
			}
		}
		// rt[i].money -= rt[0].money;
		// printf("rt[%d].money = %d\n",i,rt[i].money);
	}
}
int main(int argc, char const *argv[])
{
	FILE *file1 = fopen("test.txt","r");
	srand(time(NULL));
	for(int j = 1;j <= 5; ++j)
	{
		if(j == 1)
		{
			fscanf(file1,"%lf",&rt[0].f[j]);
		}
		else
		{
			fscanf(file1,",%lf",&rt[0].f[j]);
		}
	}
	for(int j = 1;j <= 3; ++j)
	{
		fscanf(file1,",%d",&rt[0].a[j]);
	}
	fclose(file1);
	rt[maxP + 1] = rt[0];
	file1 = fopen("CoE.txt","w");
	while(cnt--)
	{
		for(int i = 1;i <= maxRound; ++i)
		{
			now.clear();
			for(int j = 1;j <= 9; ++j)
			{
				// printf("\e[01;35m>>Round %d\e[0m\n",i);
				h1[i][j] = gethand();
				if(j == 9)
				{
					card cc[4];
					int nn = 0;
					for(int k = 0;k < allcount; ++k)
					{
						if(!now.vis[k])
						{
							cc[++nn] = tocard(k);
						}
					}
					h2[i][j] = hand(cc[1],cc[2],cc[3]);
				}
				else
				{
					h2[i][j] = gethand();
				}
				// while(1);
				// showcards();
				setvis(1,i,j,1);
				setvis(2,i,j,1);
			}
		}
		// rt[0].setp(1);
		for(int i = 1;i <= maxP; ++i)
		{
			rt[i].setp();
		}
		for(int i = 1;i <= maxP; ++i)
		{
			rt[0].money = 0;
			rt[i].money = 0;
			run(0,i);
		}
		sort(rt + 1,rt + maxP + 1,sortm);
		int lastp = rt[1].money;
		rt[1].money = 0,rt[maxP + 1].money = 0;
		run(1,maxP + 1);
		if(rt[maxP + 1].money < rt[1].money)
		{
			rt[maxP + 1] = rt[1];
		}
		rt[1].money = lastp;
		for(int i = 1;i <= maxP; ++i)
		{
			printf("**%d ",rt[i].money);
			for(int j = 1;j <= 5; ++j)
			{
				printf("%.2lf ",rt[i].f[j]);
			}
			for(int j = 1;j <= 3; ++j)
			{
				printf("%2d ",rt[i].a[j]);
			}
			printf("\n");
		}
		int LastM = 0;
		for(int i = 1;i <= maxP; ++i)
		{
			if(rt[i].money < 0)
			{
				LastM = i;
				break;
			}
		}
		for(int j = 1;j <= 5; ++j)
		{
			// printf("%.2lf ",rt[i].f[j]);
			rt[0].f[j] *= (LastM + 1);
		}
		for(int j = 1;j <= 3; ++j)
		{
			rt[0].a[j] *= (LastM + 1);
		}
		int del = LastM + 1;
		for(int i = 1;i <= maxP; ++i)
		{
			if(rt[i].money < 0)
			{
				break;
			}
			del += LastM - i + 1;
			for(int j = 1;j <= 5; ++j)
			{
				// printf("%.2lf ",rt[i].f[j]);
				rt[0].f[j] += rt[i].f[j] * (LastM - i + 1.0);
				// printf("del = %d\n",del);
			}
			for(int j = 1;j <= 3; ++j)
			{
				rt[0].a[j] += rt[i].a[j] * (LastM - i + 1);
				// del += LastM - i + 1;
			}
		}
		for(int j = 1;j <= 5; ++j)
		{
			// printf("%.2lf ",rt[i].f[j]);
			rt[0].f[j] /= ld(del + 0.0);
			// rt[0].f[j] = rt[1].f[j];
			fprintf(file1,"%.6lf,",rt[0].f[j]);
			printf("%.6lf,",rt[0].f[j]);
		}
		for(int j = 1;j <= 3; ++j)
		{
			rt[0].a[j] /= del;
			// rt[0].a[j] = rt[1].a[j];
			fprintf(file1,"%d,",rt[0].a[j]);
			printf("%d,",rt[0].a[j]);
		}
		fprintf(file1,"\n");
		printf("\n");
	}
	fprintf(file1,"best is:");
	for(int j = 1;j <= 5; ++j)
	{
		fprintf(file1,"%.6lf,",rt[maxP + 1].f[j]);
	}
	for(int j = 1;j <= 3; ++j)
	{
		fprintf(file1,"%d,",rt[maxP + 1].a[j]);
	}
	fprintf(file1,"\n");
	fclose(file1);
	return 0;
}