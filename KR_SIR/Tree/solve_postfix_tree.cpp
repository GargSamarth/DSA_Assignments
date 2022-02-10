#include <iostream>

using namespace std;

struct btnode {
    btnode *lc;
    union
    {
        int n;
        char ch;
    }data;
    btnode *rc;
    int tag;
};

//define 
typedef btnode *btptr;

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

void insert(stack &stk, int tag){

    if(tag == 1){
        int x;
        cin>>x;
        btptr T1 = new btnode;
        T1->data.n = x;
        T1->tag = 1;
        T1->lc = T1->rc = NULL;

        push(stk,T1);
    }

    else if(tag == 2){
        char ch;
        cin>>ch;
        btptr T1 = new btnode;
        T1->data.ch = ch;
        T1->tag = 2;
        T1->lc = T1->rc = NULL;

        T1->rc = pop(stk);
        T1->lc = pop(stk);

        push(stk,T1);
    }
}

int evaluate(int a, int b, char ch){

    switch (ch)
    {
    case '+': return a+b;
        break;
    case '-': return a-b;
        break;
    case '*': return a*b;
        break;
    case '/': return a/b;
        break;
    default: return -1;
        break;
    }
}

int solve(btptr T){
    if(T != NULL){
        if(T->lc->tag == 2 && T->rc->tag == 2)
            return evaluate(solve(T->lc) , solve(T->rc) , T->data.ch);
        
        else if(T->lc->tag == 2 && T->rc->tag == 1)
            return evaluate(solve(T->lc) , T->rc->data.n , T->data.ch);
        
        else if(T->lc->tag == 1 && T->rc->tag == 2)
            return evaluate(T->lc->data.n , solve(T->rc), T->data.ch);
        
        else
            return evaluate(T->lc->data.n, T->rc->data.n, T->data.ch);
    }
    else return 0;
}

//printing ------------

void preorder(btptr T){

    if(T != NULL){
        if(T->tag == 1)
            cout<< T->data.n << " ";
        else
            cout<< T->data.ch << " ";

        preorder(T->lc);
        preorder(T->rc);
    }
}

int main(){
    btptr BT = NULL;
    stack stk;
    stk.top = -1;
    stk.size = 20;

    int tag;

    cin>>tag;

    while(tag != -1){
        insert(stk, tag);
        cin>>tag;
    }
    BT = pop(stk);

    preorder(BT);
    cout<< endl;

    cout<< solve(BT) << endl;

    return 0;
}
//1 5 1 4 1 3 2 * 2 + 1 2 2 - -1