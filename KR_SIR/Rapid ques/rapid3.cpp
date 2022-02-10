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

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void range_reverse(lptr P, int i, int j){
    int temp = j,temp2 = i;
    lptr last;
    lptr first;

    while(i<j){

        temp = j;
        temp2 = i;
        last = first = P;

        while(temp--){
            last = last->next;
        }

        while(temp2--){
            first = first->next;
        }
        swap(first->data, last->data);
        i++;
        j--;
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
    
    int i,j;
    cin>>i>>j;
    range_reverse(L,i-1,j-1);
    print(L);
    cout<< endl;
    
    return 0;
}