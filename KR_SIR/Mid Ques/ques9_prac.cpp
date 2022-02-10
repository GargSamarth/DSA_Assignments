#include <iostream>

using namespace std;

struct btnode{
    btnode *rc;
    int data,AT,DT;
    btnode *lc;
};

typedef btnode *btptr;

void insert(btptr &T, int k){
    if(T == NULL){
        T = new btnode;
        T->data = k;
        T->AT = T->DT = -1;
        T->lc = T->rc = NULL;
    } cin>>k;
    if(k != 0){
        insert(T->lc,k);
        k = 0;
    } 
    if(k == 0){
        cin>>k;
        if(k != 0) insert(T->rc, k);
    }
}

void assign_AT_DT(btptr T, int &count){
    if(T != NULL){
        if(T->AT == -1)
            T->AT = count++;
        assign_AT_DT(T->lc,count);
        assign_AT_DT(T->rc,count);
        if(T->DT == -1)
            T->DT = count++;
    }
}

void find_nodes(btptr T, int a, int b, btptr &P1, btptr &P2, btptr &Head, btptr &leaf){
    if(T != NULL){
        if(T->rc != NULL && T->lc != NULL && P1 == NULL)
            Head = T;
        if(T->DT - T->AT == 1 && P2 == NULL)
            leaf = T;
        if(T->data == a)
            P1 = T;
        if(T->data == b)
            P2 = T;
        if(P1 != NULL && P2 != NULL)
            return;
        find_nodes(T->lc,a,b,P1,P2,Head,leaf);
        find_nodes(T->rc,a,b,P1,P2,Head,leaf);
    }
}

void path(btptr T, btptr P1, btptr P2, btptr Head, btptr leaf){
    int count = 0;
    if(P1->AT >= Head->AT && P1->AT <= leaf->AT)
        count++;

    if(P2->AT >= Head->AT && P2->AT <= leaf->AT)
        count++;
    
    if(count == 2)
        cout<< "1" << endl;
    else
        cout<< "0" << endl;
}

int main(){

    int ch;
    btptr BT = NULL;

    cin>> ch;
    if(ch != 0)
        insert(BT, ch);

    int a,b;
    cin>>b>>a;
    btptr P1=NULL,P2=NULL,Head=NULL,leaf=NULL;

    int count = 0;
    assign_AT_DT(BT,count);

    find_nodes(BT,a,b,P1,P2,Head,leaf);
    path(BT,P1,P2,Head,leaf);
    cout<< endl;
    return 0;
}