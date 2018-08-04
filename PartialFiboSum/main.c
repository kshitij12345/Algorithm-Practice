#include <stdio.h>
#include <stdlib.h>

int FiboRecursiveLast(int n){
    if(n<=1){return n%10;}
    else{return FiboRecursiveLast(n-1)+FiboRecursiveLast(n-2);}
}

int FiboPartialSum(int n,int m){
    int i;
    int res = 1;
    int Fib[m];
    Fib[0] = 0;
    Fib[1] = 1;
    for (i=2;i<=n;i++){
        Fib[i] = (Fib[i-1]+Fib[i-2])%10;
        }
    res = Fib[i-1]%10;
    for(i=n+1;i<=m;i++){
        Fib[i] = (Fib[i-1]+Fib[i-2])%10;
        res = (res + Fib[i])%10;
    }
        //printf("%lu = %lu + %lu \n",Fib[i],Fib[i-1],Fib[i-2]);}
    return res;
}


int main()
{
    //printf("%lu  \n",FiboLastArray(327305));
    printf("%lu  \n",FiboPartialSum(10,200));
    //printf("%lu  \n",FiboLastArray(331));
    return 0;
}
