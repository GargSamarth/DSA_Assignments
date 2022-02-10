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

int find(lptr P, int k){
    while( P != NULL){

        if(P->data == k)
            return 1;
        P = P->next;
    }
    return 0;
}

void add_front(lptr &P, int k){
    lptr T = new node;
    T->data = k;
    T->next = P;
    P = T;
}

void insert_after(lptr P, int k, int x){
    while(P->data != k)
        P = P->next;
    lptr T = new node;
    T->data = x;
    T->next = P->next;
    P->next = T;
}

void insert_before(lptr &P, int k, int x){
    lptr T = new node;
    lptr T2 = new node;
    T = P;
    int flag = 0;
    while(T->data != k){
        flag = 1;
        T2 = T;
        T = T->next;
    }
    
    lptr T1 = new node;
    T1->data = x;
    T1->next = T;

    if(flag == 1){
        T2->next = T1;
    }
    else {
        P = T1;
    }
}


int node_counter(lptr P){
    int count=0;
    
    while(P != NULL){
        P = P->next;
        count++;
    }
    return count;
}

int min_node(lptr P){
    lptr T = new node;
    T = P;
    int min = T->data;

    while(T != NULL){
        if(min > T->data)
            min = T->data;
        T = T->next;
    } 
    return min;
}

int max_node(lptr P){
    lptr T = new node;
    T = P;
    int max = T->data;

    while(T != NULL){
        if(max < T->data)
            max = T->data;
        T = T->next;
    } 
    return max;
}

void delete_k(lptr &P, int k){
    lptr T = new node;
    T = P;
    lptr T2 = new node;
    int flag = 0;
    while(T->data != k){
        flag = 1;
        T2 = T;
        T = T->next;
    }

    if(flag == 1){
        T2->next = T->next;
    }
    else{
        P = P->next;
    }
    T->next = NULL;
    delete T;    
}

void delete_min(lptr &P){
    
    lptr T = new node;
    T = P;
    lptr T2 = new node;
    int flag = 0;
    int k = min_node(T);
    while(T->data != k){
        flag = 1;
        T2 = T;
        T = T->next;
    }

    if(flag == 1){
        T2->next = T->next;
    }
    else{
        P = P->next;
    }
    T->next = NULL;
    delete T;    
}

void delete_max(lptr &P){
    lptr T = new node;
    T = P;
    lptr T2 = new node;
    int flag = 0;
    int k = max_node(T);
    while(T->data != k){
        flag = 1;
        T2 = T;
        T = T->next;
    }

    if(flag == 1){
        T2->next = T->next;
    }
    else{
        P = P->next;
    }
    T->next = NULL;
    delete T;    
}


int main(){

    lptr L;
    int n;
    cin>>n;
    L = new node;
    L->data = n;
    L->next = NULL;
    cin>>n;

    while(n > 0){
        insert(L,n);
        cin>>n;
    }
    cout<< endl;

    print(L);
    cout<< endl;
    cin>>n;

    add_front(L,n);
    print(L);
    cout<< endl;
    int x,y;
    cin>>x>>y;

    insert_before(L,y,x);
    print(L);
    cout<< endl;
    cin>>x>>y;

    insert_after(L,y,x);
    print(L);
    cout<< endl;
    cin>>n;

    delete_k(L,n);
    print(L);
    cout<< endl;

    delete_min(L);
    print(L);
    cout<< endl;

    delete_max(L);
    print(L);
    cout<< endl;

    return 0;
}