#include <cstdio>
#include <vector>
#include <map>
#include <cstring>
using namespace std;
#define mst(a,b) memset((a),(b),sizeof(a))
#define rush() int T;scanf("%d",&T);while(T--)

typedef long long ll;
const int maxn = 100005;
const ll INF = 1e18;
const ll mod=1e9+7;
const double eps = 1e-9;

int sz;
char tmp[maxn],s[maxn],t[maxn];
int word[maxn*12];
char Mp[maxn][12];
int ch[maxn*12][28];
int key[maxn*12];

void init()
{
    sz=1;
    mst(ch[0],0),mst(word,0);
}

void Insert(char *s,int id)
{
    int len=strlen(s);
    int u=0;
    for(int i=0; i<len; i++)
    {
        int c=s[i]-'a';
        if(!ch[u][c])         //节点不存在
        {
            mst(ch[sz],0);
            ch[u][c]=sz++;    //节点数加1
        }
        u=ch[u][c];
        word[u]++;            //该节点下的单词数+1
    }
    key[u]=id;
}

void solve(char *s)
{
    int len=strlen(s);
    int u=0;
    int flag=0;
    for(int i=0; i<len; i++)
    {
        int c=s[i]-'a';
        u=ch[u][c];
        if(u==0)
        {
            flag=1;
            break;
        }
    }
    if(flag) puts("eh");
    else puts(Mp[key[u]]);
}

int main()
{
    init();
    int tot=0;
    while(gets(tmp))
    {
        if(strcmp(tmp,"")==0) break;
        int len=strlen(tmp);
        int now=0;
        int cnt=0;
        for(now=0;now<len;now++)
        {
            if(tmp[now]==' ') break;
            s[cnt++]=tmp[now];
        }
        s[cnt]='\0';
        cnt=0;
        for(now=now+1;now<len;now++)
        {
            t[cnt++]=tmp[now];
        }
        t[cnt]='\0';
        strcpy(Mp[tot],s);
        Insert(t,tot);
        tot++;
    }
    while(~scanf("%s",s))
    {
        solve(s);
    }
}