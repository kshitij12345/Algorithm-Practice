#include <stdio.h>
#include <stdlib.h>
#define MAX(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })


int MaxLoot(int Weight,int bars,int* bar){

int result[bars][Weight];
int i,j,previous,curr;

for(i=0;i<=bars;i++){
        for(j=0;j<=Weight;j++){result[i][j]=0;}
}

for(i=1;i<=bars;i++){
    for(j=1;j<=Weight;j++){
            printf("i = %d  , j=  %d     ",i,j);
        previous = result[i][j-1];
        curr = bar[i]+result[Weight-bar[i]][j-1];
        if (curr>j)
             {
                 result[i][j] = previous;
             }
        else{
            result[i][j] = MAX(previous,curr);
        }
        }
    printf("\n");

    }
//
//    for(i=0;i<=bars;i++){
//        for(j=0;i<=Weight;j++){
//            printf("%d ",result[i][j]);
//        }
//        printf("\n");
//    }

for(i=0;i<=bars;i++){
        for(j=0;j<=Weight;j++){
            printf("%d ",result[i][j]);
        }
        printf("\n");
    }

    return result[i-1][j-1];
}





int main()
{
    int bars[3] = {0,1,2};
    printf("%d",MaxLoot(10,2,bars));
    return 0;
}
