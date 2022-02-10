#include <iostream>

using namespace std;

struct node{
    int data;
    node *next;
};

typedef node* lptr;

struct queue{
    int size;
    int f;
    int r;
    lptr elements[100];
};

void enqueue(queue &q, lptr s){
    if((q.r+1)%q.size == q.f)
        cout<< "Queue is full"<<endl;

    else{   
        if(q.f == -1){
            q.f=0;  q.r=0;
        }
        else{
            q.r = (q.r+1)%q.size;
        }
        q.elements[q.r] = s;
    }
}

lptr dequeue(queue &q){
    lptr temp;
    if(q.f == -1){
        cout<< "Queue is empty"<<endl;
        return temp;
    }
    else{
        temp = q.elements[q.f];

        if(q.f == q.r){
             q.f = q.r = -1;
        }
        else
            q.f = (q.f+1)%q.size;

        return temp;
    }
}

void insert(lptr LL, char ch){
    
    while(LL->next != NULL){
        LL = LL->next;
    }
    
    lptr T = new node;
    T->data = ch;
    T->next = NULL;
    LL->next = T;
}

int main(){
    queue q;
    
    q.f = q.r = -1;
    q.size = 10;

    int x;
    
    do{
        cin>>x;

        if(x != -1){
            lptr LL = new node;
            LL->data = x;
            LL->next = NULL;
            cin>> x;
            while(x != 0 && x != -1){
                insert(LL, x);
                cin>>x;
            }
            enqueue(q,LL);
        }
        
    }while(x != -1);
    
    while(q.f != -1){
        lptr T = dequeue(q);
        
        while(T != NULL){
            cout<< T->data << " ";
            T = T->next;
        }
        cout<< endl;
    }
    return 0;
}