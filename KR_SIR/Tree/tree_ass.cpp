#include <iostream>

using namespace std;

struct bstnode {
    bstnode *lchild;
    int data;
    bstnode *rchild;
};

//define 
typedef bstnode *bstptr;

struct queue{
    int size;
    int f;
    int r;
    bstptr elements[50];
};

struct stack{
    int size;
    int top;
    bstptr A[50];
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

void insert(bstptr &T, int k){

    if(T == NULL){
        T = new bstnode;
        T->data = k;
        T->lchild = NULL;
        T->rchild = NULL;
    }

    else{

        if(k < T->data)
            insert(T->lchild, k);

        else
            insert(T->rchild, k);
    }

}

void level_order(queue q, stack &stk){

    while(q.f != -1){

        queue samp;
        samp.r = samp.f = -1;
        samp.size = 10;

        while(q.f != -1){

            bstptr temp = dequeue(q);
            cout<< temp->data<< " ";
            push(stk,temp);
            
            if(temp->lchild != NULL)
                enqueue(samp,temp->lchild);

            if(temp->rchild != NULL)
                enqueue(samp,temp->rchild);

        }
        cout<< endl;
        while(samp.f != -1)
            enqueue(q,dequeue(samp));

    }
}

void level_order2(queue q, stack &stk1){

    while(q.f != -1){

        queue samp;
        samp.r = samp.f = -1;
        samp.size = 10;

        while(q.f != -1){

            bstptr temp = dequeue(q);
            push(stk1,temp);
            
            if(temp->rchild != NULL)
                enqueue(samp,temp->rchild);

            if(temp->lchild != NULL)
                enqueue(samp,temp->lchild);
        }

        while(samp.f != -1)
            enqueue(q,dequeue(samp));

    }
}

void squirrel(queue q, bool flag){

    while(q.f != -1){

        stack stk;
        stk.top = -1;
        stk.size = 20;

        bstptr temp;

        while(q.f != -1){

            temp = dequeue(q);
            cout<< temp->data<< " ";
            push(stk,temp);

        }

        while(stk.top != -1){

            temp = pop(stk);

            if(flag){
                if(temp->lchild != NULL)
                    enqueue(q,temp->lchild);

                if(temp->rchild != NULL)
                    enqueue(q,temp->rchild);
            }

            else{
                if(temp->rchild != NULL)
                    enqueue(q,temp->rchild);

                if(temp->lchild != NULL)
                    enqueue(q,temp->lchild);

            }
        }

        flag = !flag;

    }
}

int main(){
    bstptr BT = NULL;
    int n;

    cin>>n;

    while(n != -1){
        insert(BT, n);
        cin>>n;
    }

    queue q;
    q.r = q.f = -1;
    q.size = 20;

    stack stk;
    stk.top = -1;
    stk.size = 20;
    
    //print level order
    enqueue(q,BT);
    level_order(q,stk);
    cout<< endl;
    
    //print reverse reverse level order
    while(stk.top != -1)
        cout<< pop(stk)->data << " ";
    cout<< endl;

    //print reverse level order
    q.r = q.f = -1;
    enqueue(q,BT);

    stk.top = -1;
    level_order2(q,stk);

    while(stk.top != -1)
        cout<< pop(stk)->data << " ";

    cout<< endl;

    //squirrel anti clock wise
    q.r = q.f = -1;
    enqueue(q,BT);

    squirrel(q,false);
    cout<< endl;

    //squirrel anti clock wise
    q.r = q.f = -1;
    enqueue(q,BT);

    squirrel(q,true);
    cout<< endl;

    //odd level reversal order
    q.r = q.f = -1;
    enqueue(q,BT);

    squirrel(q,false);
    cout<< endl;

    //even level reversal order
    q.r = q.f = -1;
    enqueue(q,BT);

    squirrel(q,true);
    cout<< endl;


    return 0;
}