#include <iostream>

using namespace std;

struct node{
    int data;
    node *next;
};

typedef node* lptr;

struct kdnode {
    kdnode *lchild;
    int d;
    lptr data;
    kdnode *rchild;
};

//define 
typedef kdnode *kptr;

void insert(kptr &T, lptr k, int d, int i){

    if(T == NULL){
        T = new kdnode;
        T->data = k;
        T->d = d;
        T->lchild = T->rchild = NULL;
        return;
    }
    else{
        int temp = i;
        lptr kd_temp = T->data;
        lptr P = k;

        while(temp--){
            P = P->next;
            kd_temp = kd_temp->next;
        }

        if(P->data < kd_temp->data)
            insert(T->lchild, k,d,(i+1)%d);

        else
            insert(T->rchild, k,d,(i+1)%d);
    }
}

void inorder(kptr T){

    if(T != NULL){
        inorder(T->lchild);
        while(T->data != NULL){
            cout<< T->data->data;
            if(T->data->next != NULL)
                cout<< " ";
            T->data = T->data->next;
        }
        cout<< endl;
        inorder(T->rchild);
    }
}

void insert_ll(lptr LL, int ch){
    
    while(LL->next != NULL){
        LL = LL->next;
    }
    
    lptr T = new node;
    T->data = ch;
    T->next = NULL;
    LL->next = T;
}

int main(){
    kptr BT = NULL;
    int d;

    //d for Kd ------------
    cin>>d;
    int data;

    do{
        int temp = d;
        lptr n = new node;
        n->next = NULL;
        n->data = 0;

        while(temp--){
            cin>>data;

            if(data != -1)
                insert_ll(n,data);
            else
                break;
        }
        if(data != -1){
            n = n->next;
            insert(BT, n, d,0);
        }
        
    }while(data != -1);

    inorder(BT);
    return 0;
}