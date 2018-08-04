#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define maxSize 10
int array[maxSize] = {1,2,3,4,56,6,7,200,300};
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
int temp = *a;
*a = *b;
*b = temp;
}

void SiftUp(int i){
    while(i>0 && array[ParentNode(i)]<array[i]){
        Swap(&array[ParentNode(i)],&array[i]);
        i = ParentNode(i);
    }
}

void SiftDown(int i){
    int maxIndex,l,r;
    maxIndex = i;
    l = leftChild(i);
    if(l<=n && array[l]>array[maxIndex])
    {
        maxIndex = l;
    }

    r = rightChild(i);
    if(r<=n && array[r]>array[maxIndex])
    {
        maxIndex = r;
    }

    if(i!= maxIndex){
        Swap(&array[i],&array[maxIndex]);
        SiftDown(maxIndex);
    }
}

int Insert(int p){
    if (n == maxSize)
    {
        return 0;
    }
    n++;
    array[n] = p;
    SiftUp(n);
    return 1;
}

int ExtractMax(){
    int result = array[1];
    array[1] = array[n];
    n = n - 1;
    SiftDown(1);
    return result;
}

void Remove(int i){
    array[i] = 999;
    SiftUp(i);
    ExtractMax();
}


void display()
{
    int i;
    if (n == 0)
    {
        printf("Heap is empty \n");
        return;
    }
    for (i = 0; i < 10; i++)
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
    n = 9;
    //n = ;/*Represents number of nodes in the heap*/

    BuildHeap();

    display();

    exit(0);

}/*End of main()*/
