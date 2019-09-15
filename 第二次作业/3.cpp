#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<string>
#include<fstream>

using namespace std;

struct Book
{
	string Name;                 //书名
	string Author;               //作者
	string Publisher;            //出版商
	string Date;                 //日期
	string ISBN;                 //书号
	Book *next;
};

/******************初始化链表********************/

void InitList(Book *&L)
{
	L = new Book;
	L->next=NULL;
}

/*****************重载运算符<<******************/
ostream &operator<<(ostream &output, Book *&b)
{
	output << b->Name << '\t' << b->Author << '\t' << b->Publisher << '\t' << b->Date << '\t' << b->ISBN << '\t';
	return output;
}

/*****************重载运算符>>******************/

istream &operator >> (istream &input, Book *&b)
{
	input >> b->Name >> b->Author >> b->Publisher >> b->Date >> b->ISBN;
	return input;
}

/*****************存储图书信息******************/

void  SaveData(Book *&L)
{
	Book *p = L->next;
	ofstream outfile;
	outfile.open("Book.txt", ios::out);
	while(p != NULL)
	{
		outfile << p<<endl;
		p = p->next;
	}
	outfile.close();
}

/*****************读取图书信息******************/

void ReadData(Book *&L)
{
	Book *p, *s;
	ifstream infile;
	p = L;
	infile.open("Book.txt", ios::in);
	while (infile.peek() != EOF)
	{
		s = new Book;
		infile >> s;
		p->next = s;
		p = s;
	}
	p->next = NULL;
}

/*****************重复书号信息的判定******************/
int ISBN(string *str)
{
	Book *L, *s;
	InitList(L);
	ReadData(L);
	s = L->next;
	while (s != NULL)
	{
		if (s->ISBN == (*str))
		{
			return 1;
		}
		s = s->next;
	}
	return 0;
}
/*****************增加图书信息******************/

void AddBook()
{
	while (1)
	{
		Book *L, *s;
		InitList(L);
		ReadData(L);
		s = new Book;
		cout << "增加图书信息如下:" << endl;
			cout << "书名" << endl;
			cin >> s->Name;
			cout << "作者" << endl;
			cin >> s->Author;
			cout << "出版商" << endl;
			cin >> s->Publisher;
			cout << "日期" << endl;
			cin >> s->Date;
			cout << "书号" << endl;
			cin >> s->ISBN;
			if (ISBN(&(s->ISBN)))
			{
				cout << "书号重复，请重新输入:" << endl;
				continue;
			}


		cout << "\n是否要存储该图书信息(Y/N)" << endl;
		cin.ignore(INT_MAX, '\n');

		char c = getchar();
		if (c == 'Y'||c == 'y')
		{
			s->next = L->next;
			L->next = s;
			SaveData(L);
		}
		else
			cout << "\n不保存任何图书信息" << endl;
		cout << "是否需要再次增加图书信息(Y/N)\n" << endl;
		cin.ignore(INT_MAX, '\n');

		c = getchar();
		if (c == 'N'||c == 'n')
			break;
	}
}

/*****************修改图书信息******************/

void UpdateBook()
{
	system("cls");
	string str;
	Book *L, *s;
	InitList(L);
	ReadData(L);
	s = L->next;
	cout << "请输入要更改的图书信息的书号:" << endl;
	string ISBN;
	cin >> ISBN;
	bool flag;
	flag = false;
	while (s != NULL)
	{
		if (s->ISBN == ISBN)
		{
			flag = true;
			cout << s << endl;
			while (1)
			{
				cout << "是否结束修改(Y/N)" << endl;
				cin.ignore(INT_MAX, '\n');
				char c = getchar();
				if (c == 'Y'||c == 'y')
					break;
				cout << endl;
				cout << "/****************修改图书界面************/" << endl;
				cout << "/*****************************************/" << endl;
				cout << "/**************(1)书名修改*****************/" << endl;
				cout << "/**************(2)作者修改*****************/" << endl;
				cout << "/**************(3)出版商修改***************/" << endl;
				cout << "/**************(4)日期修改*****************/" << endl;
				cout << "/**************(0)返回*********************/" << endl;
				cout << "/*****************************************/" << endl;
				cout << "/********通过数字键来选取相应的服务*******/" << endl;
				switch (_getch())
				{
				    case '1':
						cout << "请输入要修改的书名:" << endl;
						cin >> str;
						s->Name = str;
						SaveData(L);
						break;
					case '2':
						cout << "请输入要修改的作者:" << endl;
						cin >> str;
						s->Author = str;
						SaveData(L);
						break;
					case '3':
						cout << "请输入要修改的出版商:" << endl;
						cin >> str;
						s->Publisher = str;
						SaveData(L);
						break;
					case '4':
						cout << "请输入要修改的日期:" << endl;
						cin >> str;
						s->Date = str;
						SaveData(L);
						break;
					case '0':
						return;
					default:
						break;
				}
			}
		}
		s = s->next;
	}
	if (!flag)
		cout << "查无此书" << endl;
	system("pause");
}
/*****************删除图书信息******************/

