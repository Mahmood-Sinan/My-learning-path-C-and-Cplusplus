#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct studentinfo{
   char id[10];
   char name[51];
   int age;
   float cgpa;
   struct studentinfo *next;
}si;
void scansi(si *info);
void add(si** head,si info);
void remove(si** head);
void edit(si* head);
void print(si *head);
int main(){
   int choice=0;
   si* head=NULL;
   si info;
   do{
      printf("Enter a choice:");
      scanf("%d",&choice);
      switch(choice){
         case 0:
         printf("Programme exited\n\n");
         break;
         case 1:
         scansi(&info);
         add(&head,info);
         break;
         case 2:
         remove(&head);
         break;
         case 3:
         edit(head);
         break;
         case 4:
         print(head);
         break;
      }
   }while(choice!=0);
}
void add(si** addofhead,si info){
   si* temp=*addofhead,*ptr=(si*)malloc(sizeof(si));
   *ptr=info;
   ptr->next=NULL;
   if(*addofhead==NULL){
      *addofhead=ptr;
   }
   else{
      while(temp->next!=NULL){
         temp=temp->next;
      }
      temp->next=ptr;
   }
}
void remove(si** addofhead){
   char sid[10];
   si *temp=*addofhead, *temp1=NULL;
   printf("Enter the student id to delete:");
   scanf("%s",sid);
   while(temp!=NULL&&strcmp(sid,temp->id)!=0){
      temp1=temp;
      temp=temp->next;
      if(temp==NULL){
         break;
      }
   }
   if(temp==NULL){
      printf("Student not found\n\n");
      return;
   }
   temp1->next=temp->next;
   free(temp);
   printf("Student deleted successfully\n\n");
}
void edit(si* head){
   char sid[10];
   si* temp=head;
   si info;
   printf("Enter the student id to search:");
   scanf("%s",sid);
   while(temp!=NULL&&strcmp(sid,temp->id)!=0){
      temp=temp->next;
   }
   if(temp==NULL){
      printf("Student not found\n\n");
      return;
   }
   scansi(&info);
   *temp=info;
   printf("Student modified successfully\n\n");
}
void print(si *head){
   si* temp=head;
   while(temp!=NULL){
      printf("ID:%s\n",temp->id);
      printf("Name:%s\n",temp->name);
      printf("Age:%d\n",temp->age);
      printf("CGPA:%0.1f\n\n",temp->cgpa);
      temp=temp->next;
   }
}
void scansi(si *info){
   printf("Enter the details\n");
   printf("Enter the student ID:");
   scanf("%s",(*info).id);
   printf("Enter the student Name:");
   scanf("%s",(*info).name);
   printf("Enter the student age:");
   scanf("%d",&(*info).age);
   printf("Enter the student CGPA:");
   scanf("%f",&(*info).cgpa);
   printf("Student added successfully\n");
}