#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int gameOver(int a[4][4]);	//判断游戏是否结束 
void showGame(int a[4][4],int step,int score);	//显示游戏界面
void invert(int *p[4][4],char c); //翻转字符
void randominsert(int a[][4]); //产生随机数
void move(int *(*pa)[4],int *score,int *step);	//加 移动

int main()
{
	int a[4][4] = {0};
	int *p[4][4], i, j;
	int step = 0, score = 0;
	char c;
	randominsert(a);
	while((c != 'q') && c != 'Q')
	{
		//判断游戏是否结束
		if(gameOver(a) == 0)
		{
			printf("\n游戏结束，你已失败！\n");
			break;
		}
		else if(gameOver(a) == 1)
		{
			printf("\n游戏胜利！\n");
			break;
		}
		else if(gameOver(a) == 3)
		//随机数
		randominsert(a);
		else ;
		//p复原
		for(i = 0; i < 4; i ++)
			for(j = 0; j < 4; j ++)
				p[i][j] = &a[i][j];
		//清屏
		system("clear");

		//显示界面
		showGame(a, step, score);
		//输入方向
		c = getchar();
		//翻转
		invert(p, c);
		//移动
		move(p, &step, &score);


	}
}

//显示界面
void showGame(int a[4][4],int step,int score)
{
	char W,A,S,D,Q;
	char UP,DOWN,LEFT,RIGHT,EXIT;
	int i,j,k;
	printf("2048游戏\n");
	printf("W--UP A--LEFT  S--DOWN D--RIGHT Q--EXIT \n ");
	printf("score:%d      step:%d\n", score, step);
	for(i = 0; i < 5; i++)
	{
		printf("|---------------|\n");
		if(i > 3)
			continue;
			for(j=0;j<4;j++)
			{
				printf("| ");
				if(a[i][j]==0)
					printf("  ");
				else
					printf("%d ", a[i][j]);
			}
			printf("|\n");
	}
}

//判断游戏是否结束
int gameOver(int a[4][4])
{
	int i, j;
	int log = 0;
	int notfull = 0;
	for(i = 0; i < 4; ++ i)
		for(j = 0; j < 3; ++ j)
		{
			if(a[i][j] == 2048 || a[i][j + 1] == 2048)
				return 1;
			if((a[i][j] == a[i][j + 1] || a[j][i] == a[j + 1][i]))
			{
				log = 2;	
			}
			if(a[i][j] == 0 || a[i][j + 1] == 0)
				notfull = 1;
		}
	return log + notfull;
}

//翻转
void invert(int *p[4][4],char c) //翻转字符
{
 int i,j,*t;
 int *q[4][4];
 if (c == 'w')
 ;
 if (c == 's')
   {
   for (i = 0; i < 3; ++i)
      {
       for (j = 0; j < 3-i; ++j)
           {
            t = p[i][j];
            p[i][j] = p[3-i][3-j];
            p[3-i][3-j] = t;             
           }
      }
   t = p[0][3]; p[0][3] = p[3][0]; p[3][0] = t;
   t = p[1][2]; p[1][2] = p[2][1]; p[2][1] = t;
   }
 if (c == 'a')
     {
     for (i = 0; i < 4; ++i)
       {
         q[0][i] = p[3-i][0];
         q[1][i] = p[3-i][1];
         q[2][i] = p[3-i][2];
         q[3][i] = p[3-i][3];
       }
     for (i=0; i < 4; ++i)
         for (j=0; j<4;++j)
            p[i][j] = q[i][j];
     }
  if (c == 'd')
    {
    for (i = 0; i < 4; ++i)
        {
        q[0][i] = p[i][3];
        q[1][i] = p[i][2];
        q[2][i] = p[i][1];
        q[3][i] = p[i][0];
        }
    for (i = 0; i<4; ++i)
        for (j = 0; j<4; ++j)
      p[i][j] = q[i][j];
    }
}

//产生随机数
void randominsert(int a[][4]) //产生随机数
{
 int number,n,*p;
 p = &a[0][0];
 srand((unsigned)time(NULL));
 number = (rand()%2+1)*2;
 n = rand()%16;
 while ( *(p+n) != 0)
  n =rand()%16;
 *(p+n) = number;
}
void move(int *(*pa)[4],int *score,int *step)
{
	int r,c,*pnum1 = NULL,*pnum2 = NULL;
	(*step)++;
	for(c = 0;c < 4;++c)
	{
		for(r = 0;r < 4;++r)
		{
			if(*pa[r][c])
			{
				if(pnum1 == NULL)
					pnum1 = pa[r][c];
				else
					pnum2 = pa[r][c];
			}
			if(pnum1 && pnum2)
			{
				if (*pnum1 == *pnum2)
				{
					*pnum1 += *pnum2;
					*score += *pnum1;
					*pnum2 = 0;
					pnum1 = NULL;
					pnum2 = NULL;
				}
				else
				{
					pnum1 = pnum2;
				}
			}
		}
		pnum1 = NULL;
		pnum2 = NULL;
		for(r = 0;r < 4;++r)
		{
			if(*pa[r][c] == 0)
			{
				if(pnum1 == NULL)
					pnum1 = pa[r][c];
			}
			else
			{
				if(pnum1)
					pnum2 = pa[r][c];
			}
			if(pnum1 && pnum2)
			{
				*pnum1 = *pnum2;
				*pnum2 = 0;
				pnum2 =NULL;
				pnum1 += 4;
			}
		} 
		pnum1 = NULL;
		pnum2 = NULL;
	}
		
}

