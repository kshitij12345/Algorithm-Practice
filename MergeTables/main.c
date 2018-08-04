#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 200
int parent[MAXSIZE];
int rank[MAXSIZE];

int Find(int i){
    if (i !=parent[i]){
        parent[i]=Find(parent[i]);
    }

    return parent[i];

}

void MakeSet(int i){
    parent[i]=i;
    rank[i]=0;
}

void Union(int i , int j){
    int i_id,j_id;
    i_id = Find(i);
    j_id = Find(j);

    if(i_id == j_id){
    return ;
    }

    if( rank[i_id] > rank[j_id]){
        parent[j_id] = i_id;
    }else{
     parent[j_id] = i_id;
     if(rank[i_id]==rank[j_id]){
            rank[i_id] = rank[i_id]+1;
     }
    }
}

typedef struct SrcDest{
int src;
int des;
}SrcDest;


int main()
{
    int numDatabases,i,numRequests,par,parsrc;
    int rows[200] = {10,0,5,0,3,3};
    numDatabases = 6;
    for(i = 0;i<numDatabases;i++){
        MakeSet(i);
    }
    SrcDest requests[100];
    numRequests = 4;
    for(i = 0;i<numRequests;i++){
        printf("%Request %d ",i);
        scanf("%d",&requests[i].des);
        scanf("%d",&requests[i].src);
    }
    for(i = 0;i<numRequests;i++){
        par = Find(requests[i].des-1);
        parsrc = Find(requests[i].src-1);
        if(par == parsrc ){continue;}
        Union(par,parsrc);
        rows[par] += rows[parsrc];
        rows[parsrc] = 0;

    }
    printf("Request %d \n",i);
        for(i = 0;i<6;i++){
            printf("%d ",parent[i]);
        }
        printf("\n");
        for(i = 0;i<6;i++){
            printf("%d ",rank[i]);
        }
        printf("\n");
        for(i = 0;i<6;i++){
            printf("%d ",rows[i]);
        }
        printf("\n");
    /*for(i = 0;i<6;i++){
        printf("%d ",parent[i]);
    }
    printf("\n");
    for(i = 0;i<6;i++){
        printf("%d ",rank[i]);
    }
    printf("\n");
    for(i = 0;i<6;i++){
        printf("%d ",rows[i]);
    }*/
    exit(0);
}
