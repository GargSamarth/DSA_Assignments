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

void create_path(queue q){

    queue dc;
    dc.r = dc.f = -1;
    dc.size = 20;

    queue ans;
    ans.f = ans.r = -1;
    ans.size = 20;

    btptr sol = q.elements[0];

    while(sol != NULL){
        if(sol->rc != NULL || sol->lc != NULL)
            enqueue(ans,sol);
        sol = sol->lc;        
    }

    sol = q.elements[0];

    stack path;
    path.top = -1;
    path.size = 20;

    do{

        btptr t = dequeue(q);
        push(path,t);

        if(t->rc != NULL && t->lc != NULL){

            if(!check_discovered(dc, t->lc)){
                enqueue(q,t->lc);
            }

            else if(!check_discovered(dc, t->rc)){
                enqueue(q,t->rc);
            }
        }

        else if(t->rc != NULL && t->lc == NULL){

            if(!check_discovered(dc, t->rc)){
                enqueue(q,t->rc);
            }
        }

        else if(t->rc == NULL && t->lc != NULL){

            if(!check_discovered(dc, t->lc)){
                enqueue(q,t->lc);
            }
        }

        else{

            enqueue(dc,t);
            enqueue(ans,t);

            btptr find = pop(path);

            while(path.top != -1 && check_discovered(dc,find))
                    find = pop(path);
                

            if(!check_discovered(dc,find)){
                enqueue(dc,find);
                enqueue(q,find);
            }
        }

    }while(q.f != -1);

    stack stk;
    stk.size = 5;
    stk.top = -1;

    while(sol != NULL){
                push(stk,sol);
        
        sol = sol->rc;
    }

    while(stk.top != -1)
        enqueue(ans, pop(stk));

    while(ans.f != -1)
        cout<< dequeue(ans)->data << " ";
    cout<< endl;

}

int main() {
    int k,l,h;
    btptr BT = NULL;

    cin>> k;
    if(k != 0)
        insert(BT, k);

    queue q;
    q.f = q.r = -1;
    q.size = 20;

    enqueue(q,BT);
    create_path(q);

    return 0;
}