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
typedef double ld;
typedef long long ll;
// #define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
const int maxc = 4;
const int maxe = 13;
const int allcount = 54;
const int maxn = 1e8;
const ld maxMoney = 200;
const int rounds = 9;

//S:spade   3 best
//H:heart   2
//C:club    1
//D:diamond 0
//
const long double coEfficient[] = {-232.3887046529465,776.4988804629082,-1028.2781462522344,696.455873160383,-259.9968460672559,54.1023162194713,-5.8004693588153,0.4070740389146,-0.0000116211147};
ld mypow(ld p,int t)
{
	ld res = 1.0;
	while(t--)
	{
		res *= p;
	}
	return res;
}
ld maxamount(ld p)
{
	long double res = 0.0;
	for(int i = 8;i >= 0; --i)
	{
		res += coEfficient[8 - i] * mypow(p,i);
	}
	res = (double)res * maxMoney;
	return res;
}
int nxt(int k)
{
	if(k < maxe)
	{
		return k + 1;
	}
	else if(k == maxe)
	{
		return 1;
	}
	else
	{
		return k;
	}
}
int roundCount;
struct card{
	int dot,suit;
	int index()
	{
		if(dot > maxe)//two kings
		{
			return dot + (allcount - 2 - 14);
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
		int dott = nxt(dot);
		if(dott == 0)
		{
			printf("%d",index());
			printf("ERROR!\n");
			while(1);
		}
		if(dott <= 9)
		{
			printf(" ");
		}
		printf("%d",dott);
		if(suit == 3)
		{
			printf("♠️");
		}
		else if(suit == 2)
		{
			printf("♥️");
		}
		else if(suit == 1)
		{
			printf("♣️");
		}
		else
		{
			printf("♦️");
		}
		if(dott > maxe)
		{
			printf("(king)");
		}
	}
	card(int a = 2,int b = 0)
	{
		suit = b;
		dot = a;
		if(dot <= 13)
		{
			dot--;
			if(dot == 0)
			{
				dot = 13;
			}
		}
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
card to_card[allcount + 5];
card tocard(int k)
{
	return to_card[k];
}
void init()
{
	srand(time(NULL));
	for(int i = 1;i <= 13; ++i)
	{
		for(int j = 0;j < 4; ++j)
		{
			card now = card(i,j);
			to_card[now.index()] = now;
		}
	}
	card now = card(14,3);
	to_card[now.index()] = now;
	now = card(15,3);
	to_card[now.index()] = now;
}

struct situation{
	int vis[allcount + 5];
	void clear()
	{
		memset(vis,0x00,sizeof(vis));
	}
}now;
struct hand{
	card c1,c2,c3;
	card pre1,pre2,pre3;
	int pri;//priority (the less the better)
	int p2;//if the priorities are same,check this (the bigger the better)
	int king1,king2;//if you have a king in your hand
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
			king1 = king2 = 1;
			c3 = c2 = c1;
		}
		else
		{
			king2 = 1;
			hand cur = hand(c1,c2,card(2,0));
			int k = card(2,0).index();
			for(int i = 0;i < allcount - 2; ++i)
			{
				if(cur < hand(c1,c2,tocard(i)))
				{
					cur = hand(c1,c2,tocard(i));
					k = i;
				}
			}
			c3 = tocard(k);
			sort();
		}
	}
	void getpri()
	{
		king1 = king2 = 0;
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
		pre1 = c1,pre2 = c2,pre3 = c3;
		getpri();
	}
	void deg()
	{
		debug("p1 = %d,p2 = %d\n",pri,p2);
		debug("c1.dot = %d\n",c1.dot);
		c1.deg();
		printf("  ");
		c2.deg();
		if(king1)
		{
			printf("(king)");
		}
		printf("  ");
		c3.deg();
		if(king2)
		{
			printf("(king)");
		}
		printf("  ");
		ld result = winprobe() * 100;
		if(result < 0.1)
		{
			printf(" ");
		}
		printf("win pro: %.3lf%c",result,'%');
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
	ld winprobe()
	{
		int p1 = 0,p2 = 0;
		now.vis[pre1.index()] = now.vis[pre2.index()] = now.vis[pre3.index()] = 1;
		for(int i = 0;i < allcount; ++i)
		{
			if(now.vis[i])
			{
				continue;
			}
			for(int j = i + 1;j < allcount; ++j)
			{
				if(now.vis[j])
				{
					continue;
				}
				for(int k = j + 1;k < allcount; ++k)
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
		now.vis[pre1.index()] = now.vis[pre2.index()] = now.vis[pre3.index()] = 0;
		// printf("all:%d,win:%d\n",p2,p2 - p1);
		if(p2 == 0)
		{
			return 0.0;
		}
		return (p2 - p1 + 0.0) / (p2 + 0.0);
	}
};
int check(ld p)
{
	return abs(rand() + rand() * rand()) % maxn < int(p * (maxn + 0.0));
}
struct robot{
	hand h;
	int money;
	ld f[30];
	int a[30];
	int getrnd(int pos)
	{
		return ((rand() % a[pos]) / 3 * ((int(maxMoney) / 50)) + 2) % 210;
	}
	void setp()
	{
		money = int(maxMoney);
		f[1] = 1.5;
		f[2] = 1.1;
		f[3] = 0.2;
		a[1] = 20;
		a[2] = 10;
		a[3] = 5;
		f[4] = 0.1;
		f[5] = 0.2;
	}
	void deg(int k)
	{
		while(k--)
		{
			printf(" ");
		}
		h.deg();
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
	int nxthand(int other)//-1:desert  -2:open  >0:keep going
	{
		ld pro = h.winprobe();
		ld maxmoney = maxamount(pro);
		int res = ceil(maxmoney);//anthing you want
		debug("res = %d,other = %d\n",res,other);
		if(ld(other) * f[1] < ld(res))
		{
			return other + getrnd(1);
		}
		else if(ld(other) * f[2] < ld(res))
		{
			return other + getrnd(2);
		}
		else if(ld(abs(other - res)) < ld(res) * f[3])
		{
			return other + getrnd(3);
		}
		else if(ld(res) * f[1] > ld(other))
		{
			if(check(f[5]))
			{
				return other + getrnd(1) * 5;
			}
			return -2;
		}
		else
		{
			debug("%.2lf %.2lf\n",ld(res) * f[1],ld(other));
			if(check(f[4]))
			{
				debug("-2:rand\n");
				return -2;
			}
			else
			{
				debug("-1:rational\n");
				return -1;
			}
		}
	}
}player[2];
card getcard()
{
	int k = rand() % allcount;
	while(now.vis[k])
	{
		k = rand() % allcount;
	}
	// if(k > 51)
	// {
	// 	printf("yes\n");
	// }
	now.vis[k] = 1;
	// tocard(k).deg();
	// printf("\n");
	return tocard(k);
}
hand gethand()
{
	return hand(getcard(),getcard(),getcard());
}
void print(int p,int op,int cnt)
{
	if(op < 0)
	{
		printf("\n>>>Result:\n");
	}
	while(cnt--)
	{
		printf(" ");
	}
	if(op == -1)
	{
		printf("person %d runs away    ",p + 1);
	}
	else if(op == -2)
	{
		printf("person %d asks to open the cards    ",p + 1);
	}
	else
	{
		
		printf("person %d asked to %d\n",p + 1,op);
	}
}
void setvis(int k,int fg)
{
	now.vis[player[k].h.pre1.index()] = now.vis[player[k].h.pre2.index()] = now.vis[player[k].h.pre3.index()] = fg;
}
void showcards()
{
	printf(">>>Info:\n");
	printf("   player %d:",1);
	player[0].deg(3);
	printf("    amount:%.2lf\n",maxamount(player[0].h.winprobe()));
	printf("   player %d:",2);
	player[1].deg(3);
	printf("    amount:%.2lf\n\n",maxamount(player[1].h.winprobe()));
}