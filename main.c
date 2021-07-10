#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct student{
    int ID;
    int day,month,year;
    float score;
    struct student *next;
    char name[50];
}StudNode;
typedef struct {            //linked list
    StudNode *head;
    StudNode *tail;
}list;
void list_init(list *l){    //initializing the list
    l->head=NULL;
    l->tail=NULL;
}
StudNode* create_node(int id,int d,int m,int y,float s,char *fn,char *ln){
    StudNode *st;
    st = (StudNode*) malloc(sizeof(StudNode));
    st->ID=id;
    st->day=d;
    st->month=m;
    st->year=y;
    st->score=s;
    strcat(fn," ");
    strcat(fn,ln);
    strcpy(st->name,fn);
    st->next=NULL;
    return st;
}


int add(list *l,StudNode *s,int choice){
    if(choice == 1){
         if (l->head == NULL){       //empty list
            l->head=s;
            l->tail=s;
            }
            else{
                s->next=l->head;        //next of new node is the head
                l->head=s;              //new node becomes the new head
            }
            return 1;
    }
    else if (choice ==2){
        int len=0;
            if (l->head == NULL){       //empty list
                l->head=s;
                l->tail=s;
            }
            else{
                StudNode* st=l->head;
                while(st != NULL){
                    len++;
                    st=st->next;
                }
                int count = ((len % 2) == 0) ? (len / 2) :(len + 1) / 2;        //if len is even count is integer
                st=l->head;
                while(count-- >1)
                    st=st->next;
                s->next=st->next;       //making the next of the new node points to the next of the middle node
                st->next=s;             //making the next of the middle node points to the new node
            }
            return 2;
    }
    else if (choice == 3){
        if (l->head == NULL){       //empty list
            l->head=s;
            l->tail=s;
            }
            else{
                l->tail->next=s;        //making the tail points to the node
                l->tail=l->tail->next;  //the tail takes on step to the new node to make it the last one
            }
            return 3;
    }
    else
        return 0;
}
void print_list(list *l){
    if(l->head == NULL)
	{
		printf("\nEmpty List");
		return;
	}
    StudNode*s=l->head;
    int j=1;
    while(s !=NULL){
        printf("Student no. %d data:    \n",j);
        printf("Name: %s, ID: %d, Date of birth: %d/%d/%d, Last year score: %f\n\n",s->name,s->ID,s->day,s->month,s->year,s->score);
        s=s->next;
        j++;
    }
}

void linkedlist()
{
    int N;
    list *LinkedList;
    int id1,d1,m1,y1,choice;
    float s1;
    char fn1[50],ln1[50];
    LinkedList = (list*) malloc(sizeof(list));
    list_init(LinkedList);
    printf("\t\t\t\t\t\t Welcome to assingment 1\n");
    printf("Enter the number of Students: ");
    scanf( "%d",&N);
    while(N<=0){
        printf("Enter a valid number : ");
        scanf( "%d",&N);
    }
    for(int i=0;i<N;i++){
        printf("Enter student's id:");
        scanf("%d",&id1);
        while (id1<=0){
            printf("Enter a valid number : ");
            scanf( "%d",&id1);
        }


        printf("Enter student's day:");
        scanf("%d",&d1);
        while(d1<=0 || d1 >31){
            printf("Enter a valid number : ");
            scanf( "%d",&d1);
        }
        printf("Enter student's month:");
        scanf("%d",&m1);
        while(m1 <=0 || m1 >12){
            printf("Enter a valid number : ");
            scanf( "%d",&m1);
        }
        printf("Enter student's year:");
        scanf("%d",&y1);
        while(y1 <=0){
            printf("Enter a valid number : ");
            scanf( "%d",&y1);
        }
        printf("Enter student's score:");
        scanf("%f",&s1);
         while(s1 <=0.0){
             printf("Enter a valid number : ");
            scanf( "%f",&s1);
        }
        printf("Enter student's name: ");
        scanf("%s %s",fn1,ln1);
        StudNode *stud=create_node(id1,d1,m1,y1,s1,fn1,ln1);
        printf("1-add first\n 2-add last\n 3-add at middle\n");
        scanf("%d",&choice);
        while(!add(LinkedList,stud,choice)){
            printf("enter a valid number : ");
            scanf("%d",&choice);
        }

    }
    print_list(LinkedList);
}


StudNode *createArray(int N){
StudNode *arr;
arr=(StudNode*)malloc(N*sizeof(StudNode));
if(arr==NULL){
    printf("memory not allocated");
}
return arr;
};


