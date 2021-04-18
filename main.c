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
void Add_at_head(list *l,StudNode*s){
    if (l->head == NULL){       //empty list
        l->head=s;
        l->tail=s;
    }
    else{
        s->next=l->head;        //next of new node is the head
        l->head=s;              //new node becomes the new head
    }
}
void Add_at_tail(list *l,StudNode *s){
    if (l->head == NULL){       //empty list
        l->head=s;
        l->tail=s;
    }
    else{
        l->tail->next=s;        //making the tail points to the node
        l->tail=l->tail->next;  //the tail takes on step to the new node to make it the last one
    }
}
void Add_at_middle(list *l,StudNode *s){
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

int main()
{
    int N;
    list *LinkedList;
    int id1,d1,m1,y1;
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
        Add_at_tail(LinkedList,stud);
    }
    print_list(LinkedList);
    return 0;
}
