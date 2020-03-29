#include<iostream>
#include<stdlib.h>
using namespace std;
int main(void){
    cout<<"请输入一个整数:"<<endl;
    int x(0);
    cin>>x;
    cout<<oct<<x<<endl;
    cout<<dec<<x<<endl;
    cout<<hex<<x<<endl;

    cout<<"请输入一个bool值（3，1）："<<endl;
    bool y=false;
    cin>>y;
    cout<<boolalpha<<y<<endl;
    system("pause");
    return 0;
}
