#include <stdio.h>
#include <stdlib.h>

typedef struct{
int num;
char* name;
}Phone;

Phone phonebook[100];
int phonecount =0;
void addName(int num,char* name){
    phonebook[phonecount].num = num;
    phonebook[phonecount].name = name;
    phonecount++;
}

char* find(int num){
int i;

for (i=0;i<phonecount;i++){
    //printf("%d      %d \n",phonebook[i].num,num);
    if(phonebook[i].num == num){
        return phonebook[i].name;
    }
}
return "N";
}

void DeleteIfPresent(int num){
    int i;
    for (i=0;i<phonecount;i++){
        if(phonebook[i].num == num){
               phonebook[i]=phonebook[phonecount-1];
               phonecount--;
               return;
    }
}
}

void Display(){
    int i;
    for (i = 0;i<phonecount;i++){
        printf("Number %d ",phonebook[i].num);
    }
}



int main()
{
    addName(911,"Police");
    Display();
    printf("\n");
    addName(76213,"Mom");
    Display();
    printf("\n");
    addName(234,"Bob");
    Display();
    printf("\n");
    //printf("%c",*(find(234)));
    DeleteIfPresent(911);
    Display();
    printf("%c",*(find(234)));

    return 0;
}
