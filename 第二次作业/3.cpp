#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<string>
#include<fstream>

using namespace std;

struct Book
{
	string Name;                 //����
	string Author;               //����
	string Publisher;            //������
	string Date;                 //����
	string ISBN;                 //���
	Book *next;
};

/******************��ʼ������********************/

void InitList(Book *&L)
{
	L = new Book;
	L->next=NULL;
}

/*****************���������<<******************/
ostream &operator<<(ostream &output, Book *&b)
{
	output << b->Name << '\t' << b->Author << '\t' << b->Publisher << '\t' << b->Date << '\t' << b->ISBN << '\t';
	return output;
}

/*****************���������>>******************/

istream &operator >> (istream &input, Book *&b)
{
	input >> b->Name >> b->Author >> b->Publisher >> b->Date >> b->ISBN;
	return input;
}

/*****************�洢ͼ����Ϣ******************/

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

/*****************��ȡͼ����Ϣ******************/

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

/*****************�ظ������Ϣ���ж�******************/
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
/*****************����ͼ����Ϣ******************/

void AddBook()
{
	while (1)
	{
		Book *L, *s;
		InitList(L);
		ReadData(L);
		s = new Book;
		cout << "����ͼ����Ϣ����:" << endl;
			cout << "����" << endl;
			cin >> s->Name;
			cout << "����" << endl;
			cin >> s->Author;
			cout << "������" << endl;
			cin >> s->Publisher;
			cout << "����" << endl;
			cin >> s->Date;
			cout << "���" << endl;
			cin >> s->ISBN;
			if (ISBN(&(s->ISBN)))
			{
				cout << "����ظ�������������:" << endl;
				continue;
			}


		cout << "\n�Ƿ�Ҫ�洢��ͼ����Ϣ(Y/N)" << endl;
		cin.ignore(INT_MAX, '\n');

		char c = getchar();
		if (c == 'Y'||c == 'y')
		{
			s->next = L->next;
			L->next = s;
			SaveData(L);
		}
		else
			cout << "\n�������κ�ͼ����Ϣ" << endl;
		cout << "�Ƿ���Ҫ�ٴ�����ͼ����Ϣ(Y/N)\n" << endl;
		cin.ignore(INT_MAX, '\n');

		c = getchar();
		if (c == 'N'||c == 'n')
			break;
	}
}

/*****************�޸�ͼ����Ϣ******************/

