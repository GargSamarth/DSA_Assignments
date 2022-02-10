#include <iostream>

using namespace std;

struct queue{
    int size;
    int f;
    int r;
    char elements[50];
};

struct stack{
    int size;
    int top;
    char A[50];
};

void enqueue(queue &q, char s){
    if((q.r+1)%q.size == q.f)
        cout<< "Queue is full"<<endl;

    else{
        if(q.f == -1){
            q.f=0;  q.r=0;
        }
        else{
            q.r = (q.r+1)%q.size;
        }
        q.elements[q.r] = s;
    }
}

char dequeue(queue &q){
    if(q.f == -1){
        cout<< "Queue is empty"<<endl;
        return 0;
    }
    else{
        char s = q.elements[q.f];

        if(q.f == q.r){
             q.f = q.r = -1;
        }
        else
            q.f++;

        return s;
    }
}

void push(stack &s, char x){
    if(s.top == s.size-1)
        cout<< "Stack is full"<<endl;
    else
        s.A[++s.top] = x;
}

char pop(stack &s){
    if( s.top == -1){
        cout<< "Stack is empty" << endl;
        return '1';
    }
    else
        return s.A[s.top--];
}

char peek(stack &s){
    if( s.top == -1){
        cout<< "Stack is empty" << endl;
        return '1';
    }
    else
        return s.A[s.top];
}

void reverse(stack &s, queue &q, int i, int n, int flag){
    if(i<n && flag==1 ){
        push(s,dequeue(q));
        reverse(s,q,i+1,n,flag);
    }
    else if(i<n && flag == 2){
        enqueue(q,pop(s));
        reverse(s,q,i+1,n,flag);
    }
    else if(i == n){
        reverse(s,q,0,n,flag+1);
    }
    return;
}

int main(){
    stack s;
    queue q;
    
    s.top = -1;
    
    q.f = q.r = -1;
    char *A = new char [30];

    int j = 0;

    while(A[j-1] != '#')
        cin>>A[j++];
        
    q.size = s.size = j-1;

    for(int i=0;i<j-1;i++)
        enqueue(q,A[i]);

    reverse(s,q,0,j-1,1);

    for(int i=0;i<j-1;i++){
        cout<< dequeue(q)<< " ";
    }
    cout<< endl;
    return 0;
}