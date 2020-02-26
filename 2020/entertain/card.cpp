/*
Author： zjd
Functions: 春节打牌记分程序
1、支持多人积分
2、支持按照名称简写或者序号1 2 30（表示第一个玩家输给第二个玩家30元）
3、支持负数
4、支持积分保存下次恢复
5、支持各种错误判断
6、已经测试了一天，超过30轮斗地主，没有🙅‍

运行平台： macos或者linux
./card (进入terminal) 后面根据提示就可以使用了😊

*/
#include <iostream>
#include <cstring>
#include <map>
#include <cstdio>
using namespace std;
typedef long long ll;
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
using namespace std;
const int maxn = 105;
const int MaxLen = 64;
int a[maxn];//money
int b[maxn];//last round
int Num;//number of people
map<int,string> mp;//name
map<string,int> mp2;
string s;
int KeyNameCnt = 5;
string KeyName[] = {"end","clear","rand","return","quit"};
int rnd()
{
	return rand() % Num + 1;
}
int check_key(string s)
{
	for(int i = 0;i < KeyNameCnt; ++i)
	{
		if(s.find(KeyName[i]) != string::npos)
		{
			return i;
		}
	}
	return -1;
}
void show()
{
	system("clear");
	for(int i = 1;i <= Num; ++i)
	{
		printf("%s : %d\n",mp[i].c_str(),a[i]);
	}
	for(int i = 1;i <= 3; ++i)
	{
		printf("\n");
	}
}
void tol(string ss)
{
	for(int i = 0;i < ss.size(); ++i)
	{
		tolower(ss[i]);
	}
}
int cntsp(string ss)
{
	int cnt = 0;
	for(int i = 0;i < ss.size(); ++i)
	{
		cnt += (ss[i] == ' ');
	}
	return cnt;
}
void input()
{
	printf("Input the number of people.\n");

	while(cin>>Num)
	{
		if(Num <= 0 || Num > MaxLen)
		{
			printf("Input number should be within 1 ~ %d.\n",MaxLen);
		}
		else
		{
			break;
		}
	}
	
	printf("Input Names.\n");
	getchar();
	string s;
	int p = 0;
	while(p < Num)
	{
		printf("Input %d(th) name.\n",p + 1);
		while(getline(cin,s))
		{
			int ss = check_key(s);
			if(s.size() == 0 || s.size() > MaxLen)
			{
				printf("Length should be within 1 ~ %d.\n",MaxLen);
			}
			else if(isdigit(s[0]))
			{
				printf("The first character can't be a digit.\n");
			}
			else if(cntsp(s) != 0)
			{
				printf("The name can't contain a space.\n");
			}
			else if(ss != -1)
			{
				printf("The name can't contain the word '%s'.\n",KeyName[ss].c_str());
			}
			else
			{
				break;
			}
		}
		tol(s);
		if(mp2[s] != 0)
		{
			printf("This name is existed. Change it.\n");
			continue;
		}
		++p;
		mp[p] = s;
		mp2[s] = p;
	}
}
int main(int argc, char const *argv[])
{
	srand(time(NULL));
	FILE *in = fopen("card.txt","r");
	if(in == NULL)
	{
		printf("Load new game.\n");
		input();
	}
	else
	{
		printf("Do you want to continue your last game? y/n\n");
		cin>>s;
		getchar();
		tol(s);
		if(s != "n")
		{
			fscanf(in,"%d",&Num);
			for(int i = 1;i <= Num; ++i)
			{
				char ss[100];
				int d;
				fscanf(in,"%s : %d",ss,&d);
				string now = string(ss);
				tol(now);
				mp[i] = now;
				a[i] = d;
				mp2[now] = i;
			}
			fclose(in);
			show();
		}
		else
		{
			fclose(in);
			input();
		}
	}

	printf("Game starts.\n");

	int rd = 0,lastflag = 0;
	while(printf("Round : %d\n",++rd) && getline(cin,s))
	{		
		tol(s);
		if(s == "end" || s == "quit")
		{
			// show();
			break;
		}
		else if(s == "return")
		{
			if(rd == 1)
			{
				lastflag = 0;
			}
			else if(lastflag)
			{
				show();
				printf("You can most return for 1 time.\n");
			}
			else
			{
				memcpy(a,b,sizeof(a));
				show();
				--rd;
			}
			lastflag = 1;
			--rd;
			continue;
		}
		else if(s == "clear")
		{
			memset(a,0x00,sizeof(a));
			--rd;
			show();
			continue;
		}
		else if(s == "rand")
		{
			show();
			printf("The first to get the card is %s\n",mp[rnd()].c_str());
			--rd;
			continue;
		}
		lastflag = 0;
		memcpy(b,a,sizeof(b));

		int cnt = cntsp(s);
		if(cnt < 2)
		{
			printf("Input shoud contains two names or indexes, and a integer.\n");
			rd--;
			continue;
		}

		// printf("*********s = %s\n",s.c_str());

		string s1 = "***",s2 = "***";
		int ind1 = -1,ind2 = -1;
		int x = 0;
		int j = 0;
		// printf("s = %s\n",s.c_str());
		int flag = 0;
		for(flag = isdigit(s[j]);j < s.size() && s[j] != ' '; ++j)
		{
			if(flag)
			{
				if(ind1 == -1)
				{
					ind1 = 0;
				}
				ind1 = ind1 * 10 + s[j] - '0';
			}
			else
			{
				if(s1 == "***")
				{
					s1.clear();
				}
				s1 += s[j];
			}
		}
		++j;
		for(flag = isdigit(s[j]);j < s.size() && s[j] != ' '; ++j)
		{
			if(flag)
			{
				if(ind2 == -1)
				{
					ind2 = 0;
				}
				ind2 = ind2 * 10 + s[j] - '0';
			}
			else
			{
				// printf("s[%d] = %c\n",j,s[j]);
				if(s2 == "***")
				{
					s2.clear();
				}
				s2 += s[j];
				// printf("s2 = %s\n",s2.c_str());
			}
		}
		++j;
		flag = -13;
		for(;j < s.size() && s[j] != ' '; ++j)
		{
			if(s[j] == '-')
			{
				flag = 1;
			}
			else if(isdigit(s[j]))
			{
				if(flag == -13)
				{
					flag = -1;
				}
				x = x * 10 + s[j] - '0';
			}
			else
			{
				flag = 0x3f;
				break;
			}
		}
		if(flag == 0x3f)
		{
			printf("The number of money should be an integer.\n");
			rd--;
			continue;
		}
		if(((ind1 <= 0 || ind1 > Num) && (s1 == "***"))
			|| ((ind2 <= 0 || ind2 > Num) && (s2 == "***")))
		{
			// printf("ind1 = %d,ind2 = %d\n",ind1,ind2);
			printf("The index should be within 1 ~ %d.\n",Num);
			rd--;
			continue;
		}
		// printf("s1 = %s,s2 = %s,%d %d\n",s1.c_str(),s2.c_str(),mp2[s1],mp2[s2]);
		x *= (-flag);
		a[(ind1 == -1) ? mp2[s1] : ind1] -= x;
		a[(ind2 == -1) ? mp2[s2] : ind2] += x;

		show();
		// memcpy(b,a,sizeof(a));
	}
	printf("Result:\n");
	for(int i = 1;i <= Num; ++i)
	{
		printf("%s : %d\n",mp[i].c_str(),a[i]);
	}
	FILE *out = fopen("card.txt","w");
	if(out == NULL)
	{
		printf("create new file : card.txt");
		system("touch ./card.txt");
	}
	fprintf(out,"%d\n",Num);
	for(int i = 1;i <= Num; ++i)
	{
		fprintf(out,"%s : %d\n",mp[i].c_str(),a[i]);
	}
	fclose(out);
	return 0;
}