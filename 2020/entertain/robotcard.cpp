#include <iostream>
#include <cstring>
#include <cstdlib>
#include <set>
#include <vector>
#include <map>
#include <cstdio>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <cassert>
#include <climits>
#include <numeric>
#include <sstream>
using namespace std;
typedef long long ll;
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
const int maxc = 4;
const int maxe = 13;
const int allcount = 54;
const int maxn = 1e8;
//S:spade   3 best
//H:heart   2
//C:club    1
//D:diamond 0
//
struct card{
	int dot,suit;
	int index()
	{
		if(dot > maxe)//two kings
		{
			return dot + 39;
		}
		return dot * 4 + suit - 4;
	}
	void input_from_sc()
	{
		char sui;
		scanf("%d %c",&dot,&sui);
		suit = 0;
		if(sui == 'S')
		{
			suit = 3;
		}
		else if(sui == 'H')
		{
			suit = 2;
		}
		else if(sui == 'C')
		{
			suit = 1;
		}
		if(dot <= 13)
		{
			dot--;
			if(dot == 0)
			{
				dot = 13;
			}
		}
	}
	void deg()
	{
		int dott = dot;
		if(dott <= 13)
		{
			dott++;
			if(dott == 14)
			{
				dott = 1;
			}
		}
		char ch = 'D';
		if(suit == 3)
		{
			ch = 'S';
		}
		else if(suit == 2)
		{
			ch = 'H';
		}
		else if(suit == 1)
		{
			ch = 'C';
		}
		printf("%d %c\n",dott,ch);
	}
	card(int a = 0,int b = 0)
	{
		dot = a,suit = b;
	}
	int samedot(const card &b)const
	{
		return dot == b.dot;
	}
	int samesuit(const card &b)const
	{
		return suit == b.suit;
	}
};
card tocard(int k)
{
	return card(k / 4 + 1,k % 4);
}
int nxt(int k)
{
	if(k != 13)
	{
		return k + 1;
	}
	else
	{
		return 1;
	}
}
struct situation{
	int vis[allcount + 5];
	int p1,p2;
	void clear()
	{
		memset(vis,0x00,sizeof(vis));
	}
}now;
struct hand{
	card c1,c2,c3;
	int pri;//priority (the less the better)
	int p2;//if the priorities are same,check this (the bigger the better)
	void sort()
	{
		if(c1.index() > c2.index())
		{
			swap(c1,c2);
		}
		if(c1.index() > c3.index())
		{
			swap(c1,c3);
		}
		if(c2.index() > c3.index())
		{
			swap(c2,c3);
		}
	}
	void best()
	{
		if(c2.dot > maxe)
		{
			c3 = c2 = c1;
		}
		else
		{
			hand cur = hand(c1,c2,card(2,1));
			int k = card(2,1).index();
			for(int i = 1;i <= allcount - 2; ++i)
			{
				if(!now.vis[i] && tocard(i).dot <= 13)
				{
					if(cur < hand(c1,c2,tocard(i)))
					{
						cur = hand(c1,c2,tocard(i));
						k = i;
					}
				}
			}
			c3 = tocard(k);
			sort();
		}
	}
	void getpri()
	{
		sort();
		if(c2.dot > maxe || c3.dot > maxe)
		{
			best();
		}
		if(c1.samedot(c2) && c2.samedot(c3))
		{
			pri = 0;//KKK
			p2 = c1.dot * 14 * 14 + c1.suit * 14 + c2.suit;
		}
		else if((nxt(c1.dot) == c2.dot && nxt(c2.dot) == c3.dot)
				|| (nxt(c2.dot) == c3.dot && nxt(c3.dot) == c1.dot)
				|| (nxt(c3.dot) == c1.dot && nxt(c1.dot) == c2.dot))
		{
			if(c1.samesuit(c2) && c2.samesuit(c3))
			{
				pri = 1;
				p2 = c3.dot * 14 + c3.suit;
			}
			else
			{
				pri = 2;//567
				p2 = c3.dot * 14 + c3.suit;
			}
		}
		else if(c1.samesuit(c2) && c2.samesuit(c3))
		{
			pri = 3;//2S,4S,5S
			p2 = c3.dot * 14 * 14 * 14 + c2.dot * 14 * 14 + c1.dot * 14 + c1.suit;
		}
		else if(c1.dot == c2.dot)
		{
			pri = 4;
			p2 = c1.dot * 14 * 14 + c3.dot * 14 + c3.suit;
		}
		else if(c2.dot == c3.dot)
		{
			pri = 4;
			p2 = c2.dot * 14 * 14 + c1.dot * 14 + c1.suit;
		}
		else
		{
			pri = 5;
			p2 = c3.dot * 14 * 14 * 14 + c2.dot * 14 * 14 + c1.dot * 14 + c3.suit;
		}
	}
	hand(card cc1 = card(),card cc2 = card(),card cc3 = card())
	{
		c1 = cc1,c2 = cc2,c3 = cc3;
		getpri();
	}
	void deg()
	{
		// printf("p1 = %d,p2 = %d\n",pri,p2);
		c1.deg(),c2.deg(),c3.deg();
		printf("the probility of winning is %.6lf%c\n",winprobe() * 100,'%');
	}
	bool operator <(const hand &b)const
	{
		if(pri > b.pri)
		{
			return 1;
		}
		else if(pri < b.pri)
		{
			return 0;
		}
		return p2 < b.p2;
	}
	bool operator >(const hand &b)const
	{
		return !((*this) < b);
	}
	double winprobe()
	{
		int p1 = 0,p2 = 0;
		for(int i = 1;i <= allcount; ++i)
		{
			if(now.vis[i])
			{
				continue;
			}
			for(int j = i + 1;j <= allcount; ++j)
			{
				if(now.vis[j])
				{
					continue;
				}
				for(int k = j + 1;k <= allcount; ++k)
				{
					if(now.vis[k])
					{
						continue;
					}
					if((*this) < hand(tocard(i),tocard(j),tocard(k)))
					{
						p1++;
					}
					p2++;
				}
			}
		}
		// printf("all:%d,win:%d\n",p2,p2 - p1);
		return (p2 - p1 + 0.0) / (p2 + 0.0);
	}
};
int check(double p)
{
	return (rand() * rand()) % maxn < int(p * (maxn + 0.0));
}
struct robot{
	hand h;
	int money;
	double f1;//desert
	double f2;//scare
	int plus = 30;
	void setp()
	{
		money = 200;
		// f1 = (((rand() + rand()) % (maxn / 1000)) + 0.0) / 1e7;
		// f2 = (((rand() + rand()) % (maxn / 1000)) + 0.0) / 1e7;
		// printf("f1 = %.2lf,f2 = %.2lf\n",f1,f2);
		f1 = 0.05;
		f2 = 0.03;
	}
	void input_from_sc()
	{
		card cc1,cc2,cc3;
		cc1.input_from_sc();
		cc2.input_from_sc();
		cc3.input_from_sc();
		h = hand(cc1,cc2,cc3);
		now.vis[cc1.index()] = now.vis[cc2.index()] = now.vis[cc3.index()] = 1;
	}
	//every time the amount must be a multiple of 5
	int nxthand(int other)//-1:desert  -2:open  >0:keep going
	{
		if(check(f1))
		{
			return -1;
		}
		if(check(f2))
		{
			return other + plus;
		}
		double pro = h.winprobe();
		int k;
		if(pro > 0.6)
		{
			return other + 5;
		}
		else if(fabs(pro - 0.5) < 0.1)
		{
			return -2;
		}
		else
		{
			if(other > money * 1.5)
			{
				return -1;
			}
			else if(other > money * 0.5)
			{
				return -2;
			}
			else
			{
				return other + 5;
			}
		}
	}
}player[2];
card getcard()
{
	int k = rand() % 54 + 1;
	while(now.vis[k])
	{
		k = rand() % 54 + 1;
	}
	now.vis[k] = 1;
	return tocard(k);
}
hand gethand()
{
	return hand(getcard(),getcard(),getcard());
}
void print(int p,int op)
{
	if(op == -2)
	{
		printf("person %d runs away\n",p + 1);
	}
	else if(op == -1)
	{
		printf("person %d asks to open the cards\n",p + 1);
	}
	else
	{
		printf("person %d asked to %d\n",p + 1,op);
	}
}
void checkallfunc()
{
	// hand a1 = gethand();
	// hand a2 = gethand();
	robot a1,a2;
	a1.input_from_sc();
	a2.input_from_sc();
	a1.h.deg();
	a2.h.deg();
	printf("%d win\n",a1.h < a2.h ? 2 : 1);
	getchar();
}
int main(int argc, char const *argv[])
{
	srand(time(NULL));
	while(1)
	{
		checkallfunc();
	}
	while(1)
	{
		now.clear();
		player[0].setp();
		player[1].setp();
		int rounds = 9;
		while(rounds--)
		{
			player[0].h = gethand();
			player[1].h = gethand();
			// while(1);
			player[0].h.deg();
			player[1].h.deg();
			int last = rand() & 1;
			int my = 5;
			int winner = 0;
			while(1)
			{
				int first = player[last].nxthand(my);
				print(last,first);
				if(first == -1)
				{
					player[last].money -= my;
					player[last ^ 1].money += my;
					winner = last ^ 1;
					break;
				}
				else if(first == -2)
				{
					printf("%d and %d\n",last,last ^ 1);
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
				last ^= 1;
				getchar();
			}
			printf("%d win\n",winner + 1);
			printf("actually %d win\n",player[0].h < player[1].h ? 2 : 1);
			printf("amount:%d\n",my);
		}
		printf("money:\np1:%d,p2:%d\n",player[0].money,player[1].money);
		getchar();
	}
	return 0;
}