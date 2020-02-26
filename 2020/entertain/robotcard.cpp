//computer vs computer
/*
程序编写： 5个小时，调试1小时
功能介绍
1、实现了标准一副扑克的玩法，每个玩家轮流起三张牌，
按照炸（三张一样）>清一色>对子>单张的标准玩法
2、扑克大小王可以替换为任何一张牌（自动按照使自己牌面最大的配发）
3、第一个玩家叫赌注数额后，对方可以叫： 开牌（比大小）、
逃跑（按照上次的共识输钱），叫一个更大的赌注。
4、程序实现了，自动根据起的牌面计算赢率，根据自己持有的钱总数，
计算最佳赌注（大于时随机决定是否逃跑）
5、程序通过8次函数拟合实现了每次加赌的数额
6、程序模拟了两个计算机玩家
7、程序可以模拟每次两个玩家的牌面、叫赌注的数额、跟进数额等过程，模拟输赢多少的结果
8、程序可以修改为计算机和真人玩家的对抗
9、程序加入了多种随机数（例如牌面小时，通过叫一个大的赌注吓跑对方；
在胜算低于阀值的时候随机选择开牌而不是逃跑），最大可能的模拟真人对抗的心理
10、程序只能在命令行中玩
*/

// 使用\e[来转义颜色
// 其中\e[01;34m 代表01加粗，34蓝色
// 其中\e[01;31m 代表01加粗，31红色
// 其中\e[0m 代表还原颜色

// 字颜色码：30-39

// 30:黑色
// 31:红色
// 32:绿色
// 33:黄色
// 34:蓝色
// 35:紫色
// 36:深绿
// 37:白色

// 样式码：
// \e[0m 关闭所有属性
// \e[1m 设置高亮
// \e[4m 下划线
// \e[5m 闪烁
// \e[7m 反显
// \e[8m 消隐
//printf("\e[01;34m Hello World\e[01;31m ShellDawn \e[01;34m ^_^ !~!\e[0m\n");
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
void showresult(int fg,int winner = 0,int m = 0,int k = 0)
{
	if(fg)
	{
		for(int i = 1;i <= k; ++i) printf(" ");
		printf("\e[01;31m%d win with %d\e[0m\n",winner + 1,m);
		for(int i = 1;i <= k; ++i) printf(" ");
		printf("player %d's money is %d 	person %d's money is %d\n\n",1,player[0].money,2,player[1].money);
	}
	else
	{
		system("clear");
		printf("\e[4m> Game %d:\e[0m\n",++roundCount);
		printf("player %d's money is %d 	person %d's money is %d\n\n",1,player[0].money,2,player[1].money);
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
	while(1)
	{
		now.clear();
		player[0].setp();
		player[1].setp();
		int rounds = 9;
		int winner = rand() & 1;
		showresult(0);
		int lastmy = 0;
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
			// while(1);
			showcards();
			setvis(0,0);
			setvis(1,0);
			int last = winner;
			int my = 5;
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
		// system("clear");
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