void insertatfirst(int N,StudNode **arr){
int i;
for(i=N-1;i>=0;i--){
(*arr)[i+1]=(*arr)[i];
}
i=0;

printf("Enter the name of new student: ");
    scanf("%s",(*arr)->name);
    printf("Enter the ID of new student: ");
    scanf("%d",&(*arr)->ID);
    printf("Enter the birth day,month and year of new student respectively: ");
    scanf("%d%d%d",&(*arr)->day,&(*arr)->month,&(*arr)->year);
    if((*arr+i)->month==2){
    if((*arr+i)->day>29||(*arr+i)->day<1)
        printf("invalid input");
    exit(0);
    }

else if((*arr+i)->day>31||(*arr+i)->day<1||(*arr+i)->month>12||(*arr+i)->month<1){

    printf("invalid input");

    exit(0);}
else
    printf("Enter the score of new student: ");
    scanf("%f",&(*arr)->score);

}

void insertatmiddle(int N,StudNode **arr){

int i;
for(i=N-1;i>=(N+1)/2;i--){
(*arr)[i+1]=(*arr)[i];
}
i=(N+1)/2;

printf("Enter the name of new student: ");
    scanf("%s",(*arr+i)->name);
    printf("Enter the ID of new student: ");
    scanf("%d",&(*arr+i)->ID);
    printf("Enter the birth day,month and year of new student respectively: ");
    scanf("%d%d%d",&(*arr+i)->day,&(*arr+i)->month,&(*arr+i)->year);
    if((*arr+i)->month==2){
    if((*arr+i)->day>29||(*arr+i)->day<1)
        printf("invalid input");
    exit(0);
    }

else if((*arr+i)->day>31||(*arr+i)->day<1||(*arr+i)->month>12||(*arr+i)->month<1){

    printf("invalid input");
    exit(0);
}else
    printf("Enter the score of new student: ");
    scanf("%f",&(*arr+i)->score);

}

void insertatlast(int N,StudNode **arr){
int i;
i=N;

printf("Enter the name of new student: ");
    scanf("%s",(*arr+i)->name);
    printf("Enter the ID of new student: ");
    scanf("%d",&(*arr+i)->ID);
    printf("Enter the birth day,month and year of new student respectively: ");
    scanf("%d%d%d",&(*arr+i)->day,&(*arr+i)->month,&(*arr+i)->year);
    if((*arr+i)->month==2){
    if((*arr+i)->day>29||(*arr+i)->day<1)
        printf("invalid input");
    exit(0);
    }

else if((*arr+i)->day>31||(*arr+i)->day<1||(*arr+i)->month>12||(*arr+i)->month<1){

    printf("invalid input");
    exit(0);
}else
    printf("Enter the score of new student: ");
    scanf("%f",&(*arr+i)->score);




}

void printarray(StudNode **arr,int N){
 int i;
 int j=1;

 for (i=0;i<=N;i++){

    printf("name of student %d is : %s\n",j,(*arr+i)->name);
printf("ID of student %d is: %d\n",j,(*arr+i)->ID);
printf("birth date of student %d is : %d/%d/%d\n",j,(*arr+i)->day,(*arr+i)->month,(*arr+i)->year);
printf("score of student %d is :  %f\n",j,(*arr+i)->score);
    j++;

 }



}
void dynamic_array()
{int N, a;
StudNode *arr;
int j=1;
printf("Enter number of students: ");
scanf("%d",&N);
if(N==0){

    printf("No student data has been entered");
    exit(0);
}
arr=createArray(N);

for (int i=0;i<N;i++){ //the input of array//

    printf("Enter the name of student %d: ",j);
    scanf("%s",(arr+i)->name);
    printf("Enter the ID of student %d: ",j);
    scanf("%d",&(arr+i)->ID);
    printf("Enter the birth day,month and year of student number %d respectively : ",j);
    scanf("%d%d%d",&(arr+i)->day,&(arr+i)->month,&(arr+i)->year);
    if((arr+i)->month==2){
    if((arr+i)->day>29||(arr+i)->day<1)
        printf("invalid input");

    exit(0);
    }

else if((arr+i)->day>31||(arr+i)->day<1||(arr+i)->month>12||(arr+i)->month<1){

    printf("invalid input");

    exit(0);
}else
    printf("Enter the score of student %d: ",j);
    scanf("%f",&(arr+i)->score);
j++;
}

printf("Choose:1-Insert at first\n2-Insert at middle\n3-Insert at last\n");
scanf("%d",&a);
arr=(StudNode*)realloc(arr,(N+1)*sizeof(StudNode));
if(a==1){
insertatfirst(N,&arr);
}else if(a==2){
insertatmiddle(N,&arr);
}else if(a==3) {
insertatlast(N,&arr);
}else {
printf("invalid input");
exit(0);
}

printarray(&arr,N);

}



int main(){

    int choice;
    printf("choose\n 1-Linked List\n 2- Dynamic array\n 3-Exit\n");
    scanf("%d",&choice);
    if(choice == 1){
        linkedlist();
    }
    else if(choice == 2){
        dynamic_array();
    }
    else{
        exit(0);
    }
    return 0;
};












