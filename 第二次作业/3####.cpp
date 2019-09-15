#include<stdio.h>
#include<stdlib.h>
#define M 20


//����ѧ���Ľṹ��
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
    printf("����ѧ����Ϣ�ĸ���\n");
    scanf("%d",&a);

    head=NULL;
    for(i=0;i<a;i++)
    {
        p=(student *)malloc(sizeof(student));
        printf("�����%d��ѧ������Ϣ\n",i+1);
        printf("ѧ��:");
        scanf("%d",&p->id);
        printf("������");
        getchar();
        gets(p->name);
        printf("�༶:");
        gets(p->classroom);
        printf("�ɼ�:");
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
        printf("ѧ����ѧ��Ϊ%d������Ϊ%s���༶Ϊ%s������Ϊ%f\n",p->id,p->name,p->classroom,p->score);
        p=p->next;
    }
}

student *addStudent(student *head)
{
    student *p,*q;
    q=head;
    while(q->next) q=q->next;
     p=(student *)malloc(sizeof(student));
        printf("ѧ�ţ�");
        scanf("%d",&p->id);
        printf("������");
        getchar();
        gets(p->name);
        printf("�༶:");
        gets(p->classroom);
        printf("�ɼ�:");
        scanf("%f",&p->score);
        p->next=NULL;
        q->next=p;
        return head;
}

student *deleteStudent(student *head)
{
    int a;
    student *pre=NULL,*p;
    printf("������Ҫɾ����id");
    scanf("%d",&a);
    if(!head) {printf("ϵͳ���Ѿ�û�����ݿ���ɾ��\n");return head;}
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
    printf("������Ҫ�޸ĵ�ѧ����id");
    scanf("%d",&a);
    if(!head) {printf("ϵͳ���Ѿ�û�����ݿ����޸�\n");return head;}
    p=head;
    while(p&&p->id!=a)
    {
        p=p->next;
    }
    if(p==NULL){printf("û�в鵽Ҫ�޸ĵ�ѧ����id\n");return head;}
    else
    {
        printf("ѧ�ţ�");
        scanf("%d",&p->id);
        printf("������");
        getchar();
        gets(p->name);
        printf("�༶:");
        gets(p->classroom);
        printf("�ɼ�:");
        scanf("%f",&p->score);
    }
    return head;
}
void writeFile(student *head)
{
    FILE *outf;
    student *p=head;
    if((outf = fopen("data.txt","wb")) == NULL) {
        printf("���ܴ������ļ���\n");
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
        printf("���ܴ������ļ���\n");
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
       printf("��ӭʹ��ѧ������ϵͳ\n");
       printf("1:����ѧ��\n2��ɾ��ѧ��\n3���޸���Ϣ\n4:��ʾ������Ϣ\n5���˳�ϵͳ\n");
       printf("������������еĲ����ǣ�\n");
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
