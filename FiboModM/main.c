#include <stdio.h>
#include <stdlib.h>

unsigned long long FiboArray(unsigned long long n){
    int i;
    unsigned long long Fib[n];
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

unsigned long long getPisano(unsigned long long M){
    unsigned long long i;
    unsigned long long a = 0;
    unsigned long long b = 1;
    unsigned long long c;
    for(i= 0;i<M*M;i++){
        c = (a+b)%M;
        a = b;
        b = c;
        if(a==0 && b==1){return i+1;}
    }
}

int FibModM(int n,int M){
    unsigned long long remainder = n % getPisano(M);
    unsigned long long i;
    unsigned long long first = 0;
    unsigned long long second = 1;

    unsigned long long res = remainder;

    for (i = 1; i < remainder; i++) {
        res = (first + second) % M;
        first = second;
        second = res;
    }

    return res%M;

}


int main()
{
    printf("Hello world!\n");
    //printf("%d \n",FibModM(2015,3));
    printf("%llu \n",FibModM(2816213588,30524));
    return 0;
}
