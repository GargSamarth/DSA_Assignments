#include <iostream>

using namespace std;

struct node{
    int data;
    node *next;
};

//defining node * to lptr
typedef node *lptr;

void insert_2(lptr P, int k, int &count){
    if(count < 5){
        while(P->next != NULL)
            P = P->next;
        lptr T = new node;
        T->data = k;
        T->next = NULL;
        P->next = T;
    }

    else if(count == 5){
        while(P->next != NULL)
            P = P->next;
        lptr T = new node;
        T->data = k;
        P->next = T;
        T->next = P;
    }

    else{
        int temp = count;
        while(temp--)
            P = P->next;
        lptr T = new node;
        T->data = k;
        T->next = P->next;
        P->next = T;
    }
    count++;
}

void insert(lptr P, int k){
    while(P->next != NULL)
        P = P->next;
    lptr T = new node;
    T->data = k;
    T->next = NULL;
    P->next = T;
}

int loop_finder(lptr P){
    lptr T1 = P;
    lptr T2 = P;
    int flag = 0;

    while(T1->next != NULL && T2->next != NULL && T2->next->next != NULL){
        T1 = T1->next;
        T2 = T2->next->next;

        if(T1 == T2){
            flag = 1;
            break;
        }
    }
    if(flag == 1){
        return 1;
    }
    else
        return 0;
}


int main(){
    lptr L;
    int n;
    cin>>n;
    L = new node;
    L->data = n;
    L->next = NULL;
    cin>>n;
    int count = 1;

    while(n > 0){
        insert_2(L,n,count);
        cin>>n;
    }
    
    cout<< loop_finder(L) << endl;   

    return 0;
}