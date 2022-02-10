#include <iostream>

using namespace std;

struct btnode{
    btnode *rc;
    int data;
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

void insert(btptr &T, int k){

    if(T == NULL){
        T = new btnode;
        T->data = k;
        T->lc = T->rc = NULL;
    }

    cin>>k;

    if(k != 0){
        insert(T->lc,k);
        k = 0;
    }
        
    if(k == 0){
        cin>>k;

        if(k != 0)
            insert(T->rc, k);
    }

}

void find(btptr T, int k, btptr &mark){

    if(T != NULL){

        if(T->data == k)
            mark = T;

            find(T->lc, k, mark);
            find(T->rc, k, mark);

            return;
    }
}

void preorder(btptr T){
    if(T != NULL){
        cout<< T->data << " ";
        preorder(T->lc);
        preorder(T->rc);
    }
}

bool check_discovered(queue q, btptr ck){

        queue temp;
        temp.f = temp.r = -1;
        temp.size = 10;

    while(q.f != -1){

        btptr x = dequeue(q);
        enqueue(temp,x);

        if(ck->data == x->data){

            while(temp.f != -1)
                enqueue(q,dequeue(temp));

            return true;
        }

    }

    while(temp.f != -1)
        enqueue(q,dequeue(temp));

    return false;
}

bool chek(queue q, int n){

    btptr t;
    queue dc;
    dc.r = dc.f = -1;
    dc.size = 20;

    stack print;
    print.top = -1;
    print.size = 20;

    do{
        t = dequeue(q);
        push(print,t);

        if(t->rc != NULL && t->lc != NULL){

            if(!check_discovered(dc, t->lc)){
                enqueue(q,t->lc);
            }

            else if(!check_discovered(dc, t->rc)){
                enqueue(q,t->rc);
            }

            else{
                btptr find = pop(print);

                while(print.top != -1 && check_discovered(dc,find)){
                    find = pop(print);
                }
                

                if(!check_discovered(dc,find)){
                    enqueue(dc,find);
                    enqueue(q,find);
                }
            }
        }

        else if(t->rc != NULL && t->lc == NULL){

            if(!check_discovered(dc, t->rc)){
                enqueue(q,t->rc);
            }

            else{
                btptr find = pop(print);

                while(print.top != -1 && check_discovered(dc,find)){
                    find = pop(print);
                }
                

                if(!check_discovered(dc,find)){
                    enqueue(dc,find);
                    enqueue(q,find);
                }
            }
        }

        else if(t->rc == NULL && t->lc != NULL){

            if(!check_discovered(dc, t->lc)){
                enqueue(q,t->lc);
            }

            else{
                btptr find = pop(print);

                while(print.top != -1 && check_discovered(dc,find)){
                    find = pop(print);
                }
                

                if(!check_discovered(dc,find)){
                    enqueue(dc,find);
                    enqueue(q,find);
                }
            }
        }

        else{

            enqueue(dc,t);
            int flag = 0;

            while(print.top != -1){
                btptr temp = pop(print);
                
                if(temp->data > n){
                    return false;
                }
            }

            btptr find = pop(print);

            while(print.top != -1 && check_discovered(dc,find))
                    find = pop(print);
                

            if(!check_discovered(dc,find)){
                enqueue(dc,find);
                enqueue(q,find);
            }
        }

    }while(q.f != -1);

    return true;
}

void find_bst(btptr &A, queue q){
    
    queue dis;
    dis.size = 20;
    dis.f = dis.r = -1;
    
    while(q.f != -1){

        btptr T = dequeue(q);
        enqueue(dis,T);

        if(chek(q, T->data)){

            if(T->lc != NULL && !check_discovered(dis,T->lc)){
                A = T;
                enqueue(q,A);
                enqueue(q,A->lc);
            }
            else if(T->rc != NULL && !check_discovered(dis,T->lc)){
                A = T;
                enqueue(q,A);
                enqueue(q,A->rc);
            }
        }

        else{

            if(T->lc != NULL && !check_discovered(dis,T->lc)){
                enqueue(q,A);
                enqueue(q,A->lc);
            }

            else if(T->rc != NULL && !check_discovered(dis,T->lc)){
                enqueue(q,A);
                enqueue(q,A->rc);
            }
        }
    }
    
}


int main() {
    int k;
    btptr BT = NULL;

    cin>> k;
    if(k != 0)
        insert(BT, k);
    
    preorder(BT);
    cout<< endl;

    queue q;
    q.f = q.r = -1;
    q.size = 20;
    enqueue(q,BT);
    btptr A = NULL;
    find_bst(A,q);


    return 0;
}