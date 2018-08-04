#include <stdio.h>
#include <stdlib.h>

long GCD(long a,long b){
    if(b==0){
        return a;
    }else{
        return GCD(b,a%b);
    }
}

long long LCM(long long a,long long b){
    return (a*b)/GCD(a,b);
}


int main()
{
    printf("Hello world!\n");
    printf("%lu  ",LCM(6,8));
    printf("%lu  ",LCM(28851538,1183019));
    return 0;
}
