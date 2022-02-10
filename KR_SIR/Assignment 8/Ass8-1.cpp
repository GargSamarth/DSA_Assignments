#include <iostream>

using namespace std;

union u
{
    int n;
    char ch;
    bool tf;
};

struct stack{
    int size;
    int top;
    u elements[50];
    int tag;
};

void push(stack &s, u x){
    if(s.top == s.size-1)
        cout<< "Stack is full"<<endl;
    else{
        if(s.tag == 1)
            s.elements[++s.top].n = x.n;
        else if(s.tag == 2)
            s.elements[++s.top].ch = x.ch;
        else if(s.tag == 3)
            s.elements[++s.top].tf = x.tf;
    }   
}

u pop(stack &s){
    u t;
    if( s.top == -1){
        cout<< "Stack is empty" << endl;
        return t;
    }

    else{
        //s.top--;
        return s.elements[s.top--];
    }
}

u peek(stack &s){
    u t;
    if( s.top == -1){
        cout<< "Stack is empty" << endl;
        return t;
    }
    else
        return s.elements[s.top];
}

int main(){
    stack s;

    s.top = -1;
    s.size = 6;
    s.tag = 1;

    for(int i=0;i<s.size;i++){
        u x;
        cin>>x.n;
        push(s,x);
    }
    int l =peek(s).n;
    cout<< endl << l << endl;

    for(int i=0;i<s.size;i++){
        int l = pop(s).n;
        cout<< l << " ";
    }
    cout<<endl;
    return 0;
}