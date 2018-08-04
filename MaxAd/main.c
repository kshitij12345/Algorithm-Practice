#include <stdio.h>
#include <stdlib.h>
#define Min(a,b)(a<b?a:b)
#define Max(a,b)(a>b?a:b)
#define N 3
int a[N] = {23};
int b[N] = {39};
//int Weight[N] = {30};
//int Value[N] = {500};

//float SortedVbyW[N];

void Sort(int* sort){
    int i,j,temp;
    for(i=0;i<N;i++){
        for(j=i;j<N;j++){
            if(sort[j]>=sort[i]){
                temp = sort[j];
                sort[j] = sort[i];
                sort[i] = temp;
            }
        }
    }

    printf("\n");
    for(i=0;i<N;i++){
        printf("%d ",sort[i]);
    }
    printf("\n");
}


float MaximizeAd(){
    int Curr;
    float Value;
    int i;
    Value = 0;
    Curr = N;
    while(Curr!=0){
        for (i=0;i<N;i++){
            if(Curr==0){
                    break;
            }
            Value += a[i]*b[i];
            Curr--;
        }
    }
    return Value;

}



int main()
{
    Sort(a);
    Sort(b);
    printf("%f ",MaximizeAd());
    return 0;
}

