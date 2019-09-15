#include<iostream>

using namespace std;

class Array{
public:
    set_value();
    show_value();
    get_max();
    get_min();
    show_max();
    show_min();
    show_in_order();
private:
    int a[10];
    int max;
    int min;
};

Array::set_value(){
    cout<<"请输入十个数："<<endl;
    for(int i=0;i<10;i++){
        cout<<i+1<<") ";
        cin>>this->a[i];
    }
}

Array::show_value(){
    cout<<"SHOW THE ARRAY:";
    for(int i=0;i<10;i++)
        cout<<this->a[i]<<" ";
    cout<<endl;
}

Array::get_max(){
    int temp = this->a[0];
    for(int i=1;i<10;i++){
        if(temp<this->a[i])
            temp = this->a[i];
    }
    max = temp;
}

Array::get_min(){
    int temp = this->a[0];
    for(int i=1;i<10;i++){
        if(temp>this->a[i])
            temp = this->a[i];
    }
    min = temp;
}

Array::show_max(){
    cout<<"MAX:";
    cout<<max<<endl;
}

Array::show_min(){
    cout<<"MIN:";
    cout<<min<<endl;
}

Array::show_in_order(){
    cout<<"IN_ORDER:";
    int i, j;
    int temp;
    int arr[10];
    for(i=0;i<10;i++)
        arr[i] = a[i];
    for (i = 0; i < 9; i++)
        for (j = 0; j < 9-i; j++)
        {
            cout<<arr[j+1]<<endl;
            if (arr[j] > arr[j + 1])
        {
            temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
        }
        }
    for(i=0;i<10;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main()
{
    Array a;
    a.set_value();
    a.show_value();
    a.get_max();
    a.get_min();
    a.show_max();
    a.show_min();
    a.show_in_order();
    return 0;
}
