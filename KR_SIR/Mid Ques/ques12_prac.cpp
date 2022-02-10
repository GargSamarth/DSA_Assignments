#include <iostream>

using namespace std;

struct queue{
    int size;
    int f;
    int r;
    int elements[100];
};

struct node{
    int data;
    queue ind;
    node *next;
};

//defining node * to lptr
typedef node *lptr;

void enqueue(queue &q, int s){
    if((q.r+1)%q.size == q.f)
        cout<< "Queue is full"<<endl;
    else{   
        if(q.f == -1){
            q.f=0;  q.r=0;}
        else q.r = (q.r+1)%q.size;
        q.elements[q.r] = s;
    }
}

int dequeue(queue &q){
    if(q.f == -1){
        cout<< "Queue is empty"<<endl;
        return -1;
    }
    else{
        int temp = q.elements[q.f];
        if(q.f == q.r){
             q.f = q.r = -1;
        }
        else
            q.f = (q.f+1)%q.size;
        return temp;
    }
}

void insert(lptr P, int k, int ind){
    while(P->next != NULL)
        P = P->next;
    lptr T = new node;
    T->ind.f = T->ind.r = -1;
    T->ind.size = 5;
    enqueue(T->ind,ind);
    T->data = k;
    T->next = NULL;
    P->next = T;
}

void print(lptr P){
    if(P != NULL){
        cout<< P->data << " ";
        print(P->next);
    }
    return;
}

bool find_val(lptr P, int k, lptr &fd){
    while( P != NULL){
        if(P->data == k){
            fd = P;
            return true;
        }
        P = P->next;
    }
    return false;
}

void path(lptr T1){
    while(T1 != NULL){
        if(T1->ind.f != T1->ind.r){
            while(T1->ind.f != -1)
                cout<< dequeue(T1->ind) << " ";
            cout<< T1->data <<endl;
        }
        T1 = T1->next;
    }
}

int main(){
    lptr L1;
    int n;
    cin>>n;
    L1 = new node;
    L1->ind.f = L1->ind.r = -1;
    L1->ind.size = 5;
    enqueue(L1->ind,1);
    L1->data = n;
    L1->next = NULL;
    cin>>n;

    while(n > 0){
        insert(L1,n,1);
        cin>>n;
    }

    lptr L2,fd=NULL;
    cin>>n;
    L2 = new node;
    L2->ind.f = L2->ind.r = -1;
    L2->ind.size = 5;
    enqueue(L2->ind,2);
    L2->data = n;
    L2->next = NULL;
    cin>>n;

    while(n > 0){
        if(find_val(L1,n,fd)){
            lptr temp = L2;
            while(temp->next != NULL)
                temp = temp->next;
            temp->next = fd;
            enqueue(fd->ind,2);
        }
        else
            insert(L2,n,2);
        cin>>n;
    }

    lptr L3;
    fd=NULL;
    cin>>n;
    L3 = new node;
    L3->ind.f = L3->ind.r = -1;
    L3->ind.size = 5;
    enqueue(L3->ind,3);
    L3->data = n;
    L3->next = NULL;
    cin>>n;

    while(n > 0){
        if(find_val(L1,n,fd)){
            lptr temp = L3;
            while(temp->next != NULL)
                temp = temp->next;
            temp->next = fd;
            enqueue(fd->ind,3);
        }
        else
            insert(L3,n,3);
        cin>>n;
    }

    lptr L4;
    fd=NULL;
    cin>>n;
    L4 = new node;
    L4->ind.f = L4->ind.r = -1;
    L4->ind.size = 5;
    enqueue(L4->ind,4);
    L4->data = n;
    L4->next = NULL;
    cin>>n;

    while(n > 0){
        if(find_val(L1,n,fd)){
            lptr temp = L4;
            while(temp->next != NULL)
                temp = temp->next;
            temp->next = fd;
            enqueue(fd->ind,4);
        }
        else
            insert(L4,n,4);
        cin>>n;
    }
    path(L1);
}