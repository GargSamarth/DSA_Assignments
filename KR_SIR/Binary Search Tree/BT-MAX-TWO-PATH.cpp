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

void create_path(queue q, int l, int h){

    btptr t;

    queue dc;
    dc.r = dc.f = -1;
    dc.size = 20;

    stack path;
    path.top = -1;
    path.size = 20;

    stack ans;
    ans.top = -1;
    ans.size = 20;

    stack ans2;
    ans2.top = -1;
    ans2.size = 20;

    do{

        t = dequeue(q);

        if(t->data == l){
            stack temp;
            temp.top = -1;
            temp.size = 20;

            while(path.top != -1){
                btptr temp1 = pop(path);

                push(ans,temp1);
                push(temp,temp1);;
            }

            while(temp.top != -1)
                push(path,pop(temp));
            

            if(t->lc != NULL)
                enqueue(dc,t->lc);
        }

        if(t->data == h){

            while(path.top != -1)
                push(ans2,pop(path));
            
            break;
        }

        push(path,t);

        if(t->rc != NULL && t->lc != NULL){

            if(!check_discovered(dc, t->lc)){
                enqueue(q,t->lc);
            }

            else if(!check_discovered(dc, t->rc)){
                enqueue(q,t->rc);
            }

            else{
                btptr find = pop(path);

                while(path.top != -1 && check_discovered(dc,find)){
                    find = pop(path);
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
                btptr find = pop(path);

                while(path.top != -1 && check_discovered(dc,find)){
                    find = pop(path);
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
                btptr find = pop(path);

                while(path.top != -1 && check_discovered(dc,find)){
                    find = pop(path);
                }
                

                if(!check_discovered(dc,find)){
                    enqueue(dc,find);
                    enqueue(q,find);
                }
            }
        }

        else{

            enqueue(dc,t);

            btptr find = pop(path);

            while(path.top != -1 && check_discovered(dc,find))
                    find = pop(path);
                

            if(!check_discovered(dc,find)){
                enqueue(dc,find);
                enqueue(q,find);
            }
        }

    }while(q.f != -1);

    btptr tp;
    stack order;
    order.top = -1;
    order.size = 20;

    while(ans.top != -1 && ans2.top != -1){
        btptr P1 = pop(ans);
        btptr P2 = pop(ans2);

        if(P1->data == P2->data){
            tp = P1;
        }
        else{
            push(order,P1);
            push(order,P2);
        }
    }
    while(ans.top != -1)
        push(order,pop(ans));

    while(ans2.top != -1)
        push(order,pop(ans2));
    
    push(order,tp);

    int max = 0;

    while(order.top != -1){
        int i = pop(order)->data;

        if(i > max && i != l && i != h)
            max = i;
    }
    cout<<max<< " ";
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

    for(int i=0;i<3;i++){
        enqueue(q,BT);
        cin>>l>>h;
        create_path(q,l,h);
        q.f = q.r = -1;
    }

    return 0;
}