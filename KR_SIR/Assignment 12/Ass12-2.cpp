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
        return 1;
    }
    else
        return s.A[s.top--];
}

void enqueue(stack &s, int n){
    if(s.top == s.size-1)
        cout<< "Queue is full"<<endl;
    else{
        push(s,n);
    }
}

int dequeue(stack &s){
    if(s.top == -1){
        cout<< "Queue is empty"<<endl;
        return 0;
    }
    else{
        stack temp;
        temp.top = -1;
        temp.size = s.size;
        while(s.top>-1)
            push(temp,pop(s));
        int ret = pop(temp);
        while(temp.top>-1)
            push(s,pop(temp));
        
        return ret;
    }
}

void enqueue2(stack &s, int n){
    if(s.top == s.size-1)
        cout<< "Queue is full"<<endl;
    else{

        stack temp;
        temp.top = -1;
        temp.size = s.size;
        while(s.top>-1)
            push(temp,pop(s));

        push(temp,n);

        while(temp.top > -1)
            push(s,pop(temp));
    }
}

int dequeue2(stack &s){
    if(s.top == -1){
        cout<< "Queue is empty"<<endl;
        return 0;
    }
    else{

        return pop(s);
    }
}

int main(){
    stack s;
    s.top = -1;
    s.size = 50;

    int n;
    do{
        cout<< "Enter 0 for enqueue, 1 for dequeue and 7 for exiting: ";
        cin>>n;

        if(n == 0){
            int x;
            cin>>x;
            enqueue(s,x);
        }
        else if(n == 1)
            cout<< dequeue(s) <<endl;

    }while(n != 7);

    cout<< endl;

    return 0;
}