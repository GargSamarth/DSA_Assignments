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

    int min=96325, max=-85236, asc = 0, dec = 0,unso=0;
    int count = 0;
    while(q.f != -1){

        btptr temp = dequeue(q);
        count++;

        while(temp->data != -1){

            if(min > temp->data)
                min = temp->data;

            if(max < temp->data)
                max = temp->data;

            if(temp->lc != NULL)
                enqueue(q,temp->lc);

            if(temp->rc != NULL)
                enqueue(q,temp->rc);
            
            temp = dequeue(q);
        }

        int i = q.f;
        int flag = 1;
        while(i != q.r){

            if(q.elements[i]->data > q.elements[i+1]->data){
                flag = 0;
                break;
            }

            i = (i+1)%q.size;
        }
        if(q.f != -1){
            if(flag == 1)
                asc = count;
            else
                unso = count;
        }

        //-----------------------------
        i = q.f;
        flag = 1;
        while(i != q.r){

            if(q.elements[i]->data < q.elements[i+1]->data){
                flag = 0;
                break;
            }
            
            i = (i+1)%q.size;
        }
        if(q.f != -1){
            if(flag == 1)
                dec = count;
            else
                unso = count;
        }

        if(q.f != -1){
            btptr samp = new btnode;
            samp->data = -1;
            samp->lc = samp->rc = NULL;
            enqueue(q,samp);
        }
    }
    cout<<max<<endl<<min<<endl<<asc<<endl<<dec<<endl<<unso<<endl;
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