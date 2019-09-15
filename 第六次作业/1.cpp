#include<iostream>

using namespace std;

class people{
public:
    setbase(string name,string sex);
    string name,sex;
};

class student:public people{
public:
    setid(string id);
    string id;
};

class teacher:public people{
public:
    settid(string tid);
    string tid;
};

class assiss_teacher:public student,teacher{
public:
    set(string n,string s){
        settid(n);
    }
    show();
};

people::setbase(string name,string sex){
    this->name = name;
    this->sex = sex;
}

student::setid(string id){
    this->id = id;
}

teacher::settid(string tid){
    this->tid = tid;
}
/*
assiss_teacher::show(){
    cout<<"name:"<<name<<" "<<"sex:"<<sex<<endl;
}
*/
int main()
{
    assiss_teacher yym;
    /*
    yym.setbase("yym","ÄÐ");
    yym.show();
    */
    return 0;
}
