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
     parent[i_id] = j_id;
     if(rank[i_id]==rank[j_id]){
            rank[j_id] = rank[j_id]+1;
     }
    }
}

int main()
{
    int i;
    MakeSet(1);
    for(i = 1;i<4;i++){
        printf("%d ",parent[i]);
    }
    printf("\n");
    MakeSet(2);
    for(i = 1;i<4;i++){
        printf("%d ",parent[i]);
    }
    printf("\n");
    MakeSet(3);
    for(i = 1;i<4;i++){
        printf("%d ",parent[i]);
    }
    printf("\n");
    Union(2,3);
    for(i = 1;i<4;i++){
        printf("%d ",parent[i]);
    }
    printf("\n");
    exit(0);
}