void UpdateBook()
{
	system("cls");
	string str;
	Book *L, *s;
	InitList(L);
	ReadData(L);
	s = L->next;
	cout << "������Ҫ���ĵ�ͼ����Ϣ�����:" << endl;
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
				cout << "�Ƿ�����޸�(Y/N)" << endl;
				cin.ignore(INT_MAX, '\n');
				char c = getchar();
				if (c == 'Y'||c == 'y')
					break;
				cout << endl;
				cout << "/****************�޸�ͼ�����************/" << endl;
				cout << "/*****************************************/" << endl;
				cout << "/**************(1)�����޸�*****************/" << endl;
				cout << "/**************(2)�����޸�*****************/" << endl;
				cout << "/**************(3)�������޸�***************/" << endl;
				cout << "/**************(4)�����޸�*****************/" << endl;
				cout << "/**************(0)����*********************/" << endl;
				cout << "/*****************************************/" << endl;
				cout << "/********ͨ�����ּ���ѡȡ��Ӧ�ķ���*******/" << endl;
				switch (_getch())
				{
				    case '1':
						cout << "������Ҫ�޸ĵ�����:" << endl;
						cin >> str;
						s->Name = str;
						SaveData(L);
						break;
					case '2':
						cout << "������Ҫ�޸ĵ�����:" << endl;
						cin >> str;
						s->Author = str;
						SaveData(L);
						break;
					case '3':
						cout << "������Ҫ�޸ĵĳ�����:" << endl;
						cin >> str;
						s->Publisher = str;
						SaveData(L);
						break;
					case '4':
						cout << "������Ҫ�޸ĵ�����:" << endl;
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
		cout << "���޴���" << endl;
	system("pause");
}
/*****************ɾ��ͼ����Ϣ******************/

void DeleteBook()
{
	system("cls");
	Book *L, *p;
	InitList(L);
	ReadData(L);
	Book *r;
	r = L;
	p = L->next;
	string ISBN;              //���������ɾ��ͼ����Ϣ��
	cout << "������Ҫɾ��ͼ������:" << endl;
	cin >> ISBN;
	bool flag = false;
	while (p != NULL)
	{
		if (p->ISBN == ISBN)
		{
			r->next = p->next;

			cout << "ɾ����ͼ����Ϣ����:" << endl;
			cout << p << endl;
			SaveData(L);
			flag = true;
		}
		r = p;
		p = p->next;
	}
	if (!flag)
		cout << "\nû�и�ͼ����Ϣ" << endl;
	system("pause");
}

/*****************����ͼ����Ϣͨ������******************/

void SearchbyName()
{
	system("cls");
	Book *L, *s;
	InitList(L);
	ReadData(L);
	string  str;
	cout << "������Ҫ���ҵ�����" << endl;
	cin >> str;
	s = L->next;
	bool flag = false;
	while (s != NULL)
	{
		if (s->Name == str)
		{
			cout << "Ҫ���ҵ�ͼ����Ϣ����:" << endl;
			flag = true;
			cout << s << endl;
		}
		s = s->next;
	}
	if (!flag)
		cout << "���޴���" << endl;
}


/*****************����ͼ����Ϣͨ������******************/

void SearchbISBN()
{
	system("cls");
	Book *L, *s;
	InitList(L);
	ReadData(L);
	string  str;
	cout << "������Ҫ���ҵ����" << endl;
	cin >> str;
	s = L->next;
	bool flag = false;
	while (s != NULL)
	{
		if (s->ISBN == str)
		{
			cout << "Ҫ���ҵ�ͼ����Ϣ����:" << endl;
			flag = true;
			cout << s << endl;
		}
		s = s->next;
	}
	if (!flag)
		cout << "���޴���" << endl;
}


/*****************����ͼ����Ϣͨ������******************/

void SearchbyAuthor()
{
	system("cls");
	Book *L, *s;
	InitList(L);
	ReadData(L);
	string  str;
	cout << "������Ҫ���ҵ�����" << endl;
	cin >> str;
	s = L->next;
	bool flag = false;
	while (s != NULL)
	{
		if (s->Author == str)
		{
			cout << "Ҫ���ҵ�ͼ����Ϣ����:" << endl;
			flag = true;
			cout << s << endl;
		}
		s = s->next;
	}
	if (!flag)
		cout << "���޴���" << endl;
}
void SearchbyPublisher()
{
	system("cls");
	Book *L, *s;
	InitList(L);
	ReadData(L);
	string  str;
	cout << "������Ҫ���ҵĳ�����" << endl;
	cin >> str;
	s = L->next;
	bool flag = false;
	while (s != NULL)
	{
		if (s->Publisher == str)
		{
			cout << "Ҫ���ҵ�ͼ����Ϣ����:" << endl;
			flag = true;
			cout << s << endl;
		}
		s = s->next;
	}
	if (!flag)
		cout << "���޴���" << endl;
}


/*****************����ͼ����Ϣͨ������******************/

void SearchbyDate()
{
	system("cls");
	Book *L, *s;
	InitList(L);
	ReadData(L);
	string  str;
	cout << "������Ҫ���ҵ�����" << endl;
	cin >> str;
	s = L->next;
	bool flag = false;
	while (s != NULL)
	{
		if (s->Date == str)
		{
			cout << "Ҫ���ҵ�ͼ����Ϣ����:" << endl;
			flag = true;
			cout << s << endl;
		}
		s = s->next;
	}
	if (!flag)
		cout << "���޴���" << endl;
}

/*****************����������******************/

void Search()
{
	system("cls");
	while (1)
	{
		cout << endl;
		cout << "/****************����ͼ��������************/"<<endl;
		cout << "/*****************************************/" << endl;
		cout << "/**************(1)��������*****************/" << endl;
		cout << "/**************(2)���߲���*****************/" << endl;
		cout << "/**************(3)�����̲���***************/" << endl;
		cout << "/**************(4)���ڲ���*****************/" << endl;
		cout << "/**************(5)��Ų���*****************/" << endl;
		cout << "/**************(0)����*********************/" << endl;
		cout << "/*****************************************/" << endl;
		cout << "/********ͨ�����ּ���ѡȡ��Ӧ�ķ���*******/" << endl;
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
		cout << "/****************ͼ�����������************/" << endl;
		cout << "/*****************************************/" << endl;
		cout << "/**************(1)����ͼ��*****************/" << endl;
		cout << "/**************(2)����ͼ��*****************/" << endl;
		cout << "/**************(3)ɾ��ͼ��****************/" << endl;
		cout << "/**************(4)�޸�ͼ��****************/" << endl;
		cout << "/**************(0)����********************/" << endl;
		cout << "/*****************************************/" << endl;
		cout << "/********ͨ�����ּ���ѡȡ��Ӧ�ķ���*******/" << endl;
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
