//yym
#include<iostream>

using  namespace std;

int main()
{

//获得行数、列数

    int m,n,count=1,i,j;
    cout<<"请输入行数：";
    cin>>m;
    cout<<"请输入列数：";
    cin>>n;

//开辟矩阵空间，使用new来动态开辟

    int **table;
    table = new int* [n];
    for(i=0;i<n;i++)
    {
        table[i] = new int[n];
    }
    cout<<endl;

//初始化矩阵

    for(i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            table[i][j]=count;  //初始化矩阵
            count++;
            cout.width(3);  //获得输出空间
            cout<<table[i][j];
        }
        cout<<endl;
    }
    cout<<endl;

//输出斜45度角矩阵

    cout<<"斜45度角打印矩阵："<<endl;
    for(int i=0,j=m-1;j>=0;j--)   //从第一行的最后一列循环到第一列，输出对角线
    {
        cout<<table[i][j]<<" "; //输出对角线的开始数字
        for(int k=i,l=j;k+1<=n-1&&l+1<=m-1;)    //右下角没越界，就输出这数字
            cout<<table[++k][++l]<<" ";
        cout<<endl;
    }
    for(i=1,j=0;i<=n-1;i++)   //从第一列的第二行循环到最后一行，输出对角线
    {
        cout<<table[i][j]<<" "; //输出对角线的开始数字
        for(int k=i,l=j;k+1<=n-1&&l+1<=m-1;)    //右下角没越界，就输出这数字
            cout<<table[++k][++l]<<" ";
        cout<<endl;
    }

//释放内存

    for(i=0;i<n;i++)
    {
        delete[] table[i];
    }
    delete[] table;
    return 0;
}
