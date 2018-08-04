#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10
int TreeHeight();
int pathlength(int i);
int Parents[]= {-1,0,0,0,0};
int main()
{
    printf("%d",TreeHeight());
    return 0;
}

int pathlength(int i){
    if (Parents[i]==-1){
        return 0;
        }
    else{
        return 1+pathlength(Parents[i]);
    }
}

int TreeHeight(){
int i,maxlength=0;
for (i=0;i<5;i++){
    if(pathlength(i)>maxlength){
        maxlength = pathlength(i);
    }
}
return maxlength;
}
