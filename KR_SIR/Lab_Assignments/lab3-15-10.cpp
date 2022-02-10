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

void max_bend_finder(queue q){

    int count = 0;
    int flag = 1;
    btptr t;

    stack print;
    print.top = -1;
    print.size = 20;

    stack ans;
    ans.top = -1;
    ans.size = 20;

    stack ans2;
    ans2.top = -1;
    ans2.size = 20;

    do{
        t = dequeue(q);
        push(print,t);

        if(t->rc != NULL && t->lc != NULL){

            if(flag == 1){
                enqueue(q,t->lc);
                count++;
                flag = 2;
            }
            else{
                enqueue(q,t->rc);
                count++;
                flag = 1;
            }
        }

        else if(t->rc != NULL && t->lc == NULL && flag == 2){

            enqueue(q,t->rc);
                count++;
                flag = 1;
        }
        else if(t->rc == NULL && t->lc != NULL && flag == 1){

            enqueue(q,t->lc);
                count++;
                flag = 1;
        }
        else{

            btptr ct = new btnode;
            ct->data = count;
            count = 0;
            ct->lc = ct->rc = NULL;

            btptr temp1;

            if(ans.top == -1){

                while(print.top != -1){
                    temp1 = pop(print);
                    push(ans,temp1);
                }
                push(ans,ct);
                flag = 2;
            }
            else if(ans2.top == -1){

                while(print.top != -1){
                    temp1 = pop(print);
                    push(ans2,temp1);
                }
                push(ans2,ct);
            }
            else
                break;

            enqueue(q,temp1);
            
        }

    }while(q.f != -1);

    int c1 = pop(ans)->data, c2 = pop(ans2)->data;

    if(c1 == c1){
        while(ans.top != -1)
            cout<< pop(ans)->data << " ";
        cout<< endl;

        while(ans2.top != -1)
            cout<< pop(ans2)->data<< " ";
        cout<< endl;
    }
    else if(c1 > c2){
        while(ans.top != -1)
            cout<< pop(ans)->data << " ";
        cout<< endl;
    }
    else{
        while(ans2.top != -1)
            cout<< pop(ans2)->data << " ";
        cout<< endl;
    }
}

int main() {
    int k;
    btptr BT = NULL;

    cin>> k;
    if(k != 0)
        insert(BT, k);

    queue q;
    q.f = q.r = -1;
    q.size = 20;

    enqueue(q,BT);
    max_bend_finder(q);

    return 0;
}