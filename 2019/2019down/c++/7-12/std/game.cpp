#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

int z[10][10],y[10][10],sum,ans;

int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);

    for (int i=1;i<=4;i++)
        for (int j=1;j<=4;j++)
            scanf("%d",&z[i][j]);

    ans=0;
    for (int a=0;a<=1;a++)
        for (int b=0;b<=1;b++)
            for (int c=0;c<=1;c++)
                for (int d=0;d<=1;d++)
                    for (int e=0;e<=1;e++)
                        for (int f=0;f<=1;f++)
                            for (int g=0;g<=1;g++)
                                for (int h=0;h<=1;h++)
                                {
                                    for (int i=1;i<=4;i++)
                                        for (int j=1;j<=4;j++)
                                            y[i][j]=z[i][j];
                                    if (a==1) y[1][1]*=-1,y[1][2]*=-1,y[1][3]*=-1,y[1][4]*=-1;
                                    if (b==1) y[2][1]*=-1,y[2][2]*=-1,y[2][3]*=-1,y[2][4]*=-1;
                                    if (c==1) y[3][1]*=-1,y[3][2]*=-1,y[3][3]*=-1,y[3][4]*=-1;
                                    if (d==1) y[4][1]*=-1,y[4][2]*=-1,y[4][3]*=-1,y[4][4]*=-1;
                                    if (e==1) y[1][1]*=-1,y[2][1]*=-1,y[3][1]*=-1,y[4][1]*=-1;
                                    if (f==1) y[1][2]*=-1,y[2][2]*=-1,y[3][2]*=-1,y[4][2]*=-1;
                                    if (g==1) y[1][3]*=-1,y[2][3]*=-1,y[3][3]*=-1,y[4][3]*=-1;
                                    if (h==1) y[1][4]*=-1,y[2][4]*=-1,y[3][4]*=-1,y[4][4]*=-1;
                                    sum=0;
                                    for (int i=1;i<=4;i++)
                                        for (int j=1;j<=4;j++)
                                            sum+=y[i][j];
                                    ans=max(ans,sum);
                                }

    printf("%d\n",ans);

    return 0;
}
