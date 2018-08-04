#include <stdio.h>
int main(){
    int Din = 0;;
    Din|=1? 0x01<<0:Din;
    printf("%x \n",Din);
    Din|=0? 0x01<<1:Din;
    printf("%x \n",Din);
    Din|=1? 0x01<<2:Din;
    printf("%x \n",Din);
    Din|=1? 0x01<<3:Din;
    printf("%x \n",Din);
    Din|=0? 0x01<<4:Din;
    printf("%x \n",Din);
    Din|=0? 0x01<<5:Din;
    printf("%x \n",Din);
    Din|=0? 0x01<<6:Din;
    printf("%x \n",Din);
    Din|=1? 0x01<<7:Din;
    printf("%x \n",Din);
}
