//yym
#include<iostream>

using  namespace std;

int main()
{

//�������������

    int m,n,count=1,i,j;
    cout<<"������������";
    cin>>m;
    cout<<"������������";
    cin>>n;

//���پ���ռ䣬ʹ��new����̬����

    int **table;
    table = new int* [n];
    for(i=0;i<n;i++)
    {
        table[i] = new int[n];
    }
    cout<<endl;

//��ʼ������

    for(i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            table[i][j]=count;  //��ʼ������
            count++;
            cout.width(3);  //�������ռ�
            cout<<table[i][j];
        }
        cout<<endl;
    }
    cout<<endl;

//���б45�ȽǾ���

    cout<<"б45�ȽǴ�ӡ����"<<endl;
    for(int i=0,j=m-1;j>=0;j--)   //�ӵ�һ�е����һ��ѭ������һ�У�����Խ���
    {
        cout<<table[i][j]<<" "; //����Խ��ߵĿ�ʼ����
        for(int k=i,l=j;k+1<=n-1&&l+1<=m-1;)    //���½�ûԽ�磬�����������
            cout<<table[++k][++l]<<" ";
        cout<<endl;
    }
    for(i=1,j=0;i<=n-1;i++)   //�ӵ�һ�еĵڶ���ѭ�������һ�У�����Խ���
    {
        cout<<table[i][j]<<" "; //����Խ��ߵĿ�ʼ����
        for(int k=i,l=j;k+1<=n-1&&l+1<=m-1;)    //���½�ûԽ�磬�����������
            cout<<table[++k][++l]<<" ";
        cout<<endl;
    }

//�ͷ��ڴ�

    for(i=0;i<n;i++)
    {
        delete[] table[i];
    }
    delete[] table;
    return 0;
}
