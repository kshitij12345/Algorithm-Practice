#include <stdio.h>
#include <stdlib.h>
#define Min(a,b)(a<b?a:b)
#define N 3
int Weight[N] = {20,50,30};
int Value[N] = {60,100,120};
//int Weight[N] = {30};
//int Value[N] = {500};

float SortedVbyW[N];

void SortedValueByWeight(){
    int i,j,temp;
    for(i=0;i<N;i++){
        for(j=i;j<N;j++){
            if(Value[j]/Weight[j]>=Value[i]/Weight[i]){
                SortedVbyW[i] = (float)Value[j]/(float)Weight[j];
                temp = Value[j];
                Value[j] = Value[i];
                Value[i] = temp;
                temp = Weight[j];
                Weight[j] = Weight[i];
                Weight[i] = temp;

            }
        }
    }
    for(i=0;i<N;i++){
        printf("%f ",SortedVbyW[i]);
    }
    printf("\n");
    for(i=0;i<N;i++){
        printf("%d ",Weight[i]);
    }
    printf("\n");
    for(i=0;i<N;i++){
        printf("%d ",Value[i]);
    }
    printf("\n");
}

int SumWeights(){
    int sum=0,i;
    for(i=0;i<N;i++){
        sum = sum + Weight[i];
    }
    return sum;
}

float MaximizeLoot(int Max){
    int Curr;
    float Value;
    int a,i;
    Value = 0;
    Curr = Max;
    while(Curr!=0){
        for (i=0;i<N;i++){
            if(Weight[i]>0 && Curr!=0){
                a = Min(Weight[i],Curr);
                Weight[i] = Weight[i] - a;
                Curr = Curr - a;
                Value = Value + a*SortedVbyW[i];
                break;
            }
        }
    }
    return Value;

}



int main()
{
    SortedValueByWeight();
    printf("%f ",MaximizeLoot(50));
    return 0;
}

