#include <iostream>

using namespace std;

class stack{
    private:
    int top, size, *A;
    public:
    stack(int size){
        top = -1;
        this->size = size;
        A = new int [this->size];
    }
    void push(int x);
    int pop();
    int peek();
    int get_size(){return size;}
};

void stack::push(int x){
    if(top == size-1)
        cout<< "Stack is full"<<endl;
    else
        A[++top] = x;
    //(top == size-1 ? (cout<< "Stack is full"<<endl) : (A[++top]=x)); -- not working, giving error
}

int stack::pop(){
    if( top == -1){
        cout<< "Stack is empty" << endl;
        return -1;
    }
    else
        return A[top--];
}

int stack::peek(){
    if( top == -1){
        cout<< "Stack is empty" << endl;
        return -1;
    }
    else
        return A[top];
}

int main(){
    int n;
    cout<< "enter the size of stack: ";
    cin>>n;
    stack stk(n);

    cout<< endl <<  "Enter the number: ";
    int num;
    cin>>num;

    while(num>0){
        stk.push(num%10);
        num=num/10;
    }
    int size = stk.get_size();
    while(size--)
        cout<< stk.pop() << " ";
    cout<< endl;


    return 0;
}