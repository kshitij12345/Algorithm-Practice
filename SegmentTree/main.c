#include <stdio.h>
#include <stdlib.h>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define len 15

void printSegtree(int* segTree){
int i;
for(i=0;i<len;i++){
    printf("%d \t",segTree[i]);
}
printf("\n");

}



void constructSegTree(int* input,int* segTree,int low,int high,int pos){
    int mid;
    //printf("%d   %d \t",low,high);
    //printSegtree(segTree);

    if (low == high){segTree[pos] = input[low]; return ;}
    mid = (low + high)/2;
    constructSegTree(input,segTree,low,mid,2*pos+1);
    constructSegTree(input,segTree,mid+1,high,2*pos+2);
    segTree[pos] = MAX(segTree[2*pos+1],segTree[2*pos+2]);
}


int rangeQuery(int* segTree,int qlow, int qhigh,int low,int high,int pos){
    if(qlow <= low && qhigh >= high){return segTree[pos];}//total overlap
    else if(qlow > high || qhigh < low ){return -99;}//no overlap

    int mid = (low + high)/2;

    return(MAX(rangeQuery(segTree,qlow,qhigh,low,mid,2*pos+1),rangeQuery(segTree,qlow,qhigh,mid+1,high,2*pos+2)));
}

updateValue()//only applicable for sum query



int main()
{
    int i;
    int input[5] = {-1,2,4,0,2};
    int segTree[len];
    for(i = 0;i<len;i++){
        segTree[i] = 99;
    }
    constructSegTree(input,segTree,0,4,0);

    printSegtree(segTree);
    printf("%d", rangeQuery(segTree,0,2,0,4,0));

    return 0;
}
