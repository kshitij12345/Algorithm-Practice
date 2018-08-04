#include <stdio.h>
#include <stdlib.h>
#include "queue.h"



void Process(int i){printf("%d \n",i);}

int main()
{   int j,i,s,e;
    Request request;
    Request Buffer[5];
    Request requests[2];
    for(i=0;i<2;i++){
        scanf("%d",&s);
        scanf("%d",&e);
        requests[i].StartTime = s;
        requests[i].EndTime = e;
    }

    j=0;
    i=0 + requests[0].EndTime;
    Insert_Element(&Buffer[0],&requests[0]);
    j++;
    while(j<2){
        while(requests[j].StartTime<i && j<2){
            if(!Full(&Buffer[0])){
                Insert_Element(&Buffer[0],&requests[j]);
                printf("Inserted %d \n",j);
                j++;
            }
            else{
                printf("Full %d \"-1\" \n",j);
                j++;
            }

        }
        request = Delete_Element(&Buffer[0]);
        Process(request.StartTime);
        i = i+ request.EndTime;
    }

    while(!Empty()){
        request = Delete_Element(&Buffer[0]);
        Process(request.StartTime);
    }


    return 0;
}
