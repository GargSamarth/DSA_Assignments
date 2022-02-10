#include <iostream>

using namespace std;

struct btnode{
    btnode *rc;
    char data;
    btnode *lc;
};

typedef btnode *btptr;

struct queue{
    int size;
    int f;
    int r;
    btptr elements[50];
};

struct stack{
    int size;
    int top;
    btptr A[50];
};

void push(stack &s, btptr x){
    if(s.top == s.size-1)
        cout<< "Stack is full"<<endl;
    else
        s.A[++s.top] = x;
}

btptr pop(stack &s){
    if( s.top == -1){
        cout<< "Stack is empty" << endl;
        return NULL;
    }
    else
        return s.A[s.top--];
}

void enqueue(queue &q, btptr x){
    if((q.r+1)%q.size == q.f)
        cout<< "Queue is full"<<endl;

    else{   
        if(q.f == -1){
            q.f=0;  q.r=0;
        }
        else{
            q.r = (q.r+1)%q.size;
        }
        q.elements[q.r] = x;
    }
}

btptr dequeue(queue &q){
    if(q.f == -1){
        cout<< "Queue is empty"<<endl;
        return NULL;
    }

    else{

        btptr temp = q.elements[q.f];

        if(q.f == q.r){
             q.f = q.r = -1;
        }
        else
            q.f = (q.f+1)%q.size;

        return temp;
    }
}

void insert(btptr &T, char k){

    if(T == NULL){
        T = new btnode;
        T->data = k;
        T->lc = T->rc = NULL;
    }

    cin>>k;

    if(k != '#'){
        insert(T->lc,k);
        k = '#';
    }
        
    if(k == '#'){
        cin>>k;

        if(k != '#')
            insert(T->rc, k);
    }

}

void preorder(btptr T){

    if(T != NULL){
        cout<< T->data;
        if(T->lc != NULL)
            cout<< "(";
        preorder(T->lc);
        preorder(T->rc);
        if(T->rc != NULL || T->lc != NULL)
            cout<<")";
    }
}

int main() {
    char k,l,h;
    btptr BT = NULL;

    cin>> k;
    if(k != '#')
        insert(BT, k);

    preorder(BT);
    cout<< endl;
    return 0;
}
