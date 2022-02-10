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

void insert(btptr &T, int ch){

    if(T == NULL){
        T = new btnode;
        T->data = ch;
        T->lc = T->rc = NULL;
    }

    cin>>ch;

    if(ch != 0){
        insert(T->lc,ch);
        ch = 0;
    }
        
    if(ch == 0){
        cin>>ch;

        if(ch != 0)
            insert(T->rc, ch);
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

    queue left;
    left.f = left.r = -1;
    left.size = 10;

    queue right;
    right.f = right.r = -1;
    right.size = 10;

    queue leaf;
    leaf.f = leaf.r = -1;
    leaf.size = 10;

    queue boundary;
    boundary.f = boundary.r = -1;
    boundary.size = 10;

    queue bottom;
    bottom.f = bottom.r = -1;
    bottom.size = 10;

    btptr dot = new btnode;
    dot->data = -1;
    dot->lc = dot->rc = NULL;

    queue hidden;
    hidden.f = hidden.r = -1;
    hidden.size = 10;

    while(q.f != -1){

        enqueue(left,q.elements[q.f]);
        enqueue(right,q.elements[q.r]);
        enqueue(q,dot);
        btptr T = dequeue(q);

        while(T->data != -1){

            enqueue(hidden,T);

            if(T->lc != NULL)
                enqueue(q,T->lc);
            else enqueue(bottom,T);
            
            if(T->rc != NULL)
                enqueue(q,T->rc);
            else enqueue(bottom,T);
            
            if(T->lc == NULL && T->rc == NULL){
                enqueue(leaf,T);
                enqueue(bottom,T);
            }
            
            T = dequeue(q);
        }
    }
    cout<< endl;
    //printing left view
    cout<< "Nodes in left view --------------" << endl<<"\t";
    while(left.f != -1)
        cout<< dequeue(left)->data << " ";
    cout<< "\t \t| "<<endl<< "---------------------------------" << endl<< endl;
    
    //printing right view
    cout<< "Nodes in right view -------------" << endl<<"\t";
    while(right.f != -1)
        cout<< dequeue(right)->data << " ";
    cout<< "\t \t| "<<endl<< "---------------------------------" << endl<<endl;

    btptr temp = BT;
    while(temp != NULL){
        enqueue(boundary,temp);
        temp = temp->lc;
    }
    while(leaf.f != -1){
        enqueue(boundary,dequeue(leaf));
    }
    temp = BT;
    stack stk;
    stk.top = -1; stk.size = 10;
    while(temp != NULL){
        push(stk,temp);
        temp = temp->rc;
    }
    while(stk.top != -1)
        enqueue(boundary,pop(stk));

    //printing hidden view
    cout<< "Nodes in hidden view ------------" << endl<<"\t";
    while(hidden.f != -1){
        btptr prnt = dequeue(hidden);

        if(!check_discovered(boundary,prnt))
        cout<< prnt->data << " ";
    }
    cout<< "\t\t\t| "<<endl<< "---------------------------------" << endl<<endl;

    //printing boundary view
    cout<< "Nodes in boundary view ----------" << endl<<"\t"<<dequeue(boundary)->data<< " ";
    while(boundary.f != -1){
        btptr prnt = dequeue(boundary);

        if(!check_discovered(boundary,prnt))
        cout<< prnt->data << " ";
    }
    cout<< "\t| "<<endl<< "---------------------------------" << endl<<endl;

    queue top;
    top.f = top.r = -1;
    top.size = 10;
    //top view
    temp = BT;
    while(temp != NULL){
        enqueue(top,temp);
        temp = temp->lc;
    }
    temp = BT;
    stk.top = -1;
    while(temp != NULL){
        push(stk,temp);
        temp = temp->rc;
    }
    while(stk.top != -1)
        enqueue(top,pop(stk));

    cout<< "Nodes in Top view ---------------" << endl<<"\t"<<dequeue(top)->data<< " ";
    while(top.f != -1){
        btptr prnt = dequeue(top);

        if(!check_discovered(top,prnt))
        cout<< prnt->data << " ";
    }
    cout<< "\t| "<<endl<< "---------------------------------" << endl<<endl;

    //printing bottom view
    cout<< "Nodes in bottom view ------------" << endl<<"\t";
    while(bottom.f != -1){
        btptr prnt = dequeue(bottom);

        if(!check_discovered(bottom,prnt))
        cout<< prnt->data << " ";
    }
    cout<< "\t\t| "<<endl<< "---------------------------------" << endl<<endl;

    
}

int main() {
    int ch;
    btptr BT = NULL;

    cin>> ch;
    if(ch != 0)
        insert(BT, ch);
    
    queue q;
    q.f = q.r = -1;
    q.size = 20;
    enqueue(q,BT);

    view(q,BT);

    return 0;
}