#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define maxSize 10
int array[maxSize] = {5,4,3,2,1,99};
int n = 1;


int leftChild(int i ){
return ((2*i)+1);
}

int rightChild(int i ){
return ((2*i)+2);
}

int ParentNode(int i){
return (int)floor((i-1)/2);
}

void Swap(int* a,int* b){
//printf("%d   %d \n",*a,*b);
int temp = *a;
*a = *b;
*b = temp;
}

void SiftUp(int i){
    while(i>=0 && array[ParentNode(i)]>array[i]){

        Swap(&array[ParentNode(i)],&array[i]);
        i = ParentNode(i);
    }
}

void SiftDown(int i){
    int minIndex,l,r;
    minIndex = i;
    l = leftChild(i);
    if(l<=n-1 && array[l]<array[minIndex])
    {
        minIndex = l;
    }

    r = rightChild(i);
    if(r<=n-1 && array[r]<array[minIndex])
    {
        minIndex = r;
    }

    if(i!= minIndex){
        //printf("%d   %d \n",i,maxIndex);
        Swap(&array[i],&array[minIndex]);
        SiftDown(minIndex);
    }
}

int Insert(int p){
    if (n == maxSize)
    {
        return 0;
    }
    n++;
    array[n-1] = p;
    //display();
    SiftUp(n-1);
    return 1;
}

int ExtractMin(){
    int result = array[0];
    array[0] = array[n-1];
    n = n - 1;
    SiftDown(0);
    return result;
}

void Remove(int i){
    array[i] = 999;
    SiftUp(i);
    ExtractMin();
}


void display()
{
    int i;
    if (n == 0)
    {
        printf("Heap is empty \n");
        return;
    }
    for (i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}

void BuildHeap()
{
    int i;
    for(i =(int)floor((n)/2);i>=0;i--){
        //printf("%d \n",i);
        SiftDown(i);
    }
}



int main()
{
    //int choice, num;
    n = 5;
    //n = ;/*Represents number of nodes in the heap*/
    display();
    BuildHeap();

    display();
    Insert(1);
    display();
    Insert(0);
    display();
    ExtractMin();
    printf("Extract");
    display();
    ExtractMin();
    printf("Extract");
    display();
    ExtractMin();
    printf("Extract");
    display();
    exit(0);

}/*End of main()*/
