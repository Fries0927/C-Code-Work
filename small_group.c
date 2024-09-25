//https://zerojudge.tw/ShowProblem?problemid=c291

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct friend_list
{
  int friend;
  bool iterated;
}friend_list;

void find_group(friend_list* people , int current_check)
{
    int head = current_check;
    do
    {
        people[current_check].iterated = true;
        current_check = people[current_check].friend;
    }
    while(head != current_check);
}

int main()
{
    int people_count;
    int group_count = 0;
    friend_list* people;
    scanf("%d",&people_count);
    people = calloc(people_count,sizeof(friend_list));
    for(int i = 0 ; i < people_count ; i++)
    {
        scanf("%d",&people[i].friend);
    }
    for(int i = 0; i < people_count ; i++)
    {
        if(people[i].iterated == false)
        {
            find_group(people,i);
            group_count++;
        }
    }
    printf("%d",group_count);
    return 0;
}
