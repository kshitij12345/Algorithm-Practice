#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED


#include<stdio.h>
#include<conio.h>
#define MAX 2
int front = -1, rear = -1;
typedef struct Request{
int StartTime;
int EndTime;
}Request;


/******************************************/
int Insert_Element(Request* queue,Request *num)
{
if (rear < MAX - 1)
{
if (front == -1)
/*when queue is initially empty */
front = 0;
rear = rear + 1;
queue[rear] = *num;
return 1;
}
else
{
return 0;
}
}

int Full(Request* queue){
if (rear >= MAX -1)
{
return 1;
}
else{return 0;};
}

int Empty(){
if (front == -1 || front > rear){
    return 1;
}
else{
    return 0;
}

}


Request Delete_Element(Request* queue)
{
    Request element;
if (front == -1 || front > rear)
{

}
else
{
element = queue[front];
//printf("\n Element deleted from queue is : %d", element);
front = front + 1;
return element;
}
}
/*
void Display_Queue(Request* queue[])
{
int i;
if (front == -1 || front > rear)
printf("\n No elements to display");
else
{
printf("\n The queue elements are:\n ");
for (i = front; i <= rear; i++)
{
printf("\t %d", queue[i]);
}
}
}*/

void Empty_Queue(Request* queue[])
{
/*Reset queue or Creates Empty queue*/
front = -1;
rear = -1;
printf("\n New Queue created successfully.");
}


#endif // QUEUE_H_INCLUDED
