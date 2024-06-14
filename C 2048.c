#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
int gameblock[4][4] = {0};

void printgame()
{
  int i,o;
  //printf("\033[H\033[2J");
  for(i = 0;i <= 3;i++)
  {
    printf("---------------------\n");
    for(o = 0;o <= 3; o++)
    {
      switch(gameblock[i][o])
      {
        case(2):
        {
          printf("| 2  ");
          break;
        }
        case(4):
        {
          printf("| \033[33m4\033[0m  ");
          break;
        }
        case(8):
        {
          printf("| \033[32m8\033[0m  ");
          break;
        }
        case(16):
        {
          printf("| \033[36m16\033[0m ");
          break;
        }
        case(32):
        {
          printf("| \033[34m32\033[0m ");
          break;
        }
        case(64):
        {
          printf("| \033[35m64\033[0m ");
          break;
        }
        case(128):
        {
          printf("|\033[31m128\033[0m ");
          break;
        }
        case(256):
        {
          printf("|\033[31m\033[4m256\033[0m ");
          break;
        }
        case(512):
        {
          printf("|\033[31m\033[4m512\033[0m ");
          break;
        }
        case(1024):
        {
          printf("|\033[31m\033[4m1024\033[0m ");
          break;
        }
        case(2048):
        {
          printf("|\033[31m\033[4m2048\033[0m ");
          break;
        }
        default:
        {
          printf("|    ");
        }
      } 
    }
    printf("|\n");
  } 
  printf("---------------------");
}
void RandomNum(void)
{
  int number,i,o,u;
  srand(time(NULL));
  do
  { 
    i = rand()%4;
    o = rand()%4;
  }
  while(gameblock[i][o] != 0);
  if(gameblock[i][o] == 0)
  {
    u = rand()%2;
    if(u == 0)
    {
      gameblock[i][o] = 2;
    }
    else
    {
      gameblock[i][o] = 4;
    }
  }  
}
void movement(char value)
{
  int i ,o, u,counter = 0,merged[4] = {0},clean[4] = {0},clear;
  if(value == 'w')
  {
    for(o=0;o<=3;o++)
    {
      for(clear=0;clear<=3;clear++)
        merged[clear] = clean[clear];
      for(i=0;i<=2;i++)
      {
        for(u=1;u<=3-i;u++)
        {
          if(gameblock[i][o] == 0 && gameblock[i+u][o] !=0)
          {
            gameblock[i][o] = gameblock[i+u][o];
            gameblock[i+u][o] = 0;
            counter ++;
          }
        }
      }
      for(i=0;i<=2;i++)
      {
        if(gameblock[i][o]==gameblock[i+1][o] && gameblock[i+1][o] != 0 && merged[i] == 0)
        {
          gameblock[i][o]*=2;
          gameblock[i+1][o] = 0;
          merged[i] = 1;
          counter ++;
        }
      }
      for(i=0;i<=2;i++)
      {
        for(u=1;u<=3-i;u++)
        {
          if(gameblock[i][o] == 0 && gameblock[i+u][o] !=0)
          {
            gameblock[i][o] = gameblock[i+u][o];
            gameblock[i+u][o] = 0;
            counter ++;
          }
        }
      }
    }
  }
  else if(value == 's')
  {
    for(o=0;o<=3;o++)
    {
      for(clear=0;clear<=3;clear++)
        merged[clear] = clean[clear];
      for(i=3;i>=1;i--)
      {
        for(u=1;u<=i;u++)
        {
          if(gameblock[i][o] == 0 && gameblock[i-u][o] !=0)
          {
            gameblock[i][o] = gameblock[i-u][o];
            gameblock[i-u][o] = 0;
            counter ++;
          }
        }
      }
      for(i=3;i>=1;i--)
      {
        if(gameblock[i][o]==gameblock[i-1][o] && gameblock[i-1][o] != 0 && merged[i] == 0)
        {
          gameblock[i][o]*=2;
          gameblock[i-1][o] = 0;
          merged[i] = 1;
          counter ++;
          merged[i] = 1;
        }
      }
      for(i=3;i>=1;i--)
      {
        for(u=1;u<=i;u++)
        {
          if(gameblock[i][o] == 0 && gameblock[i-u][o] !=0)
          {
            gameblock[i][o] = gameblock[i-u][o];
            gameblock[i-u][o] = 0;
            counter ++;
          }
        }
      }
    }
  }
  else if(value == 'a')
  {
    for(i=0;i<=3;i++)
    {
      for(clear=0;clear<=3;clear++)
        merged[clear] = clean[clear];
      for(o=0;o<=2;o++)
      {
        for(u=1;u<=3-o;u++)
        {
          if(gameblock[i][o] == 0 && gameblock[i][o+u] !=0)
          {
            gameblock[i][o] = gameblock[i][o+u];
            gameblock[i][o+u] = 0;
            counter ++;
          }
        }
      }
      for(o=0;o<=2;o++)
      {
        if(gameblock[i][o]==gameblock[i][o+1] && gameblock[i][o+1] != 0 && merged[o] == 0)
        {
          gameblock[i][o]*=2;
          gameblock[i][o+1] = 0;
          counter ++;
          merged[o] = 1;
        }
      }
      for(o=0;o<=2;o++)
      {
        for(u=1;u<=3-o;u++)
        {
          if(gameblock[i][o] == 0 && gameblock[i][o+u] !=0)
          {
            gameblock[i][o] = gameblock[i][o+u];
            gameblock[i][o+u] = 0;
            counter ++;
          }
        }
      }
    }
  }
  else if(value == 'd')
  {
    for(i=0;i<=3;i++)
    {
      for(clear=0;clear<=3;clear++)
        merged[clear] = clean[clear];
      for(o=3;o>=1;o--)
      {
        for(u=1;u<=o;u++)
        {
          if(gameblock[i][o] == 0 && gameblock[i][o-u] !=0)
          {
            gameblock[i][o] = gameblock[i][o-u];
            gameblock[i][o-u] = 0;
            counter ++;
          }
        }
      }
      for(o=3;o>=1;o--)
      {
        if(gameblock[i][o]==gameblock[i][o-1] && gameblock[i][o-1] != 0 && merged[o] == 0)
        {
          gameblock[i][o]*=2;
          gameblock[i][o-1] = 0;
          counter ++;
          merged[o] = 1;
        }
      }
      for(o=3;o>=1;o--)
      {
        for(u=1;u<=o;u++)
        {
          if(gameblock[i][o] == 0 && gameblock[i][o-u] !=0)
          {
            gameblock[i][o] = gameblock[i][o-u];
            gameblock[i][o-u] = 0;
            counter ++;
          }
        }
      }
    }
  }
  if(counter>0)
  {
    RandomNum();
  }
}

