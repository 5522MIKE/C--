#include<iostream>
#include<stdlib.h>
#include<string>
#include<stdio.h>

using namespace std;


struct Book
{
    string ID;                 //���
	string BookName;                 //����
	string Author;               //����
	string Publisher;            //������

	struct Book *next;
}book;

init()
{
    book *p,*q,*head;
    int i,a;
    int n=0;
    cout<<"�����鱾��Ϣ�ĸ���"<<endl;
    cin>>a;

    head=NULL;
    for(i=0;i<a;i++)
    {
        p=(book *)malloc(sizeof(book));
        cout<<"�����%d���鱾��Ϣ"<<i+1<<endl;
        cout<<"ID:";
        cin>>&p->ID;
        cout<<"������";
        cin>>p->BookName;
        cout<<"���ߣ�";
        cin>>p->Author;
        cout<<"�����磺";
        cin>>p->Publisher;
        n=n+1;
        if(n==1)
        {
            head=p;
            q=p;
            q->next=NULL;

        }
        else
        {
            q->next=p;
            q=p;
            p->next=NULL;
        }
    }
}
void Search()
{
    system("cls");
	Book *p;
	string  str;
	cout << "������Ҫ���ҵ�����" << endl;
	cin >> str;
	bool flag = false;
	while (p != NULL)
	{
		if (p->Name == str)
		{
			cout << "Ҫ���ҵ�ͼ����Ϣ����:" << endl;
			flag = true;
			cout<<"ID:"<<p->ID<<" "<<cout<<"������"<<p->BookName<<" "<<cout<<"���ߣ�"<<p->Author<<" "<<cout<<"�����磺"<<p->Publisher<<endl;
		}
		p = p->next;
	}
	if (!flag)
		cout << "���޴���" << endl;
}

int main()
{
    init();
    display()
}
