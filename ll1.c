#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct studentinfo
{
   char id[10];
   char name[51];
   int age;
   float cgpa;
   struct studentinfo *next;
} si;
void scansi(si *info);
void add(si **head, si info);
void dlt(si **head);
void edit(si *head);
void print(si *head);
void saveintxt(si *head);
void loadintxt(si **head);
void saveinbin(si *head);
void loadinbin(si **head);

int main()
{
   int choice = 0;
   si *head = NULL;
   si info;
   do
   {
      printf("\n1.Add at end\n2.Delete by id\n3.Edit by id\n4.Print all\n5.Save in txt\n6.Load from txt\n7.Save in bin\n8.Load in bin\n\n");
      printf("Enter a choice:");
      scanf("%d", &choice);
      switch (choice)
      {
      case 0:
         printf("Programme exited\n\n");
         break;
      case 1:
         scansi(&info);
         add(&head, info);
         break;
      case 2:
         dlt(&head);
         break;
      case 3:
         edit(head);
         break;
      case 4:
         print(head);
         break;
      case 5:
         saveintxt(head);
         break;
      case 6:
         loadintxt(&head);
         break;
      case 7:
         saveinbin(head);
         break;
      case 8:
         loadinbin(&head);
         break;
      }
   } while (choice != 0);
}
void add(si **addofhead, si info)
{
   si *temp = *addofhead, *ptr = NULL;
   if (*addofhead == NULL)
   {
      *addofhead = (si *)malloc(sizeof(si));
      **addofhead = info;
      (*addofhead)->next = NULL;
   }
   else
   {
      while (temp->next != NULL)
      {
         temp = temp->next;
      }
      ptr = (si *)malloc(sizeof(si));
      *ptr = info;
      ptr->next = NULL;
      temp->next = ptr;
   }
}
void dlt(si **addofhead)
{
   char sid[10];
   printf("Enter the id to delete:");
   scanf("%s", sid);
   si *temp = *addofhead;
   si *temp1 = NULL;
   while (temp->next != NULL)
   {
      if (strcmp(temp->id, sid) == 0)
      {
         break;
      }
      else
      {
         temp1 = temp;
         temp = temp->next;
      }
   }
   if (temp == *addofhead)
   {
      *addofhead = (*addofhead)->next;
      free(temp);
   }
   else
   {
      if (temp->next == NULL && strcmp(temp->id, sid) != 0)
      {
         printf("Student not found\n\n");
         return;
      }
      else
      {
         temp1->next = temp->next;
         free(temp);
      }
   }
}
void edit(si *head)
{
   char sid[10];
   printf("Enter the Student ID to edit:");
   scanf("%s", sid);
   si *temp = head;
   si info;
   while (temp != NULL)
   {
      if (strcmp(temp->id, sid) == 0)
      {
         break;
      }
      else
      {
         temp = temp->next;
      }
   }
   if (temp == NULL)
   {
      printf("Student not found\n\n");
      return;
   }
   else
   {
      scansi(&info);
      info.next = temp->next;
      *temp = info;
   }
}
void print(si *head)
{
   si *temp = head;
   while (temp != NULL)
   {
      printf("ID:%s  ", temp->id);
      printf("Name:%s  ", temp->name);
      printf("Age:%d  ", (*temp).age);
      printf("CGPA:%f\n", (*temp).cgpa);
      temp = temp->next;
   }
}
void scansi(si *info)
{
   printf("Enter the details\n");
   printf("Enter the student ID:");
   scanf("%s", (*info).id);
   printf("Enter the student Name:");
   scanf("%s", (*info).name);
   printf("Enter the student age:");
   scanf("%d", &(*info).age);
   printf("Enter the student CGPA:");
   scanf("%f", &(*info).cgpa);
   printf("Student added successfully\n");
}
void saveintxt(si *head)
{
   FILE *fp;
   fp = fopen("mydata.txt", "w");
   while (head != NULL)
   {
      fprintf(fp, "%s %s %d %f\n", head->id, head->name, head->age, head->cgpa);
      head = head->next;
   }
   fclose(fp);
}
void loadintxt(si **addofhead)
{
   FILE *fp;
   fp = fopen("mydata.txt", "r");
   si *temp = *addofhead;
   while (temp != NULL)
   {
      si *to_delete = temp;
      temp = temp->next;
      free(to_delete);
   }
   *addofhead = NULL;
   si info;
   si *temp1 = NULL;
   while (!feof(fp))
   {
      fscanf(fp, "%s %s %d %f", info.id, info.name, &info.age, &info.cgpa);
      add(addofhead, info);
   }
   fclose(fp);
   //delete last
   temp = *addofhead, temp1 = temp;
   while ((temp->next) != NULL)
   {
      temp1 = temp;
      temp = temp->next;
   }
   temp1->next = NULL;
   free(temp);
}
void saveinbin(si *head)
{
   FILE *fp;
   fp = fopen("mydata.bin", "wb");
   while (head != NULL)
   {
      fwrite(head, sizeof(si), 1, fp);
      head = head->next;
   }
   fclose(fp);
}
void loadinbin(si **addofhead)
{
   FILE *fp;
   fp = fopen("mydata.bin", "rb");
   // to delete the list fully
   si *temp = *addofhead;
   while (temp != NULL)
   {
      si *to_delete = temp;
      temp = temp->next;
      free(to_delete);
   }
   *addofhead = NULL;
   // to read the list fully
   si info;
   si *ptr = NULL, *temp1 = NULL;
   while (!feof(fp))
   {
      fread(&info, sizeof(si), 1, fp);
      add(addofhead, info);
   }
   fclose(fp);
   // to delete the last node
   temp = *addofhead, temp1 = temp;
   while ((temp->next) != NULL)
   {
      temp1 = temp;
      temp = temp->next;
   }
   temp1->next = NULL;
   free(temp);
}