void Default(void)
{
  int i;
  for(i = 1;i<=2;i++)
  {
    RandomNum();
  }
}

int decwin(void)
{
  int i = 0,o = 0,counter = 0; 
  for(i=0;i<=2;i++)
  {
    for(o=0;o<=2;o++)
    {
      if(gameblock[i][o] == gameblock[i+1][o] || gameblock[i][o] == gameblock[i][o+1])
      {
        counter ++; 
      }
    }
  }
  for(i=0;i<=3;i++)
    for(o=0;o<=3;o++)
      if(gameblock[i][o]==0)
        counter++;
      else if(gameblock[i][o] == 2048)
        counter += 32767;
  if(counter == 0)
  {
    return 1;
  }
  else if(counter >= 32767)
  {
    return 2;
  }
  else
  {
    return 0;
  }
}

int main(void)
{
  Default();
  char move;
  char c;
  int win = 0;
  while(1)
  {
    printgame();
    win = decwin();
    if(win == 0)
    {
      
    }
    else if(win == 1)
    {
      printf("\n        You Lost!");
      return 0;
    }
    else if(win == 2)
    {
      printf("\n        You Won!");
    }
    printf("\n        w=向上\n        a=向左\n        s=向下\n        d=向右 > ");
    move = getchar();
    while((c=getchar()) != '\n' && c != EOF);
    movement(move);
  }
  return 0;
}
