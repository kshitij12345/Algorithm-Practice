#include <stdio.h>
#include <stdlib.h>
#define pwrtwo(x) (1 << (x))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

int log2floor(int num){int l=0; while(num >>= 1){++l;}return l;}
int sparse[6][2+1];

void constructSparse(int* input,int n){

    int i,j;
    for(i=0;i<n;i++){sparse[i][0] = i;}

    for(j=1;pwrtwo(j)<=n;j++){
        for(i=0;i+pwrtwo(j)-1 <n;i++){
            if(input[sparse[i][j-1]]<input[sparse[i+pwrtwo(j-1)][j-1]]){
                sparse[i][j]=sparse[i][j-1];
            }
            else{sparse[i][j] = sparse[i+pwrtwo(j-1)][j-1];}
        }
    }

}

int rmq(int low,int high,int* input){
int l = high - low + 1;
int k = log2floor(l);

return MIN(input[sparse[low][k]],input[sparse[low + l - pwrtwo(k)][k]]);
}



int main()
{
    int input[6] = {3,1,2,6,5,1};
    //int sparse[6][log2floor(6)+1];

    constructSparse(input,6);


    printf("%d",rmq(3,3,input));

    return 0;
}
