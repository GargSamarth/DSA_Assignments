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
        cout<< "";//"Queue is full"<<endl;

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

void insert(btptr &T, char ch){

    if(T == NULL){
        T = new btnode;
        T->data = ch;
        T->lc = T->rc = NULL;
    }

    cin>>ch;

    if(ch != '#'){
        insert(T->lc,ch);
        ch = '#';
    }
        
    if(ch == '#'){
        cin>>ch;

        if(ch != '#')
            insert(T->rc, ch);
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


void view(queue q, btptr BT){
    queue leaf;
    leaf.f = leaf.r = -1;
    leaf.size = 10;
    queue boundary;
    boundary.f = boundary.r = -1;
    boundary.size = 20;
    btptr dot = new btnode;
    dot->data = '*';
    dot->lc = dot->rc = NULL;
    queue hidden;
    hidden.f = hidden.r = -1;
    hidden.size = 20;

    while(q.f != -1){
        enqueue(q,dot);
        btptr T = dequeue(q);

        while(T->data != '*'){
            enqueue(hidden,T);
            if(T->lc != NULL)
                enqueue(q,T->lc);
            if(T->rc != NULL)
                enqueue(q,T->rc);
            if(T->lc == NULL && T->rc == NULL)
                enqueue(leaf,T);
            T = dequeue(q);
        }
    }
    btptr temp = BT;
    while(temp != NULL){
        enqueue(boundary,temp);
        temp = temp->lc;
    }
    while(leaf.f != -1){
        enqueue(boundary,dequeue(leaf));
    }
    temp = BT;
    while(temp != NULL){
        enqueue(boundary,temp);
        temp = temp->rc;
    }
    //printing hidden view
    while(hidden.f != -1){
        btptr prnt = dequeue(hidden);
        if(!check_discovered(boundary,prnt))
            cout<< prnt->data << " ";
    }
}

int main() {
    char ch;
    btptr BT = NULL;
    cin>> ch;
    if(ch != '#')
        insert(BT, ch);
    queue q;
    q.f = q.r = -1;
    q.size = 20;
    enqueue(q,BT);
    view(q,BT);
    cout<< endl;
    return 0;
}