void DeleteBook()
{
	system("cls");
	Book *L, *p;
	InitList(L);
	ReadData(L);
	Book *r;
	r = L;
	p = L->next;
	string ISBN;              //根据书号来删除图书信息；
	cout << "请输入要删除图书的书号:" << endl;
	cin >> ISBN;
	bool flag = false;
	while (p != NULL)
	{
		if (p->ISBN == ISBN)
		{
			r->next = p->next;

			cout << "删除的图书信息如下:" << endl;
			cout << p << endl;
			SaveData(L);
			flag = true;
		}
		r = p;
		p = p->next;
	}
	if (!flag)
		cout << "\n没有该图书信息" << endl;
	system("pause");
}

/*****************查找图书信息通过书名******************/

void SearchbyName()
{
	system("cls");
	Book *L, *s;
	InitList(L);
	ReadData(L);
	string  str;
	cout << "请输入要查找的书名" << endl;
	cin >> str;
	s = L->next;
	bool flag = false;
	while (s != NULL)
	{
		if (s->Name == str)
		{
			cout << "要查找的图书信息如下:" << endl;
			flag = true;
			cout << s << endl;
		}
		s = s->next;
	}
	if (!flag)
		cout << "查无此书" << endl;
}


/*****************查找图书信息通过书名******************/

void SearchbISBN()
{
	system("cls");
	Book *L, *s;
	InitList(L);
	ReadData(L);
	string  str;
	cout << "请输入要查找的书号" << endl;
	cin >> str;
	s = L->next;
	bool flag = false;
	while (s != NULL)
	{
		if (s->ISBN == str)
		{
			cout << "要查找的图书信息如下:" << endl;
			flag = true;
			cout << s << endl;
		}
		s = s->next;
	}
	if (!flag)
		cout << "查无此书" << endl;
}


/*****************查找图书信息通过作者******************/

void SearchbyAuthor()
{
	system("cls");
	Book *L, *s;
	InitList(L);
	ReadData(L);
	string  str;
	cout << "请输入要查找的作者" << endl;
	cin >> str;
	s = L->next;
	bool flag = false;
	while (s != NULL)
	{
		if (s->Author == str)
		{
			cout << "要查找的图书信息如下:" << endl;
			flag = true;
			cout << s << endl;
		}
		s = s->next;
	}
	if (!flag)
		cout << "查无此书" << endl;
}
void SearchbyPublisher()
{
	system("cls");
	Book *L, *s;
	InitList(L);
	ReadData(L);
	string  str;
	cout << "请输入要查找的出版商" << endl;
	cin >> str;
	s = L->next;
	bool flag = false;
	while (s != NULL)
	{
		if (s->Publisher == str)
		{
			cout << "要查找的图书信息如下:" << endl;
			flag = true;
			cout << s << endl;
		}
		s = s->next;
	}
	if (!flag)
		cout << "查无此书" << endl;
}


/*****************查找图书信息通过日期******************/

void SearchbyDate()
{
	system("cls");
	Book *L, *s;
	InitList(L);
	ReadData(L);
	string  str;
	cout << "请输入要查找的日期" << endl;
	cin >> str;
	s = L->next;
	bool flag = false;
	while (s != NULL)
	{
		if (s->Date == str)
		{
			cout << "要查找的图书信息如下:" << endl;
			flag = true;
			cout << s << endl;
		}
		s = s->next;
	}
	if (!flag)
		cout << "查无此书" << endl;
}

/*****************查找主界面******************/

void Search()
{
	system("cls");
	while (1)
	{
		cout << endl;
		cout << "/****************查找图书主界面************/"<<endl;
		cout << "/*****************************************/" << endl;
		cout << "/**************(1)书名查找*****************/" << endl;
		cout << "/**************(2)作者查找*****************/" << endl;
		cout << "/**************(3)出版商查找***************/" << endl;
		cout << "/**************(4)日期查找*****************/" << endl;
		cout << "/**************(5)书号查找*****************/" << endl;
		cout << "/**************(0)返回*********************/" << endl;
		cout << "/*****************************************/" << endl;
		cout << "/********通过数字键来选取相应的服务*******/" << endl;
		switch (_getch())
		{
		  case '1':
			  SearchbyName();
			  break;
		  case '2':
			  SearchbyAuthor();
			  break;
		  case'3':
			  SearchbyPublisher();
			  break;
		  case'4':
			  SearchbyDate();
			  break;
		  case'5':
			  SearchbISBN();
			 break;
		  case'0':
			  return;
		  default:
			  break;
		}
	}
}

void menu()
{
	system("cls");
	while (1)
	{
		cout << endl;
		cout << "/****************图书管理主界面************/" << endl;
		cout << "/*****************************************/" << endl;
		cout << "/**************(1)新增图书*****************/" << endl;
		cout << "/**************(2)查找图书*****************/" << endl;
		cout << "/**************(3)删除图书****************/" << endl;
		cout << "/**************(4)修改图书****************/" << endl;
		cout << "/**************(0)返回********************/" << endl;
		cout << "/*****************************************/" << endl;
		cout << "/********通过数字键来选取相应的服务*******/" << endl;
		switch (_getch())
		{
		case '1':
			AddBook();
			break;
		case '2':
			Search();
			break;
		case'3':
			DeleteBook();
			break;
		case '4':
			UpdateBook();
			break;
		case'0':
			cout<<"THANKS"<<endl;
			exit(1);
		default:
			break;
		}
	}
}
int main()
{
	menu();
}
