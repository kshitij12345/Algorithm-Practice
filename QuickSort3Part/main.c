#include <stdio.h>
#include <stdlib.h>
#define SWAP(x, y) do { typeof(x) SWAP = x; x = y; y = SWAP; } while (0)


int* Partition(int* A,int l,int r){
int indices[2];
int i;
int x;
int k;
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
//printf("After first part");
//for(i=0;i<r;i++){printf("%d ",A[i]);}
//printf("j %d \n",j);
//printf("%d \n",j);
indices[1] = j;
k=j;
for(i=j-1;i>=0;i--){
    if(A[i]==x){
//        while(A[i]==A[k]){if(k==0){break;}k--;}
        k--;
        SWAP(A[i],A[k]);
    }
}
indices[0]=k;
//printf("%d \n",k);
return indices;
}


void QuickSort(int* A,int l ,int r){
int i;
int m,k;
if (l>=r){return;}

int *indices = Partition(A,l,r);
m = indices[0];
k = indices[1];
//printf("%d  ",m);
/*for (i=0;i<9;i++){
    printf("%d ",A[i]);
}
printf("\n");*/
QuickSort(A,l,m);

//printf("k+1  %d     r %d",k+1,r);
QuickSort(A,k+1,r);

}


int main()
{
    int i;
    //int A[6] ={3,1,2,4,2,3};
    int A[18]={3,6,1,3,2,1,4,3,1,5,1,4,6,3,9,4,6,8};
    QuickSort(A,0,18);
//    QuickSort(A,7,10);
  //  QuickSort(A,7,9);
    //QuickSort(A,10,10);
    //printf("\n");
    //int A[3]= {5,4,6};
   // Partition(A,0,3);
    for(i=0;i<18;i++){
        printf("%d ",A[i]);
    }

    return 0;
}
