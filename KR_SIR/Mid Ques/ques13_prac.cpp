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

void level_order(queue q){

    while(q.f != -1){
        btptr temp = dequeue(q);
        while(temp->data != -1){
            if(temp->lc != NULL)
                enqueue(q,temp->lc);
            if(temp->rc != NULL)
                enqueue(q,temp->rc);
            temp = dequeue(q);
        }
        queue temp1;
        temp1.f = temp1.f = -1;
        temp1.size = 10;
        int flag = -1;
        btptr a = NULL;
        if(q.f != -1)
            a = dequeue(q);

        while(q.f != -1){
            btptr b = dequeue(q);
            if(flag == -1){
                if(a->data < b->data)
                    flag = 0;
                else if(a->data > b->data)
                    flag = 1;
                else{
                    enqueue(temp1,a); enqueue(temp1,b);
                    flag = 2;
                    break;
                }
            }
            else if(flag == 0){
                if(a->data > b->data)
                    flag = 1;
                else{
                    enqueue(temp1,a); enqueue(temp1,b);
                    flag = 2;
                    break;
                }
            }
            else{
                if(a->data < b->data)
                    flag = 0;
                else{
                    enqueue(temp1,a); enqueue(temp1,b);
                    flag = 2;
                    break;
                }
            }
            enqueue(temp1,a);
            a = b;
        }
        if(flag == 2){
            while(q.f != -1)
                enqueue(temp1,dequeue(q));
            while(temp1.f != -1)
                enqueue(q,dequeue(temp1));
        }
        else if(flag != -1){
            enqueue(temp1,a);
            while(temp1.f != -1){
                btptr c = dequeue(temp1);
                cout<< c->data << " ";
                enqueue(q,c);
            }
            cout<< endl;
        }
        if(q.f != -1){
            btptr samp = new btnode;
            samp->data = -1;
            samp->lc = samp->rc = NULL;
            enqueue(q,samp);
        }
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
    
    btptr temp = new btnode;
    temp->data = -1;
    temp->lc = temp->rc = NULL;

    enqueue(q,BT);
    enqueue(q,temp);
    level_order(q);

    return 0;
}