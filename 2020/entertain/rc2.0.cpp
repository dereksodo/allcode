//computer vs human
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
void showresult(int fg,int winner = 0,int m = 0)
{
	if(fg)
	{
		printf("%d win with %d\n",winner + 1,m);
		printf("player %d's money is %d 	person %d's money is %d\n\n",1,player[0].money,2,player[1].money);
	}
	else
	{
		printf("> Round %d:\n",roundCount++);
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
		++roundCount;
		now.clear();
		player[0].setp();
		player[1].setp();
		int winner = rand() & 1;
		// showresult(0);
		int lastmy = 0;
		for(int i = 1;i <= rounds; ++i)
		{
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
			showcards();
			setvis(0);
			int last = winner;
			int my = 5;
			while(1)
			{
				int m;
				if(last == 0)
				{
					m = player[last].nxthand(my);
					print(last,m,0);
				}
				else
				{
					//-1:desert  -2:open
					scanf("%d",&m);
					// m = -1;
				}
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
			setvis(1);
			showresult(1,winner,my);
			printf("finish round %d\n",i);
		}
		printf("Game ends\n");
		printf("player %d:%d\nplayer %d:%d",1,player[0].money,2,player[1].money);
		// getchar();
	}
	return 0;
}