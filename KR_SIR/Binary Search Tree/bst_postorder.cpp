#include <iostream>

using namespace std;

struct bstnode {
    bstnode *lchild;
    int data;
    bstnode *rchild;
};

//define 
typedef bstnode *bstptr;

struct stack{
    int size;
    int top;
    bstptr A[50];
};

struct queue{
    int size;
    int f;
    int r;
    bstptr elements[50];
};

void push(stack &s, bstptr x){
    if(s.top == s.size-1)
        cout<< "Stack is full"<<endl;
    else
        s.A[++s.top] = x;
}

bstptr pop(stack &s){
    if( s.top == -1){
        cout<< "Stack is empty" << endl;
        return NULL;
    }
    else
        return s.A[s.top--];
}

void enqueue(queue &q, bstptr x){
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

bstptr dequeue(queue &q){
    if(q.f == -1){
        cout<< "Queue is empty"<<endl;
        return NULL;
    }

    else{

        bstptr temp = q.elements[q.f];

        if(q.f == q.r){
             q.f = q.r = -1;
        }
        else
            q.f = (q.f+1)%q.size;

        return temp;
    }
}

void insert(bstptr &T, bstptr K){

        if(T == NULL){
            T = K;
        }

        else{
            if(K->data < T->data)
                insert(T->lchild, K);

            else
                insert(T->rchild, K);
        }
}

void level_order(queue q){

    while(q.f != -1){

        bstptr temp = dequeue(q);

        while(temp->data != -1){

            cout<< temp->data<< " ";
            
            if(temp->lchild != NULL)
                enqueue(q,temp->lchild);

            if(temp->rchild != NULL)
                enqueue(q,temp->rchild);
            
            temp = dequeue(q);
        }

        if(q.f != -1){
            bstptr samp = new bstnode;
            samp->data = -1;
            samp->lchild = samp->lchild = NULL;
            enqueue(q,samp);
        }
        cout<< endl;
    }
}

void preorder(bstptr T){

    if(T != NULL){
        cout<< T->data << " ";
        preorder(T->lchild);
        preorder(T->rchild);
    }
}

int main(){
    
    int n;
    cin>>n;

    stack stk;
    stk.top = -1;
    stk.size = 10;

    while(n != -1){
        bstptr T = new bstnode;
        T->data = n;
        T->lchild = T->rchild = NULL;
        push(stk,T);

        cin>>n;
    }

    bstptr BT = NULL;

    while(stk.top != -1)
        insert(BT,pop(stk));
    
    queue q;
    q.r = q.f = -1;
    q.size = 20;
    
    bstptr temp = new bstnode;
    temp->data = -1;
    temp->lchild = temp->lchild = NULL;

    //print level order
    enqueue(q,BT);
    enqueue(q,temp);
    level_order(q);

    return 0;
}