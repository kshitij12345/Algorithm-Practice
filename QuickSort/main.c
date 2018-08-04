#include <stdio.h>
#include <stdlib.h>
#define SWAP(x, y) do { typeof(x) SWAP = x; x = y; y = SWAP; } while (0)


int Partition(int* A,int l,int r){
int i;
int x;
int j;
x = A[l];//pivot
j = l;
for(i=l+1;i<r;i++){
    if(A[i]<=x){
        j++;
        SWAP(A[j],A[i]);
    }
}
SWAP(A[l],A[j]);

return j;
}


void QuickSort(int* A,int l ,int r){
int i;
if (l>=r){return;}

int m = Partition(A,l,r);
printf("%d  ",m);
for (i=0;i<9;i++){
    printf("%d ",A[i]);
}
printf("\n");
QuickSort(A,l,m);
QuickSort(A,m+1,r);

}


int main()
{
    int i;
    //int A[6] ={3,1,2,4,2,3};
    int A[10]={1,6,1,3,2,1,4,3,1,5};
    QuickSort(A,0,10);
    printf("\n");
    for(i=0;i<10;i++){
        printf("%d ",A[i]);
    }

    return 0;
}
