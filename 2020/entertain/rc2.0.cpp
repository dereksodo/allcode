//computer vs human
//用户人和电脑对抗，可以看到每次牌面信息和赌注信息
#include "robotcard.hpp"

void checkallfunc()
{
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
	while(1)
	{
		now.clear();
		player[0].setp1(8.176648,4.778467,6.318363,0.751499,0.048878,49,10,6,-1);
		// player[1].setp();
		int winner = rand() & 1;
		showresult(0);
		for(int i = 1;i <= rounds; ++i)
		{
			printf("\e[01;35m>>Round %d\e[0m\n",i);
			player[0].h = gethand();//computer
			// printf("hi\n");
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
				player[1].h = gethand();//human
			}
			// while(1);
			showcards(1,1);
			setvis(0,0);
			setvis(1,0);
			int last = winner;
			int my = 5;
			int lastmy = 5;
			printf(">>>Bid:\n");
			printf("\e[01;36m   desert,open,or input the amount(>= 5)\e[0m\n");
			while(1)
			{
				int m;
				if(last == 0)
				{
					m = player[last].nxthand(my);
					printf("  :");
					print(last,m,0,-1);
					if(m < 0)
					{
						printf("\n");
					}
				}
				else
				{
					printf("  :");
					//-1:desert  -2:open
					// scanf("%d",&m);
					char buf[100];
					scanf(" %s",buf);
					if(isdigit(buf[0]))
					{
						m = 0;
						for(int ki = 0;ki < strlen(buf); ++ki)
						{
							m = m * 10 + buf[ki] - '0';
						}
					}

					else
					{
						if(buf[0] == 'd')
						{
							m = -1;
						}
						else if(buf[0] == 'o')
						{
							m = -2;
						}
						else
						{
							printf("***\e[01;31mInput Not Correct!\e[0m\n");
							continue;
						}
					}
					// m = -1;
					if((m >= 0 && ((m < my) && lastmy != 0)) || (m < -2))
					{
						printf("***\e[01;31mthe amount need to be -1,-2 or >= %d\e[0m\n",my);
						continue;
					}
					if(m == my)
					{
						m = -2;
					}
					if(m < 0)
					{
						print(last,m,3);
						printf("\n");
					}
				}
				if(m >= maxMoney)
				{
					m = -2;
				}
				if(m < 0)
				{
					printf("\e[01;31m");
					printf("   Computer's Card:");
					player[0].deg(0,1,1);
					printf("\e[0m\n");
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
			printf("finish round %d\n",i);
		}
		printf("\e[01;34mGame ends\e[0m\n");
		printf("\e[01;35mplayer %d:%d\nplayer %d:%d\e[0m\n",1,player[0].money,2,player[1].money);
		getchar();
	}
	return 0;
}