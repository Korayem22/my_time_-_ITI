#include <iostream>
using namespace std;
class Stack{
private:
    int tos;
    int stackSize;
    int *st;
    static int counter;
public:
    Stack(){
        tos = 0;
        stackSize = 10;
        st = new int[stackSize];
        counter++;
        cout<<"stack counter = "<<counter<<endl;
    }
    Stack(int n){
        tos = 0;
        stackSize = n;
        st = new int[stackSize];
        counter++;
        cout<<"stack counter = "<<counter<<endl;
    }
    Stack( Stack &z);
    ~Stack(){
        counter--;
        cout<<"stack counter = "<<counter<<endl;
        delete[] st;
    }
    friend void viewContent(Stack x);
    void push(int);
    int pop();
    void print();
    Stack& operator = (const Stack &s);
};
int Stack::counter=0;
Stack::Stack(Stack &z){
    tos=z.tos;
    stackSize=z.stackSize;
    st = new int[stackSize];
    for(int i=0;i<tos;i++)
        st[i]=z.st[i];
    counter++;
    cout<<"stack counter (in copy) = "<<counter<<endl;
}
void Stack::print(){
    for(int i = 0;i<tos;i++){
        cout<<st[i]<<endl;
    }
}
void Stack::push(int n){
    if (tos==stackSize){
        cout<<"Stack is full"<<endl;
    }
    else{
        st[tos]=n;
        tos++;
        //cout<<"tos ++"<<endl;
    }
}
int Stack::pop(){
    int ret;
    if (tos==0){
        cout<<"Stack is empty"<<endl;
        ret=-1;
    }
    else{
        tos--;
        ret=st[tos];
    }
    return ret;
}
void viewContent(Stack x){
    int t=x.tos;
    while(t!=0)
        cout<<x.st[--t]<<endl;
}
Stack& Stack::operator=(const Stack &s){
    delete[]this->st;
    this->tos=s.tos;
    this->stackSize=s.stackSize;
    this->st = new int[stackSize];
    for(int i=0;i<tos;i++){
        this->st[i]=s.st[i];
    }
}
int main(){
    Stack s1(5);
    s1.push(5);
    s1.push(14);
    s1.push(20);
    s1.push(22);
    s1.push(55);
    Stack s2(7);
    s2.push(9);
    cout<<"************************"<<endl;
    s2=s1;
    s2.print();
    return 0;
}
