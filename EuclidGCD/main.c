#include <stdio.h>
#include <stdlib.h>

long GCD(long a,long b){
    if(b==0){
        return a;
    }else{
        return GCD(b,a%b);
    }


}


int main()
{
    printf("Hello world!\n");
    printf("%lu  ",GCD(18,35));
    printf("%lu  ",GCD(28851538,1183019));
    return 0;
}
