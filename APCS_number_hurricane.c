https://zerojudge.tw/ShowProblem?problemid=c292

#include <stdio.h>

int main()
{
  int N;
  scanf("%d",&N);
  int numbers[N][N];
  int direction;
  int x = N/2;
  int y = N/2;
  int time = 2;
  int number = 1;
  scanf("%d",&direction);
  for(int i = 0 ; i < N; i++)
  {
    for(int o = 0 ; o < N ; o++)
    {
      scanf("%d",&numbers[i][o]);
    }
  }
  printf("%d",numbers[x][y]);
  do
  {
    switch(direction)
    {
      case(0):
      {
        for(int i = y - 1 ; i >= y - (time/2) ; i--)
        {
          printf("%d",numbers[x][i]);
          //printf("[%d,%d]",x,y);
          number++;
          if(number >= N*N)
          {
            printf("\n");
            return 0;
          }
        }
        y = y - (time/2);
        break;
      }
      case(1):
      {
        for(int i = x - 1 ; i >= x - (time/2) ; i--)
        {
          printf("%d",numbers[i][y]);
          //printf("[%d,%d]",x,y);
          number++;
          if(number >= N*N)
          {
            printf("\n");
            return 0;
          }
        }
        x = x - (time/2);
        break;
      }
      case(2):
      {
        for(int i = y + 1 ; i <= y + (time/2) ; i++)
        {
          printf("%d",numbers[x][i]);
          //printf("[%d,%d]",x,y);
          number++;
          if(number >= N*N)
          {
            printf("\n");
            return 0;
          }
        }

        y = y + (time/2);
        //printf("y : [%d]",y);
        break;
      }
      case(3):
      {
        for(int i = x + 1 ; i <= x + (time/2) ; i++)
        {
          printf("%d",numbers[i][y]);
          //printf("[%d,%d]",x,y);
          number++;
          if(number >= N*N)
          {
            printf("\n");
            return 0;
          }
        }
        x = x + (time/2);
        //printf("x : [%d]",x);
        break;
      }
    }
    direction = (direction+1) % 4;
    time++;
  }
  while(number <= N*N);
  return 0;
}
