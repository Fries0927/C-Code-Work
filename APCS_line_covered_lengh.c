https://zerojudge.tw/ShowProblem?problemid=b966
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct line
{
    int start;
    int end;
};

void swap(int pos1 , int pos2 , struct line* lines)
{
    int buffers = lines[pos1].start;
    int buffere = lines[pos1].end;
    lines[pos1].start = lines[pos2].start;
    lines[pos1].end = lines[pos2].end;
    lines[pos2].start = buffers;
    lines[pos2].end = buffere;
}

void Quick_sort(struct line* lines,int min,int max)
{
    if(min >= max)
    {
        return;
    }
    int pivot = lines[(min+max)/2].start;
    int pivotpos = min;
    swap(min,(min+max)/2,lines);
    for(int i = min+1 ; i <= max ; i++)
    {
        if(lines[i].start <= pivot)
        {
            pivotpos++;
            swap(pivotpos,i,lines);
        }
    }
    swap(pivotpos,min,lines);
    Quick_sort(lines,min,pivotpos-1);
    Quick_sort(lines,pivotpos+1,max);
    return;
}

int main(void)
{
    int line_count;
    scanf("%d",&line_count);
    struct line lines[line_count];
    for(int i = 0 ; i < line_count ; i++)
    {
        scanf("%d",&lines[i].start);
        scanf("%d",&lines[i].end);
    }
    Quick_sort(lines,0,line_count-1);
    int total=0;
    struct line current = lines[0];
    for(int i = 1 ; i < line_count ; i++)
    {
        if(current.end < lines[i].start)
        {
            total += current.end - current.start;
            current = lines[i];
        }
        else if(current.end < lines[i].end || current.end == lines[i].start)
        {
            current.end = lines[i].end;
        }
    }
    total += current.end - current.start;
    printf("%d",total);
    return 0;
}
