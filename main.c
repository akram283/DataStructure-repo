#include <stdio.h>
#include <stdlib.h>

typedef struct student{
    int ID;
    int day,month,year;
    float score;
    char name[50];
}st;


st *createArray(int N){
st *arr;
arr=(st*)malloc(N*sizeof(st));
if(arr==NULL){
    printf("memory not allocated");
}
return arr;
};


void insertatfirst(int N,st **arr){
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
         printf("hello");
    exit(0);
    }

else if((*arr+i)->day>31||(*arr+i)->day<1||(*arr+i)->month>12||(*arr+i)->month<1){

    printf("invalid input");
     printf("hello1");
    exit(0);}
else
    printf("Enter the score of new student: ");
    scanf("%f",&(*arr)->score);

}

void insertatmiddle(int N,st **arr){

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

void insertatlast(int N,st **arr){
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

void printarray(st **arr,int N){
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
int main()
{int N, a;
st *arr;
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
arr=(st*)realloc(arr,(N+1)*sizeof(st));
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


    return 0;
}
