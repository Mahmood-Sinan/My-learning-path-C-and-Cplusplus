#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct studentinfo{
   char name[10];
   int age;
   struct studentinfo *next;
}si;
void scan(si *info){
    printf("Enter name:");
    scanf("%s",info->name);
    printf("Enter age:");
    scanf("%d",&info->age);
    printf("\n");
}
int main (){
    si info;
    int choice=0;
    si* head=NULL,*temp=NULL,*ptr=NULL,*temp1=NULL;
    do{
        printf("0-exit\n1-addatend\n2-addbetween\n3-addbeginning\n4-dltend\n5-dltbetween\n6-dltbeginning\n7.printall\n8.savetxt\n9.readtxt\n10.savebin\n11.readbin\n12.deleteall\n\n");
        scanf("%d",&choice);
        switch(choice){
            case 0:
            exit(1);
            break;
            case 1:
            ptr=(si*)malloc(sizeof(si));
            scan(&info);
            *ptr=info;
            if(head==NULL){
                head=ptr;
                head->next=NULL;
                temp=head;
            }
            else{
                while(temp->next!=NULL){
                    temp=temp->next;
                }
                temp->next=ptr;
                ptr->next=NULL;
                temp=ptr;
            }
            break;
            case 2:
            char s[10];
            printf("Enter the search id to add after:");
            scanf("%s",s);
            for(temp1=head;temp1!=NULL;temp1=temp1->next){
                if(!strcmp(temp1->name,s)){
                    break;
                }
            }
            ptr=(si*)malloc(sizeof(si));
            scan(&info);
            *ptr=info;
            ptr->next=temp1->next;
            temp1->next=ptr;
            break;
            case 3:
            ptr=(si*)malloc(sizeof(si));
            scan(&info);
            *ptr=info;
            ptr->next=head;
            head=ptr;
            break;
            case 4:
            temp=head;
            temp1=NULL;
            if(head->next==NULL){
                free(head);
                head=NULL;
            }
            else{
                while(temp->next!=NULL){
                    temp1=temp;
                    temp=temp->next;
                }
                free(temp);
                temp1->next=NULL;
            }
            break;
            case 5:
            printf("Enter the name to search:");
            scanf("%s",s);
            temp=head;
            temp1=temp;
            if(!strcmp(head->name,s)){
                head=head->next;
                free(temp);
            }
            else{
                while(temp->next!=NULL){
                    if(!strcmp(temp->name,s)){
                        break;
                    }
                    temp1=temp;
                    temp=temp->next;
                }
                temp1->next=temp->next;
                free(temp);
            }
            break;
            case 6:
            temp=head;
            head=head->next;
            free(temp);
            break;
            case 7:
            for(temp1=head;temp1!=NULL;temp1=temp1->next){
                printf("Name:%s Age:%d\n",temp1->name,temp1->age);
            }
            printf("\n");
            break;
            case 8:
            FILE *fp=fopen("mydata.txt","w");
            temp=head;
            while(temp!=NULL){
                fprintf(fp,"%s %d\n",temp->name,temp->age);
                temp=temp->next;
            }
            fclose(fp);
            break;
            case 9:
            fp=fopen("mydata.txt","r");
            while(!feof(fp)){
                fscanf(fp,"%s %d",info.name,&info.age);
                //addatend
                ptr=(si*)malloc(sizeof(si));
                *ptr=info;
                if(head==NULL){
                    head=ptr;
                    head->next=NULL;
                    temp=head;
                }
                else{
                    while(temp->next!=NULL){
                        temp=temp->next;
                    }
                    temp->next=ptr;
                    ptr->next=NULL;
                    temp=ptr;
                }
            }
            fclose(fp);
            //deleteend
            temp=head;
            temp1=NULL;
            if(head->next==NULL){
                free(head);
                head=NULL;
            }
            else{
                while(temp->next!=NULL){
                    temp1=temp;
                    temp=temp->next;
                }
                free(temp);
                temp1->next=NULL;
            }
            break;
            case 10:
            fp=fopen("mydata.bin","wb");
            temp=head;
            while(temp!=NULL){
                fwrite(temp,sizeof(si),1,fp);
                temp=temp->next;
            }
            fclose(fp);
            break;
            case 11:
            fp=fopen("mydata.bin","rb");
            while(!feof(fp)){
                fread(&info,sizeof(si),1,fp);
                //addatend
                ptr=(si*)malloc(sizeof(si));
                *ptr=info;
                if(head==NULL){
                    head=ptr;
                    head->next=NULL;
                    temp=head;
                }
                else{
                    while(temp->next!=NULL){
                        temp=temp->next;
                    }
                    temp->next=ptr;
                    ptr->next=NULL;
                    temp=ptr;
                }
            }
            fclose(fp);
            //deleteend
            temp=head;
            temp1=NULL;
            if(head->next==NULL){
                free(head);
                head=NULL;
            }
            else{
                while(temp->next!=NULL){
                    temp1=temp;
                    temp=temp->next;
                }
                free(temp);
                temp1->next=NULL;
            }
            break;
            case 12:
            temp=head;
            si *to_delete=NULL;
            while(temp!=NULL){
                to_delete=temp;
                temp=temp->next;
                free(to_delete);
            }
            head=NULL;
            break;
        }
    }while(choice!=0);
    return 0;
}