#include<iostream>

using namespace std;


class mother
{

public:
    mother(){cout<<"mother: default constructor!"<<endl;}
    mother(int a) {cout<<"mother: constructor with int "<<a<<endl;}

};

class daughter : public mother
{

public:
    daughter():mother(1)
    {
        cout<<"daughter: default contructor"<<endl;
    }

};

int main()
{

daughter lily;

}
//OUTPUT:
//peter@cow:~/gitbro/wiki$ ./a.out 
//mother: constructor with int 1
//daughter: default contructor
