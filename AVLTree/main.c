#include <stdio.h>
#include <stdlib.h>
#define max(a,b) (((a)>(b))?(a):(b))

typedef struct Node{
int Key;
int height;
struct Node* Parent;
struct Node* Right;
struct Node* Left;
}Node;

Node* Find(int k,Node* R){
if (R->Key == k){
    return R;
}
else if(R->Key > k){
    if(R->Left != NULL){
        return Find(k,R->Left);
    }
    return R;
}else if(R->Key < k){
    if(R->Right != NULL){
    return Find(k,R->Right);
    }
    return R;
}
}

Node* LeftDescendant(Node* N){

    if(N->Left == NULL){
        return N;
    }else{
        return LeftDescendant(N->Left);
    }
}

Node* RightAncestor(Node* N){
    if(N->Parent == NULL){return NULL;}
    if(N->Key < (N->Parent)->Key){
        return N->Parent;
    }else{
        return RightAncestor(N->Parent);
    }
}


Node* Next(Node* N){
    if (N->Right != NULL){
        return LeftDescendant(N->Right);
    }
    else{
        return RightAncestor(N);
    }
}
//Implement Later
/*RangeSearch(int x,int y,Node* R){
Node* Nodes[10],N;
N = Find(x,R)
while(N->Key <= y){
    if(N->Key >= x){

    }
}
}*/

void Insert(int k,Node* R){
    Node* P = Find(k,R);
    Node N;
    N.Key = k;
    N.Parent = P;
    N.Left = NULL;
    N.Right = NULL;
    N.height = 0;

    if (R->Key > k){
        R->Left = &N;
    }
    if (R-Key < k){
        R->Right =&N;
    }
}
/*
void Delete(Node* N){
if N->Right
}*/
AdjustHeight(Node* N){

N->height = 1 + max(N->Left->height,N-Right->height);

}

void RebalanceRight(Node* N){
Node* M = N->Left;
if(M->Right->height > M->Left-height){
    RotateLeft(M);
}
RotateRight(N);
AdjustHeight(N);
}


void Rebalance(Node* N){

    Node* P = N->Parent;
    if((N->Left)->height > (N->Right)->height+1){
        RebalanceRight(N);
    }
    if(N->Right->height > N->Left->height+1){
        RebalanceLeft(N);
    }
    AdjustHeight(N);
    if(P != NULL){
        Rebalance(P);
    }
}

void AVLInsert(int k,Node* R){
    Insert(k,R);
    Node* N = Find(k,R);
    Rebalance(N);
}






int main()
{

    return 0;
}
