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

void connect(lptr P1, lptr P2){
    while(P1->data != 6)
        P1 = P1->next;

    while(P2->next != NULL)
        P2 = P2->next;

    P2->next = P1;
}

int find_connection(lptr P1, lptr P2){
    lptr T1 = P1;
    lptr T2 = P2;
    int find,flag = 0;

    T1 = P1;
    T2 = P2;
    while(T1 != NULL && T1 != T2){
        T2 = P2;

        while(T2 != NULL){
            if(T2 == T1){
                flag = 1;
                find = T1->data;
                break;
            }
            T2 = T2->next;
        }
        T1 = T1->next;
        if(flag == 1)
            break;
    }
    if(flag == 1)
        return find;
    else{
        cout<< "Not found"<<endl;
        return -1;
    }
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

    lptr L2;
    cin>>n;
    L2 = new node;
    L2->data = n;
    L2->next = NULL;
    cin>>n;

    while(n > 0){
        insert(L2,n);
        cin>>n;
    }

    connect(L,L2);
    cout<< find_connection(L,L2);
    cout<< endl;
    

    return 0;
}