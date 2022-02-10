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

void print(lptr A[]){

    for(int i=0;i<7;i++){
        
        lptr T = A[i];

        while(T->next != NULL){

            T = T->next;
            cout<< T->data << " ";

        }

    }

    cout<< endl;
}

void chain(lptr A[], int n){

        int index = n % 7;

        lptr T = A[index];

        while(T->next != NULL)
            T = T->next;
        
        lptr T1 = new node;
        T1->data = n;
        T1->next = NULL;
        T->next = T1;
    
}

int main(){

    lptr A[7];

    for(int i=0;i<7;i++){
        A[i] = new node;
        A[i]->next = NULL;
    }

    int n;

    cin>>n;

    while(n > 0){
        chain(A,n);
        cin>>n;
    }

    print(A);
    cout<< endl;

    return 0;
}