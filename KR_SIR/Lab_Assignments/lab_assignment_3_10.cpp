#include <iostream>

using namespace std;

struct node{
    node *left;
    int data;
    node *right;
};

//defining node * to lptr
typedef node *lptr;

void insert(lptr P, int k){
    while(P->right != NULL)
        P = P->right;
    lptr T = new node;
    T->data = k;
    T->right = NULL;
    P->right = T;
    T->left = P;
}

void print(lptr P){
    if(P != NULL){
        cout<< P->data;
        print(P->right);
    }
    return;
}

int node_counter(lptr P){
    int count=0;
    
    while(P != NULL){
        P = P->right;
        count++;
    }
    return count;
}

void reverse_a_ll(lptr &P){

    lptr T1;
    lptr T2 = P;
    lptr last = P;

    while(last->right != NULL)
        last = last->right;

    while(T2->right != NULL){
        T1 = T2;
        T2 = T2->right;

        T1->right = T1->left;
        T1->left = T2;

    }
    T2->right = T2->left;
    T2->left = NULL;

    P = last;
}

lptr add_ll(lptr P1, lptr P2){

    lptr T1 = P1;
    lptr T2 = P2;
    int ans=0, rem=0;
    lptr L = new node;
    L->right = L->left = NULL;

    while(T1 != NULL || T2 != NULL){

        if(T1 != NULL && T2 != NULL){
            ans = T1->data + T2->data + rem;
            T1 = T1->right;  T2 = T2->right;
        }
        else if(T1 != NULL && T2 == NULL){
            ans = T1->data + rem;
            T1 = T1->right;
        }
        else if(T1 == NULL && T2 != NULL){
            ans = T2->data + rem;
            T2 = T2->right;
        }

        rem = ans/10;
        ans = ans%10;
        insert(L,ans);
        
    }

    insert(L,rem);
    L = L->right;
    L->left = NULL;
    reverse_a_ll(L);
    while(L->data == 0)
        L = L->right;
    
    L->left = NULL;
    return L;
}

int main(){

    string str1, str2;
    cin>>str1>>str2;

    lptr L1 = new node;
    L1->right = L1->left = NULL;

    for(int i=0 ; i< str1.length()-1; i++){
        int x = int(str1[i])-48;
        insert(L1,x);
    }
    L1 = L1->right;
    L1->left = NULL;

    lptr L2 = new node;
    L2->right = L2->left = NULL;

    for(int i=0 ; i< str2.length()-1; i++){
        int x = int(str2[i])-48;
        insert(L2,x);
    }
    L2 = L2->right;
    L2->left = NULL;

    reverse_a_ll(L1);
    reverse_a_ll(L2);

    lptr L3 = add_ll(L1,L2);
    print(L3);
    cout<< endl;

    return 0;
}
