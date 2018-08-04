#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define maxSize 10

typedef struct Thread{
int ThreadId;
int endTime;
int isFree;
}Thread;

int array[maxSize] = {5,4,3,2,1,99};
int n = 0;


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
    if (n == 0){return 999;}
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
    int time,i,j,cur,numThreads,njobs,jobcount;
    int jobs[100]= {1,2,3,4,5};
    for (i=0;i<20;i++){jobs[i] = 1;}
    Thread threads[100];
    //printf("Enter Number of threads");
    //scanf("%d",&numThreads);
    numThreads = 4;
    //printf("Enter number of jobs");
    njobs = 20;
    //scanf("%d",&njobs);
    /*for(i = 0;i<njobs;i++){
        scanf("%d",&jobs[i]);
    }*/
    for(i=0;i<numThreads;i++){
            Insert(i);
            threads[i].ThreadId = i;
            threads[i].endTime = 0;
            threads[i].isFree = 1;
    }
    //display();
    time = 0;
    jobcount = 0;
    while(jobcount<njobs && time<10){
    for(j=0;j<numThreads;j++){
        if(threads[j].endTime == time && time != 0){
            threads[j].isFree = 1;
            Insert(threads[j].ThreadId);
            //printf("Inserted thread %d at time %d \n",threads[j].ThreadId,time);
            //display();
        }
    }
    while(cur != 999 && jobcount < njobs){
    cur = ExtractMin();
    if(cur !=999){
    printf("thread id %d          time %d \n",threads[cur].ThreadId,time);
    threads[cur].endTime = time + jobs[jobcount];
    //printf("end time %d \n",threads[cur].endTime);
    threads[cur].isFree = 0;
    jobcount++;}
    }
    cur = 0;
    time++;
    printf("Time incrementd to %d \n",time);
    }
exit(0);
}
