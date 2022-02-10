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

void Union_ll(lptr P1, lptr P2, lptr &P3){

    lptr T = new node;
    T->data = 0;
    T->next = NULL;

    while(P1 != NULL && P2 != NULL){

        if(P1->data <= P2->data){
            if(P1->data == P2->data){
                insert(T,P1->data);
                P1 = P1->next;
                P2 = P2->next;
            }

            else{
                insert(T,P1->data);
                P1 = P1->next;
            }
        }

        else{
            insert(T,P2->data);
            P2 = P2->next;
        }

    }

    while(P1 != NULL){
        insert(T,P1->data);
        P1 = P1->next;
    }
    while(P2 != NULL){
        insert(T,P2->data);
        P2 = P2->next;
    }
    P3 = T;
    P3 = P3->next;
}

void intersection(lptr P1, lptr P2, lptr &P3){

    lptr T = new node;
    T->data = 0;
    T->next = NULL;

    while(P1 != NULL && P2 != NULL){

        if(P1->data <= P2->data){
            if(P1->data == P2->data){
                insert(T,P1->data);
                P1 = P1->next;
                P2 = P2->next;
            }

            else{
                P1 = P1->next;
            }
        }

        else{
            P2 = P2->next;
        }

    }

    P3 = T;
    P3 = P3->next;
}

void difference(lptr P1, lptr P2, lptr &P3){

    lptr T = new node;
    T->data = 0;
    T->next = NULL;

    while(P1 != NULL && P2 != NULL){

        if(P1->data <= P2->data){
            if(P1->data == P2->data){
                P1 = P1->next;
                P2 = P2->next;
            }

            else{
                insert(T,P1->data);
                P1 = P1->next;
            }
        }

        else{
            P2 = P2->next;
        }

    }

    while(P1 != NULL){
        insert(T,P1->data);
        P1 = P1->next;
    }

    P3 = T;
    P3 = P3->next;
}

void u_Union_ll(lptr P1, lptr P2, lptr &P3){

    lptr T = new node;
    T->data = 0;
    T->next = NULL;

    lptr T1 = new node;
    T1 = P1;

    while(T1 != NULL){
        insert(T,T1->data);
        T1 = T1->next;
    }

    while(P2 != NULL){
        
        T1 = P1;
        int flag = 0;
        while(T1 != NULL){
            if(T1->data == P2->data){
                flag = 1;
                P2 = P2->next;
                break;
            }
            T1 = T1->next;
        }

        if(flag == 0){
            insert(T,P2->data);
            P2 = P2->next;
        }

    }

    P3 = T;
    P3 = P3->next;
}

void u_intersection(lptr P1, lptr P2, lptr &P3){

    lptr T = new node;
    T->data = 0;
    T->next = NULL;

    lptr T2 = new node;

    while(P1 != NULL){
        
        T2 = P2;
        int flag = 0;
        while(T2 != NULL){
            if(T2->data == P1->data){
                flag = 1;
                break;
            }
            T2 = T2->next;
        }

        if(flag == 1)
            insert(T,P1->data);

        P1 = P1->next;        

    }

    P3 = T;
    P3 = P3->next;
}

void u_difference(lptr P1, lptr P2, lptr &P3){

    lptr T = new node;
    T->data = 0;
    T->next = NULL;

    lptr T2 = new node;

    while(P1 != NULL){
        
        T2 = P2;
        int flag = 0;
        while(T2 != NULL){
            if(T2->data == P1->data){
                flag = 1;
                break;
            }
            T2 = T2->next;
        }

        if(flag == 0)
            insert(T,P1->data);

        P1 = P1->next;
    }

    P3 = T;
    P3 = P3->next;
}

int main(){

    lptr L1;
    lptr L2;
    int n;
    cin>>n;
    L1 = new node;
    L1->data = n;
    L1->next = NULL;
    cin>>n;

    while(n > 0){
        insert(L1,n);
        cin>>n;
    }

    cin>>n;
    L2 = new node;
    L2->data = n;
    L2->next = NULL;
    cin>>n;

    while(n > 0){
        insert(L2,n);
        cin>>n;
    }

    lptr L3;

    Union_ll(L1,L2,L3);
    print(L3);
    cout<< endl;

    intersection(L1,L2,L3);
    print(L3);
    cout<< endl;

    difference(L1,L2,L3);
    print(L3);
    cout<< endl;
//---------------------------------------------------

    lptr L4;
    lptr L5;

    cin>>n;
    L4 = new node;
    L4->data = n;
    L4->next = NULL;
    cin>>n;

    while(n > 0){
        insert(L4,n);
        cin>>n;
    }

    cin>>n;
    L5 = new node;
    L5->data = n;
    L5->next = NULL;
    cin>>n;

    while(n > 0){
        insert(L5,n);
        cin>>n;
    }

    u_Union_ll(L4,L5,L3);
    print(L3);
    cout<< endl;

    u_intersection(L4,L5,L3);
    print(L3);
    cout<< endl;

    u_difference(L4,L5,L3);
    print(L3);
    cout<< endl;

    return 0;
}