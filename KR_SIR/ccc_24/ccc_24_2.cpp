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

lptr add_ll(lptr P1, lptr P2){
    lptr T1 = P1;
    lptr T2 = P2;

    int ans=0, rem=0;
    lptr L = new node;
    L->next = NULL;

    while(T1 != NULL && T2 != NULL){

        if(T1 != NULL && T2 != NULL){
            ans = T1->data + T2->data + rem;
            T1 = T1->next;  T2 = T2->next;
        }
        else if(T1 != NULL && T2 == NULL){
            ans = T1->data + rem;
            T1 = T1->next;
        }
        else if(T1 == NULL && T2 != NULL){
            ans = T2->data + rem;
            T2 = T2->next;
        }

        rem = ans/10;
        ans = ans%10;
        insert(L,ans);
        
    }

    insert(L,rem);
    L = L->next;
    reverse_a_ll(L);
    while(L->data == 0)
        L = L->next;
        
    return L;
}

int main(){
    // lptr L1;
    // int n;
    // cin>>n;
    // L1 = new node;
    // L1->data = n;
    // L1->next = NULL;
    // cin>>n;

    // while(n > 0){
    //     insert(L1,n);
    //     cin>>n;
    // }


    // lptr L2;
    // cin>>n;
    // L2 = new node;
    // L2->data = n;
    // L2->next = NULL;
    // cin>>n;

    // while(n > 0){
    //     insert(L2,n);
    //     cin>>n;
    // }

    // lptr L3 = add_ll(L1,L2);
    // cout<< endl;
    // print(L3);
    // cout<< endl;
    int a,b;
    cin>>a>>b;

    lptr L1 = new node;
    L1->next = NULL;
    while(a>0){
        int x = a%10;
        a=a/10;
        insert(L1,x);
    }
    L1 = L1->next;

    lptr L2 = new node;
    L2->next = NULL;
    while(b>0){
        int x = b%10;
        b=b/10;
        insert(L2,x);
    }
    L2 = L2->next;

    lptr L3 = add_ll(L1,L2);
    //cout<< endl;
    print(L3);
    cout<< endl;

    return 0;
}