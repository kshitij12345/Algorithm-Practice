#include<stdio.h>
#include<string.h>

int hash_func(char *s);
void RabinKarp(char* s,char* p);
int * pre_hash_func(char* s,char* p);
int main()
{
    RabinKarp("geek for geek","or");
    exit(0);
}

void RabinKarp(char* s,char* p){
int result[10];
int i;
int lens = strlen(s);
int lenp = strlen(p);
int pHash = hash_func(p);
int* h = pre_hash_func(s,p);
for(i = 0;i<lens-lenp;i++){
    if (pHash != h[i]){
        continue;
    }
    else{
    AreEqual(s,p,i);
    }
}
}

int AreEqual(char* s,char* p,int ii){
    int i;
    int lenp = strlen(p);
    for(i = ii;i<ii+lenp;i++){
        if(s[i]!=p[i]){return 0;}
    }
    printf("%d \n",ii);
    return 1;
}


int hash_func(char *s){
        int prime = 11;
        int multiplier = 263;
        int ans = 0;
        int len = strlen(s);
        int i;
        for (i =0;i<len;i++){
            printf("%c",s[i]);
            ans = (ans * multiplier + s[i])%prime;
            }
        printf(" \n");
        //if(ans<0){ans=ans+prime;}
        return ans;
}

int* pre_hash_func(char* s,char* p){
        int lens = strlen(s);
        int lenp = strlen(p);
        int h[lens-lenp+1];
        int te;
        int prime = 11;
        int multiplier = 263;
        int ans = 0;
        int y = 1;
        int i;
        char temp[1000];
        int t = 0;
        //printf("Hash string \n");
        for(i = 0;i<lenp;i++){
            temp[i] = s[i];
        }
        //for(i = t-1;i>=0;i--){printf("%c ",temp[i]);}
        //printf("%d \n",t);
        h[0]=hash_func(temp);
        for (i=0;i<lenp;i++){
            y = (y*multiplier)%prime;
        }
        for(i=1;i<lens-lenp;i++){
            //printf("%c        %c \n",s[i],s[i+lenp]);
            h[i]=(multiplier*(h[i-1]+y*s[i])+s[i+lenp])%prime;
            printf("%d ", i);
            }
        return &h;
}
