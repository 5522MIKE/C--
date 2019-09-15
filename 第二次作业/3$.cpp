#include<iostream>
#include<stdlib.h>
#include<string>
#include<stdio.h>

using namespace std;


struct Book
{
    string ID;                 //书号
	string BookName;                 //书名
	string Author;               //作者
	string Publisher;            //出版商

	struct Book *next;
}book;

init()
{
    book *p,*q,*head;
    int i,a;
    int n=0;
    cout<<"输入书本信息的个数"<<endl;
    cin>>a;

    head=NULL;
    for(i=0;i<a;i++)
    {
        p=(book *)malloc(sizeof(book));
        cout<<"输入第%d个书本信息"<<i+1<<endl;
        cout<<"ID:";
        cin>>&p->ID;
        cout<<"书名：";
        cin>>p->BookName;
        cout<<"作者：";
        cin>>p->Author;
        cout<<"出版社：";
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
	cout << "请输入要查找的书名" << endl;
	cin >> str;
	bool flag = false;
	while (p != NULL)
	{
		if (p->Name == str)
		{
			cout << "要查找的图书信息如下:" << endl;
			flag = true;
			cout<<"ID:"<<p->ID<<" "<<cout<<"书名："<<p->BookName<<" "<<cout<<"作者："<<p->Author<<" "<<cout<<"出版社："<<p->Publisher<<endl;
		}
		p = p->next;
	}
	if (!flag)
		cout << "查无此书" << endl;
}

int main()
{
    init();
    display()
}
