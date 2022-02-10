#include <iostream>

using namespace std;

struct snode{
    int val,l,h;
};

struct bstnode {
    bstnode *lchild;
    snode data;
    bstnode *rchild;
};

//define 
typedef bstnode *bstptr;

void insert(bstptr &T, int k, int l, int h){
    if(T == NULL){
        T = new bstnode;
        T->data.val = k;
        T->data.h = h;
        T->data.l = l;
        T->lchild = NULL;
        T->rchild = NULL;
    }
    else{
        if(k < T->data.val)
            insert(T->lchild, k,l,h);
        else
            insert(T->rchild, k,l,h);
    }
}

void find_overlap(bstptr T, int l, int h){
    if(T != NULL){
        if(l>T->data.l && h<T->data.h)
        cout<< T->data.l << " " << T->data.h<<endl;
        find_overlap(T->lchild,l,h);
        find_overlap(T->rchild,l,h);
    }
}

int main(){
    int q=8;
    //cin>>n;
    bstptr BT = NULL;
    
    while(q--){
        int type;
        cin>>type;
        if(type == 1){
            int val,l,h;
            cin>>l>>h>>val;
            insert(BT,val,l,h);
        }
        else{
            int l, h;
            cin>>l>>h;
            find_overlap(BT,l,h);
        }
    }
    return 0;
}