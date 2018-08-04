#include <stdio.h>
#include <stdlib.h>

int MaximizePrize(int n){

    int k = n;
    int l = 1;
    int prize[n];

    while(k>2*l){
        prize[l-1] = l;
        k -=l;
        l++;
        //printf("k = %d   l = %d \n",k,l);

    }
    prize[l-1] = k;

    for(k=0;k<l;k++){printf("%d ",prize[k]);}

    return l;

}

int main()
{
    printf("Hello world!\n");
    printf("\n %d  ",MaximizePrize(10));
    return 0;
}
