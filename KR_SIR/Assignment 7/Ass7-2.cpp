#include <iostream>

using namespace std;

struct stack{
    int size;
    int top;
    char A[50];
};

void push(stack &s, char x){
    if(s.top == s.size-1)
        cout<< "Stack is full"<<endl;
    else
        s.A[++s.top] = x;
}

char pop(stack &s){
    if( s.top == -1){
        cout<< "Stack is empty" << endl;
        return -1;
    }
    else
        return s.A[s.top--];
}

char peek(stack &s){
    if( s.top == -1){
        cout<< "Stack is empty" << endl;
        return -1;
    }
    else
        return s.A[s.top];
}

void symbols(stack &s, char *ch, int n){

    for(int i=0;i<n;i++){

            if(ch[i] == '{')
                push(s,ch[i]);
            
            else if(ch[i] == '}')
                cout<< pop(s) << ch[i]<< " ";
    }
    //while()
    cout<< endl;
}

int main(){

    char *ch;
    int n;
    ch = new char [n];
    stack s;
    s.top = -1;

    cin>>n;
    s.size = n;

    for(int i=0;i<n;i++)
        cin>>ch[i];

    symbols(s,ch,n);
    

    return 0;
}