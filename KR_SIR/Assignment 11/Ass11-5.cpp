#include <iostream>

using namespace std;

struct stack{
    int top;
    int size;
    int elements[50];
};

void push(stack &s, int x){
    if(s.top == s.size-1)
        cout<< "Stack is full";
    else
        s.elements[++s.top] = x;
}

int pop(stack &s){
    if(s.top == -1){
        cout<< "Stack is empty";
        return -1;
    }
    else
        return s.elements[s.top--];
}

int peek(stack &s){
    if(s.top == -1){
        cout<< "Stack is empty";
        return -1;
    }
    else
        return s.elements[s.top];
}

void reverse_a_stack(stack &s, int *A, int i,int flag){
    if(s.top > -1 && flag == 1){
        A[i] = pop(s);
        //cout<< "----- 1 -----------------"<<A[i]<<endl;
        reverse_a_stack(s,A,i+1,1);
    }

    else if(s.top == -1 && flag == 1)
        reverse_a_stack(s,A,0,2);

    else if(flag == 2 && s.top < s.size-1){
        push(s,A[i]);
        //cout<< peek(s)<< "----------------- 2 -----------"<<endl;
        reverse_a_stack(s,A,i+1,2);
    }
    return;    
}

int main(){
    stack s;
    int n,*A;
    cin>>n;
    A = new int [n];
    s.top = -1;
    s.size = n;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        push(s,x);
    }

    reverse_a_stack(s,A,0,1);
    
    for(int i=0;i<n;i++)
        cout<< pop(s)<< " ";
    cout<<endl;
    return 0;
}