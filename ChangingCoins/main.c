#include <stdio.h>
#include <stdlib.h>
int CoinList[3] = {10,5,1};
int ChangeCoins(int Max){
    int Curr,Coins,i;
    Coins = 0;
    Curr = Max;
    while(Curr!=0){
        for (i=0;i<3;i++){
            if(CoinList[i]<=Curr){
                Curr = Curr - CoinList[i];
                Coins++;
                break;
            }
        }
    }
    return Coins;

}



int main()
{
    printf("%d ",ChangeCoins(28));
    return 0;
}

