#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Maj[4] = {1,2,3,1};
int Cnt[4] = {0,0,0,0};

void MajByDivideAndConquer(int* A,int low,int high){
int max=0;
int mid = low + (int)floor(high-low/2);
int a,b;
if(low==high){
    Cnt[low]++;
    }
else{
    MajByDivideAndConquer(A,low,mid);
    MajByDivideAndConquer(A,mid+1,high);

}


}

int main()
{
    printf("Hello world!\n");

    MajByDivideAndConquer(Maj,0,3);
    return 0;
}
