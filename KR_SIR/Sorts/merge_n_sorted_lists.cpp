#include <iostream>

using namespace std;

struct bstnode {
    bstnode *lc;
    int data;
    bstnode *rc;
};

//define 
typedef bstnode *bstptr;

void insert(bstptr &T, int k){
    if(T == NULL){
        T = new bstnode;
        T->data = k;
        T->lc = T->rc = NULL;
    }
    else{
        if(k < T->data)
            insert(T->lc, k);
        else
            insert(T->rc, k);
    }
}

// void inorder(bstptr T, int *A, int &i){
//     if(T != NULL){
//         inorder(T->lc,A,i);
//         A[i++] = T->data;
//         inorder(T->rc,A,i);
//     }
// }

void inorder(bstptr T){
    if(T != NULL){
        inorder(T->lc);
        cout<<T->data<< " ";
        inorder(T->rc);
    }
}

int main(){
    int n;
    cout<< "Number of lists to be merged: ";
    cin>>n;
    bstptr BT = NULL;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        while(k != -1){
            insert(BT,k);
            cin>>k;
        }
    }
    inorder(BT);
    cout<< endl;
    return 0;
}