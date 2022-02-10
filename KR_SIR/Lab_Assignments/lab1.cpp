#include <iostream>

using namespace std;

struct node{
    int data;
    node *next;
};

//defining node * to lptr
typedef node *lptr;

void insert(lptr P, int k){
    while(P->next != NULL)
        P = P->next;
    lptr T = new node;
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


void add_front(lptr &P, int k){
    lptr T = new node;
    T->data = k;
    T->next = P;
    P = T;
}

int remove_front(lptr &P){
    lptr T = P;
    P = P->next;
    int k = T->data;
    T->next = NULL;
    delete T;
    return k;
}

void add_back(lptr P, int k){
    while(P->next != NULL)
        P = P->next;
    
    lptr T = new node;
    T->data = k;
    T->next = NULL;
    P->next = T;
}

int node_counter(lptr P){
    int count=0;
    
    while(P != NULL){
        P = P->next;
        count++;
    }
    return count;
}

void push(lptr &P, int x, int size){

    if(node_counter(P) == size)
        cout<< "Stack is full"<< endl;

    else
        add_front(P,x);
    
}

int pop(lptr &P){
    int k = -1;

    if(P == NULL)
        cout<< "Stack is empty"<<endl;

    else
        k = remove_front(P);
    
    return k;
}

void enqueue(lptr P, int n, int size){

    if(node_counter(P) == size)
        cout<< "Queue is full"<< endl;

    else
        add_back(P,n);
}

int dequeue(lptr &P){
    int k = -1;

    if(P == NULL)
        cout<< "Stack is empty"<<endl;

    else
        k = remove_front(P);
    
    return k;
}


int main(){
    lptr stack = new node;
    stack->next = NULL;
    
    int n,size = 10;

    cin>>n;
    stack->data = n;
    cin>>n;
    while(n > 0){
        push(stack,n,size);
        cin>>n;
    }

    cout<< endl;
    while(stack != NULL)
        cout<< pop(stack) << " ";
    cout<< endl;

    lptr queue = new node;
    queue->next = NULL;

    cin>>n;
    queue->data = n;
    cin>>n;
    while(n > 0){
        enqueue(queue,n,size);
        cin>>n;
    }

    cout<< endl;
    while(queue != NULL)
        cout<< dequeue(queue) << " ";
    cout<< endl;

    return 0;
}