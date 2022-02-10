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

void level_insert(queue q){

    char ch;
    btptr samp1 = new btnode;
    samp1->data = '*';
    samp1->lc = samp1->rc = NULL;
    enqueue(q,samp1);

    while(q.f != -1){

        btptr temp = dequeue(q);

        while(temp->data != '*'){

            if(temp->lc == NULL){
                cin>>ch;
                if(ch == '$')
                    break;

                if(ch != '#'){
                    btptr K = new btnode;
                    K->lc = K->rc = NULL;
                    K->data = ch;
                    temp->lc = K;
                    enqueue(q,K);
                }
            }

            if(temp->rc == NULL){
                cin>>ch;
                if(ch == '$')
                    break;

                if(ch != '#'){
                    btptr K = new btnode;
                    K->lc = K->rc = NULL;
                    K->data = ch;
                    temp->rc = K;
                    enqueue(q,K);
                }
            }
            
            temp = dequeue(q);
        }
        if(ch == '$')
            break;
            
        if(q.f != -1){
            btptr samp = new btnode;
            samp->data = '*';
            samp->lc = samp->rc = NULL;
            enqueue(q,samp);
        }
    }
}

void level_order(queue q){

    btptr samp1 = new btnode;
    samp1->data = '*';
    samp1->lc = samp1->rc = NULL;
    enqueue(q,samp1);

    while(q.f != -1){

        btptr temp = dequeue(q);

        while(temp->data != '*'){

            cout<< temp->data << " ";

            if(temp->lc != NULL)
                enqueue(q,temp->lc);

            if(temp->rc != NULL)
                enqueue(q,temp->rc);
            
            temp = dequeue(q);
        }

        cout<<endl;

        if(q.f != -1){
            btptr samp = new btnode;
            samp->data = '*';
            samp->lc = samp->rc = NULL;
            enqueue(q,samp);
        }
    }
}


int main() {
    char ch,ch2;
    cin>>ch;

    btptr BT = new btnode;
    BT->data = ch;
    BT->lc = BT->rc = NULL;

    queue q;
    q.f = q.r = -1;
    q.size = 20;
    enqueue(q,BT);
    level_insert(q);
    
    q.f = q.r = -1;
    enqueue(q,BT);

    level_order(q);

    return 0;
}