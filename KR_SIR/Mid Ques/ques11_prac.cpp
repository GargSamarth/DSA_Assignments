#include <iostream>

using namespace std;

struct btnode{
    btnode *rc;
    int data;
    btnode *lc;
};

typedef btnode *btptr;

void insert(btptr &T, int ch){
    if(T == NULL){
        T = new btnode;
        T->data = ch;
        T->lc = T->rc = NULL;
    }
    cin>>ch;
    if(ch != 0){
        insert(T->lc,ch);
        ch = 0;
    }   
    if(ch == 0){
        cin>>ch;
        if(ch != 0)
            insert(T->rc, ch);
    }
}
void overlap(btptr T1, btptr &T2){
    if(T1 != NULL){
        if(T2 == NULL){
            T2 = new btnode;
            T2->lc = T2->rc = NULL;
            T2->data = T1->data;
        }
        overlap(T1->lc,T2->lc);
        overlap(T1->rc,T2->rc);
    }
}
void preorder(btptr T){
    if(T != NULL){
        cout<< T->data << " ";
        preorder(T->lc);
        preorder(T->rc);
    }
}
void postorder(btptr T){
    if(T != NULL){
        postorder(T->lc);
        postorder(T->rc);
        cout<< T->data << " ";
    }
}

int main() {
    int ch;
    btptr BT1 = NULL;
    cin>> ch;
    if(ch != 0)
        insert(BT1, ch);
    btptr BT2 = NULL;
    cin>> ch;
    if(ch != 0)
        insert(BT2, ch);
    btptr BT3 = NULL;
    cin>> ch;
    if(ch != 0)
        insert(BT3, ch);

    overlap(BT1,BT2);
    overlap(BT2,BT3);
    preorder(BT3);
    cout<< endl;
    postorder(BT3);
    cout<< endl;
    return 0;
}