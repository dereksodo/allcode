//computer vs computer  step by step
// 用于查看电脑和电脑对抗，可以分析每次对抗的参数
#include "robotcard.hpp"

void checkallfunc()
{
	// hand a1 = gethand();
	// hand a2 = gethand();
	// robot a1,a2;
	// a1.input_from_sc();
	// a2.input_from_sc();
	// a1.h.deg();
	// a2.h.deg();
	// printf("%d win\n",a1.h < a2.h ? 2 : 1);
	// getchar();
	// tocard(53).deg();
	// player[0].input_from_sc();
	// player[1].input_from_sc();
	// player[0].deg();
	// printf("%.2lf %.2lf\n",player[0].h.winprobe(),ceil(maxamount(player[0].h.winprobe())));
	for(int i = 0;i < allcount; ++i)
	{
		tocard(i).deg();
		printf("\n");
		if(tocard(i).index() != i)
		{
			printf("ERROR %d\n",i);
		}
	}
}
int main(int argc, char const *argv[])
{
	init();
	// while(1)
	// {
	// 	checkallfunc();
	// 	getchar();
	// }
	int M1 = 0,M2 = 0;
	int Cnt = 0;
	while(1)
	{
		++Cnt;
		now.clear();
		player[1].setp1(4.713712,4.327479,4.323815,3.836897,4.806396,33,45,29);
		player[0].setp1(4.713712,4.327479,4.323815,0.476375,0.519601,33,45,29);
		int rounds = 9;
		int winner = rand() & 1;
		showresult(0);
		for(int i = 1;i <= rounds; ++i)
		{
			printf("\e[01;35m>>Round %d\e[0m\n",i);
			player[0].h = gethand();
			if(i == 9)
			{
				card cc[4];
				int nn = 0;
				for(int j = 0;j < allcount; ++j)
				{
					if(!now.vis[j])
					{
						cc[++nn] = tocard(j);
					}
				}
				player[1].h = hand(cc[1],cc[2],cc[3]);
			}
			else
			{
				player[1].h = gethand();
			}
			swap(player[0].h,player[1].h);
			// while(1);
			showcards();
			setvis(0,0);
			setvis(1,0);
			int last = winner;
			int my = 5;
			int lastmy = 0;
			printf(">>>Bid:\n");
			while(1)
			{
				int m = player[last].nxthand(my);
				print(last,m,3);
				if(m >= maxMoney)
				{
					m = -2;
				}
				if(m == -1)
				{
					player[last].money -= lastmy;
					player[last ^ 1].money += lastmy;
					winner = last ^ 1;
					my = lastmy;
					break;
				}
				else if(m == -2)
				{
					if(player[last].h < player[last ^ 1].h)
					{
						player[last].money -= my;
						player[last ^ 1].money += my;
						winner = last ^ 1;
					}
					else
					{
						player[last].money += my;
						player[last ^ 1].money -= my;
						winner = last;
					}
					break;
				}
				else
				{
					last ^= 1;
					lastmy = my;
					my = m;
				}
			}
			setvis(0,1);
			setvis(1,1);
			showresult(1,winner,my,3);
			getchar();
		}
		printf("\e[01;34mGame ends\e[0m\n");
		printf("\e[01;35mplayer %d:%d\nplayer %d:%d\e[0m\n",1,player[0].money,2,player[1].money);
		getchar();
		system("clear");
	}
	return 0;
}



//拟合曲线
//参数表
// 0.1,0.016667
// 0.2,0.03334
// 0.3,0.05
// 0.4,0.08334
// 0.5,0.11667
// 0.6,0.16667
// 0.7,0.2
// 0.8,0.33334
// 0.9,0.1
//方程
//coEfficient