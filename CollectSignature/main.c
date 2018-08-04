#include <stdio.h>
#include <stdlib.h>
#define Min(a,b)(a<b?a:b)
#define N 6

//int start[N] = {1,2,3};
//int end[N] = {3,5,6};

//int start[N] = {4,1,2,5};
//int end[N] = {7,3,5,6};

int start[N] = {4,1,2,5,8,11};
int end[N] = {7,3,5,6,10,12};

void SortByStart(){
    int i,j,temp;
    for(i=0;i<N;i++){
        for(j=i;j<N;j++){
            if(start[j]<=start[i]){
                temp = start[j];
                start[j] = start[i];
                start[i] = temp;
                temp = end[j];
                end[j] = end[i];
                end[i] = temp;

            }
        }
    }
    for(i=0;i<N;i++){
        printf("%d ",start[i]);
    }
    printf("\n");
    for(i=0;i<N;i++){
        printf("%d ",end[i]);
    }
    printf("\n");
    printf("\n");
}



int CollectSign(){
    int Curr;
    int points[N];
    int numpoints;
    int star = start[0];
    int en = end[0];
    numpoints = 1;
    points[0] = en;
    int i=0;
    Curr = N;
    while(Curr!=0){
        while(start[i]<=en && Curr !=0){
        //printf("%d \n",i);
        points[numpoints-1] = start[i];
        Curr--;
        i++;
        }
        //printf("i %d   star  %d    en % \n",i,star,en);
        if(Curr==0){break;}
        numpoints++;
        star = start[i];
        en = end[i];
        //printf("i %d   star  %d    en %d \n",i,star,en);
        points[numpoints-1]=star;
    }


    for(i=0;i<numpoints;i++){
        printf("%d  ",points[i]);
    }
    return numpoints;

}



int main()
{
    SortByStart();
    printf("\n %d ",CollectSign());
    return 0;
}

