#include <stdio.h>
#include <stdlib.h>

long FiboRecursive(long n){
    if(n<=1){return n;}
    else{return FiboRecursive(n-1)+FiboRecursive(n-2);}
}

long FiboArray(long n){
    int i;
    long Fib[n];
    for(i = 1;i<n;i++){
        Fib[i] = 0;
    }
    Fib[0] = 0;
    Fib[1] = 1;
    for (i=2;i<=n;i++){
        Fib[i] = Fib[i-1]+Fib[i-2];}
        //printf("%lu = %lu + %lu \n",Fib[i],Fib[i-1],Fib[i-2]);}
    return Fib[n];
}


int main()
{
    printf("%lu %lu \n",FiboRecursive(20),FiboArray(20));
    printf("%lu %lu \n",FiboRecursive(3),FiboArray(3));
    printf("%lu %lu \n",FiboRecursive(10),FiboArray(10));
    return 0;
}
