#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 6


int BinarySearch(int* A,int low,int high,int key){
int mid;
if (high<low){
    return -1;
}
mid = low + (int)floor(high-low/2);

if (key == A[mid]){return mid;}
else if(key<A[mid]){
    return BinarySearch(A,low,mid-1,key);
}else{return BinarySearch(A,mid+1,high,key);}

}


int BinaryIter(int* A,int low,int high,int key){
int mid;
while(low<=high){
    mid = low + (int)floor(high-low/2);
    if (key == A[mid]){
        return mid;
    }else if(key<A[mid]){
        high = mid-1;
    }else{
        low = mid + 1;
    }
}
return -1;
}

int main()
{   int bin[N] = {1,2,3,4,5,6};
    int key[3] = {1,9,6};
    int i;
    printf("Hello world!\n");
    for(i = 0;i<3;i++){
        printf("%d ",BinaryIter(bin,0,5,key[i]));
    }

    return 0;
}
