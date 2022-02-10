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

int node_counter(lptr P){
    int count=0;
    
    while(P != NULL){
        P = P->next;
        count++;
    }
    return count;
}

void reverse_a_ll(lptr &P){

    lptr T1 = new node;
    lptr T2 = new node;
    lptr T = new node;
    T = P;

    int count = node_counter(T) - 1;
    
    int temp = count;
    T = P;

    while(temp--)
        T = T->next;

    while(count >= 0){

        temp = count;
        T1 = NULL;
        T2 = P;

        while(temp--){
            T1 = T2;
            T2 = T2->next;
        }
        T2->next = T1;

        count--;
    }

    P = T;
}


void reorder(lptr P){
    lptr T1 = P;
    int count = node_counter(T1);
    int n = count;
    n = (n / 2) - 1;
    T1 = P;

    while(n--){
        T1 = T1->next;
    }
    lptr T2;
    T2 = T1->next;
    T1->next = NULL;
    T1 = P;
    reverse_a_ll(T2);
    count--;

    lptr T = T2;

    while(T1 != NULL && T2 != NULL){
        T2 = T2->next;
        T->next = T1->next;
        T1->next = T;
        T = T2;
        T1 = T1->next->next;
    }
    T = P;
    while(T->next != NULL)
        T = T->next;
        
    while(T2 != NULL){
        T2->next = T->next;
        T->next = T2;
        T2 = T2->next;
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
    cout<< endl;
    reorder(L);
    print(L);
    cout<< endl;

    return 0;
}