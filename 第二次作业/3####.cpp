#include<stdio.h>
#include<stdlib.h>
#define M 20


//定义学生的结构体
 typedef struct node
 {
    int id;
    char name[M];
    char classroom[M];
    float score;
    struct node *next;
 }student;
student *init()
{
    student *p,*q,*head;
    int i,a;
    int n=0;
    printf("输入学生信息的个数\n");
    scanf("%d",&a);

    head=NULL;
    for(i=0;i<a;i++)
    {
        p=(student *)malloc(sizeof(student));
        printf("输入第%d个学生的信息\n",i+1);
        printf("学号:");
        scanf("%d",&p->id);
        printf("姓名：");
        getchar();
        gets(p->name);
        printf("班级:");
        gets(p->classroom);
        printf("成绩:");
        scanf("%f",&p->score);
        n=n+1;
        if(n==1)
        {
            head=p;
            q=p;
            q->next=NULL;

        }else
        {
            q->next=p;
            q=p;
            p->next=NULL;
        }
    }
    return head;
}
void display (student *head)
{
    student *p=head;
    while(p)
    {
        printf("学生的学号为%d，姓名为%s，班级为%s，分数为%f\n",p->id,p->name,p->classroom,p->score);
        p=p->next;
    }
}

student *addStudent(student *head)
{
    student *p,*q;
    q=head;
    while(q->next) q=q->next;
     p=(student *)malloc(sizeof(student));
        printf("学号：");
        scanf("%d",&p->id);
        printf("姓名：");
        getchar();
        gets(p->name);
        printf("班级:");
        gets(p->classroom);
        printf("成绩:");
        scanf("%f",&p->score);
        p->next=NULL;
        q->next=p;
        return head;
}

student *deleteStudent(student *head)
{
    int a;
    student *pre=NULL,*p;
    printf("请输入要删除的id");
    scanf("%d",&a);
    if(!head) {printf("系统中已经没有数据可以删除\n");return head;}
    p=head;
    while(p&&p->id!=a)
    {
        pre=p;
        p=p->next;
    }
    if(p)
    {
        if(!pre) head =head->next;
        else pre->next=p->next;
        free(p);
    }
    return head;

}

student *correctStudent(student *head)
{
    int a;
    student *p;
    printf("请输入要修改的学生的id");
    scanf("%d",&a);
    if(!head) {printf("系统中已经没有数据可以修改\n");return head;}
    p=head;
    while(p&&p->id!=a)
    {
        p=p->next;
    }
    if(p==NULL){printf("没有查到要修改的学生的id\n");return head;}
    else
    {
        printf("学号：");
        scanf("%d",&p->id);
        printf("姓名：");
        getchar();
        gets(p->name);
        printf("班级:");
        gets(p->classroom);
        printf("成绩:");
        scanf("%f",&p->score);
    }
    return head;
}
void writeFile(student *head)
{
    FILE *outf;
    student *p=head;
    if((outf = fopen("data.txt","wb")) == NULL) {
        printf("不能打开数据文件。\n");
        exit(1);
    }
    while(p) {
        fwrite(p,sizeof(student),1,outf);
        p = p->next;
    }
    fclose(outf);
}

student *readFile(student *head)
{
    int n=0;
    student temp;
    FILE *inf;
    student *p=NULL,*q;
    if((inf = fopen("data.txt","rb")) == NULL) {
        printf("不能打开数据文件。\n");
        exit(1);
    }
    while(fread(&temp,sizeof(student),1,inf)!=0)
    {
        p=(student *)malloc(sizeof(student));
        p->id=temp.id;
        p->score=temp.score;
        strcpy(p->name,temp.name);
        strcpy(p->classroom,temp.classroom);
        n++;
        if(n==1){head=p;q=p;}
        else
        {
            q->next=p;
            q=q->next;
        }

    }
    q->next=NULL;
    fclose(inf);
    return head;
}

int main()
{
    int a;
    student *head,*p;
    //head=init();
    head=readFile(head);

    do
    {
       printf("欢迎使用学生管理系统\n");
       printf("1:增加学生\n2：删除学生\n3：修改信息\n4:显示所有信息\n5：退出系统\n");
       printf("请输入您想进行的操作是：\n");
       scanf("%d",&a);
       switch(a)
       {
           case 1:head=addStudent(head);break;
           case 2:head=deleteStudent(head);break;
           case 3:head=correctStudent(head);break;
           case 4:display(head);break;

       }

   }while(a != 5);
   writeFile(head);

}
