#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
   int data;
   int key;
   struct node *next;
}node;


//display the list
void printList(node *head) {
   struct node *ptr = head;
   printf ("\n");

   //start from the beginning
   while(ptr != NULL) {
      printf("(%d,%d) ",ptr->key,ptr->data);
      ptr = ptr->next;
   }

   printf(" ]");
}

//insert link at the first location
void insertFirst(node** head,int key, int data) {
   //create a link
   struct node *link = (struct node*) malloc(sizeof(struct node));

   link->key = key;
   link->data = data;

   //point it to old first node
   link->next = *head;

   //point first to new first node
   *head = link;
}

//delete first item
struct node* deleteFirst(node** head) {

   //save reference to first link
   struct node *tempLink = *head;

   //mark next to first link as first
   *head = (*head)->next;

   //return the deleted link
   return tempLink;
}

//is list empty
bool isEmpty(node* head) {
   return head == NULL;
}

int length(node* head) {
   int length = 0;
   struct node *current;

   for(current = head; current != NULL; current = current->next) {
      length++;
   }

   return length;
}

//find a link with given key
struct node* find(node** head,int key) {

   //start from the first link
   struct node* current = *head;

   //if list is empty
   if(*head == NULL) {
      return NULL;
   }

   //navigate through list
   while(current->key != key) {

      //if it is last node
      if(current->next == NULL) {
         return NULL;
      } else {
         //go to next link
         current = current->next;
      }
   }

   //if data found, return the current Link
   return current;
}

//delete a link with given key
struct node* delete(node** head,int key) {

   //start from the first link
   struct node* current = *head;
   struct node* previous = NULL;

   //if list is empty
   if(*head == NULL) {
      return NULL;
   }

   //navigate through list
   while(current->key != key) {

      //if it is last node
      if(current->next == NULL) {
         return NULL;
      } else {
         //store reference to current link
         previous = current;
         //move to next link
         current = current->next;
      }
   }

   //found a match, update the link
   if(current == *head) {
      //change first to point to next link
      *head = (*head)->next;
   } else {
      //bypass the current link
      previous->next = current->next;
   }

   return current;
}

void sort(node** head) {

   int i, j, k, tempKey, tempData;
   struct node *current;
   struct node *next;

   int size = length(*head);
   k = size ;

   for ( i = 0 ; i < size - 1 ; i++, k-- ) {
      current = *head;
      next = (*head)->next;

      for ( j = 1 ; j < k ; j++ ) {

         if ( current->data > next->data ) {
            tempData = current->data;
            current->data = next->data;
            next->data = tempData;

            tempKey = current->key;
            current->key = next->key;
            next->key = tempKey;
         }

         current = current->next;
         next = next->next;
      }
   }
}

void reverse(node** head_ref) {
   struct node* prev   = NULL;
   struct node* current = *head_ref;
   struct node* next;

   while (current != NULL) {
      next  = current->next;
      current->next = prev;
      prev = current;
      current = next;
   }

   *head_ref = prev;
}

/*main() {
    node *head[2] = {NULL,NULL};
    //struct node *current = NULL;
   insertFirst(&head[0],1,10);
   insertFirst(&head[1],2,20);
   insertFirst(&head[0],3,30);
   insertFirst(&head[1],4,1);
   insertFirst(&head[0],5,40);
   insertFirst(&head[1],6,56);

   printf("Original List1: ");

   //print list
   printList(head[0]);
   printf(" \n Original List2: ");

   //print list
   printList(head[1]);

   /*while(!isEmpty(head)) {
      struct node *temp = deleteFirst(&head);
      printf("\nDeleted value:");
      printf("(%d,%d) ",temp->key,temp->data);
   }

   printf("\nList after deleting all items: ");
   printList(head);
   insertFirst(&head,1,10);
   insertFirst(&head,2,20);
   insertFirst(&head,3,30);
   insertFirst(&head,4,1);
   insertFirst(&head,5,40);
   insertFirst(&head,6,56);

   printf("\nRestored List: ");
   printList(head);
   printf("\n");

   struct node *foundLink = find(&head,4);

   if(foundLink != NULL) {
      printf("Element found: ");
      printf("(%d,%d) ",foundLink->key,foundLink->data);
      printf("\n");
   } else {
      printf("Element not found.");
   }

   delete(&head,4);
   printf("List after deleting an item: ");
   printList(head);
   printf("\n");
   foundLink = find(&head,4);

   if(foundLink != NULL) {
      printf("Element found: ");
      printf("(%d,%d) ",foundLink->key,foundLink->data);
      printf("\n");
   } else {
      printf("Element not found.");
   }

   printf("\n");
   sort(&head);

   printf("List after sorting the data: ");
   printList(head);

   reverse(&head);
   printf("\nList after reversing the data: ");
   printList(head);
}*/

long long hash_func(char *s,int len){
        long long bucket_count = 5;
        long long prime = 1000000007;
        long long multiplier = 263;
        long long ans = 0;
        int i;
        for (i =len-1;i>=0;i--){
            ans = (ans * multiplier + (long long)s[i])%prime;
            }
        return ans%bucket_count ;
}

void addHash(char *s,int len){
    int hash = hash_func(s,len);
    insertFirst(buckets[hash])
}
node* buckets[5];
int main(){

}
