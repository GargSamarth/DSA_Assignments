#include <iostream>

using namespace std;

struct stack{
    int size;
    int top;
    int A[50];
};

void push(stack &s, int x){
    if(s.top == s.size-1)
        cout<< "Stack is full"<<endl;
    else
        s.A[++s.top] = x;
}

int pop(stack &s){
    if( s.top == -1){
        cout<< "Stack is empty" << endl;
        return -1;
    }
    else
        return s.A[s.top--];
}

int peek(stack &s){
    if( s.top == -1){
        cout<< "Stack is empty" << endl;
        return -1;
    }
    else
        return s.A[s.top];
}

int main(){
    stack A[2];

    int n;
    cout<< "Enter the number of elements: ";
    cin>>n;

    for(int i=0;i<2;i++){
        cout<< "Stack no " << i+1 << endl;
        for(int j=0;j<n;j++){
            int temp;
            cin>>temp;
            push(A[i],temp);
        }

        for(int j=0;j<n;j++){
            cout<< pop(A[i]);
        }
    }
    return 0;
}