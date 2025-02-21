#include <stdio.h>
#include <string.h>
typedef struct patientinfo{
    char id[10];
    char name[51];
    int age;
    float bill;
}pi;
void add(pi* a,int *n);
void remove(pi* a,int *n);
void modify(pi* a,int n);
void print(pi* a,int n);

int main(){
    pi a[1000];
    int choice=0,n=0;
    do{
        printf("Please enter a choice:");
        scanf("%d",&choice);
        switch(choice){
            case 0:
            printf("Programme exited\n");
            break;
            case 1:
            add(a,&n);
            n++;
            break;
            case 2:
            remove(a,&n);
            n--;
            break;
            case 3:
            modify(a,n);
            break;
            case 4:
            print(a,n);
            break;
        }
    }while(choice!=0);
    return 0;
}
void add(pi* a,int *n){
    printf("Type Patient ID:");
    scanf("%s",(a+*n)->id);
    printf("Type Patient name:");
    scanf("%s",(a+*n)->name);
    printf("Type Patient age:");
    scanf("%d",&(a+*n)->age);
    printf("Type Patient bill:");
    scanf("%f",&(a+*n)->bill);
    printf("You have successfully entered the details\n\n");
}
void remove(pi* a,int *n){
    int i=0;
    char sid[10];
    printf("Please enter the ID of the patient to remove:\n");
    scanf("%s",sid);
    for(i=0;i<*n;i++){
        if(!strcmp((a+i)->id,sid)){
            break;
        }
    }
    if(i==*n){
        printf("Patient not found\n\n");
        return;
    }
    for(int j=i;j<*n-1;j++){
        *(a+j)=*(a+j+1);
    }
    printf("Patient %s deleted successfully\n\n",sid);
}
void modify(pi* a,int n){
    int i=0;
    char sid[10];
    printf("Please enter the ID of the patient to modify:\n");
    scanf("%s",sid);
    for(i=0;i<n;i++){
        if(!strcmp((a+i)->id,sid)){
            break;
        }
    }
    if(i==n){
        printf("Patient not found\n\n");
        return;
    }
    printf("Type Patient ID:");
    scanf("%s",(a+i)->id);
    printf("Type Patient name:");
    scanf("%s",(a+i)->name);
    printf("Type Patient age:");
    scanf("%d",&(a+i)->age);
    printf("Type Patient bill:");
    scanf("%f",&(a+i)->bill);
    printf("You have successfully modified the details of patient %s\n\n",sid);
}
void print(pi* a,int n){
    for(int i=0;i<n;i++){
        printf("Patient %d\n",i+1);
        printf("ID:%s\n",(a+i)->id);
        printf("Name:%s\n",(a+i)->name);
        printf("Age:%d\n",(a+i)->age);
        printf("Bill:%f\n\n",(a+i)->bill);
    }
}