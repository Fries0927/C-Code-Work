//https://zerojudge.tw/ShowProblem?problemid=b266
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printout(int R,int C ,int *arr);

void swap(int* element1 ,int* element2)
{
    int buffer = *element1;
    *element1 = *element2;
    *element2 = buffer;
}

void flip(int row , int col , int* array)
{
    //printf("flip row , col[%d,%d]\n",row,col);
    int upptr = 0 , downptr = row-1;
    for(int swapcol = 0 ; swapcol <= col-1 ; swapcol++)
    {
        upptr = 0;
        downptr = row-1;
        while( upptr < downptr )
        {
            //printf("[%d,%d]",array[upptr * col + swapcol],array[downptr * col + swapcol]);
            swap(&array[upptr * col + swapcol],&array[downptr * col + swapcol]);
            upptr++;
            downptr--;
        }
    }
}

//rotate 90 degree
int* rotate(int* rowp , int* colp , int* arr)
{
    int row = *rowp;
    int col = *colp;
    swap(rowp,colp);
    int* array = malloc(sizeof(int) * col * row);
    if(array == NULL)
    {
        fprintf(stderr,"array malloc failed!");
        return 0;
    }
    int transforVal = 0;
    for(int o = col-1; o >= 0 ; o--)
    {
        for(int i = 0; i < row ; i++)
        {
            array[transforVal] = arr[i*col+o];
            //printf("[%d,%d,%d]",i,col,o);
            transforVal++;
        }
    }
    free(arr);
    return array;
}

void original(int** array , int* mani , int R, int C, int M)
{
    int* Rol = &R;
    int* Col = &C;
    for(int i = M-1 ; i>=0 ; i--)
    {
        if(mani[i] != 0)
        {
            //printf("executing flip");
            flip(R,C,*array);
            //printout(R,C,*array);
        }
        else
        {
            //printf("executing rotate");
            *array = rotate(Rol,Col,*array);
            //printout(R,C,*array);
        }
    }
    printout(R,C,*array);
}

void printout(int R,int C ,int *arr)
{
    int changeL = 0;
    printf("%d ",R);
    printf("%d\n",C);
    for(int i = 0 ; i < R ; i++)
    {
        for(int o = 0 ; o < C ; o++)
        {
            printf("%d ",arr[i*C+o]);
        }
        printf("\n");
    }
}

int main(void)
{
    int *arr;
    int R;
    int C;
    int M;
    int* manipulation;
    scanf("%d",&R);
    scanf("%d",&C);
    scanf("%d",&M);

    arr = malloc(R * C * sizeof(int));
    if(arr == NULL)
    {
        fprintf(stderr,"arr malloc failed!");
        return 0;
    }

    manipulation = malloc(M * sizeof(int));
    if(manipulation == NULL)
    {
        fprintf(stderr,"manipulation malloc failed!");
        return 0;
    }

    for(int i = 0 ; i<R*C ; i++)
    {
        scanf("%d",&arr[i]);
    }

    for(int i = 0 ; i < M ; i++)
    {
        scanf("%d",&manipulation[i]);
    }
    //printf("hello");
    original(&arr , manipulation ,R,C,M);
    free(manipulation);
    free(arr);
    return 0;
}
