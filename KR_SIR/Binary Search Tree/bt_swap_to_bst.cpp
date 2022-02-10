#include <iostream>

using namespace std;

struct btnode{
    btnode *rc;
    int data;
    btnode *lc;
};

typedef btnode *btptr;

void insert(btptr &T, int k){

    if(T == NULL){
        T = new btnode;
        T->data = k;
        T->lc = T->rc = NULL;
    }

    cin>>k;

    if(k != 0){
        insert(T->lc,k);
        k = 0;
    }
        
    if(k == 0){
        cin>>k;

        if(k != 0)
            insert(T->rc, k);
    }

}

void find(btptr T, int k, btptr &mark){

    if(T != NULL){

        if(T->data == k)
            mark = T;

            find(T->lc, k, mark);
            find(T->rc, k, mark);

            return;
    }
}

void convert_to_bst(btptr T){

    if(T == NULL){
        T = new btnode;
        T->data = k;
        T->lc= NULL;
        T->rc = NULL;
    }

    else{

        if(T->lc->data < T->data){
            convert_to_bst(T->lc);
        }

        else if(T->rc->data > T->data){
            convert_to_bst(T->rc);
        }
            
    }
}

int correct(btptr T, btptr k){

    if(T != NULL){
        int l = T->data;

        if(T->lc != NULL && l < correct(T->lc,k)){
            find(T,correct(T->lc,k),k);
        }

        else if(T->rc != NULL && l > correct(T->rc,k)){
            find(T,correct(T->rc,k),k);
        }

        else{
            return l;
        }
            
    }
}

void preorder(btptr T){
    if(T != NULL){
        cout<< T->data << " ";
        preorder(T->lc);
        preorder(T->rc);
    }
}


int main() {
    int k;
    btptr BT = NULL;

    cin>> k;
    if(k != 0)
        insert(BT, k);
    
    btptr k = new btnode;
    correct(BT,k);
    preorder(BT);
    cout<< endl;

    return 0;
}