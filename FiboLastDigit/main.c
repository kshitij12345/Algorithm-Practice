#include <stdio.h>
#include <stdlib.h>

int FiboRecursiveLast(int n){
    if(n<=1){return n%10;}
    else{return FiboRecursiveLast(n-1)+FiboRecursiveLast(n-2);}
}

int FiboLastArray(int n){
    int i;
    int Fib[n];
    Fib[0] = 0;
    Fib[1] = 1;
    for (i=2;i<=n;i++){
        Fib[i] = (Fib[i-1]+Fib[i-2])%10;
        }
        //printf("%lu = %lu + %lu \n",Fib[i],Fib[i-1],Fib[i-2]);}
    return Fib[n];
}


int main()
{
    //printf("%lu  \n",FiboLastArray(327305));
    printf("%lu  \n",FiboLastArray(100));
    //printf("%lu  \n",FiboLastArray(331));
    return 0;
}
