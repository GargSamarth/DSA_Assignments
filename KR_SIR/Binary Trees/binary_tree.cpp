#include <iostream>

using namespace std;

struct btnode{
    btnode *rc;
    char data;
    btnode *lc;
};

typedef btnode *btptr;

void insert(btptr &T, char ch){

    if(T == NULL){
        T = new btnode;
        T->data = ch;
        T->lc = T->rc = NULL;
    }

    cin>>ch;

    if(ch != '.'){
        insert(T->lc,ch);
        ch = '.';
    }
        
    if(ch == '.'){
        cin>>ch;

        if(ch != '.')
            insert(T->rc, ch);
    }

}

void find(btptr T, char ch, btptr &mark){

    if(T != NULL){

        if(T->data == ch)
            mark = T;

            find(T->lc, ch, mark);
            find(T->rc, ch, mark);

            return;
    }
}

//printing methods

void preorder(btptr T){
    if(T != NULL){
        cout<< T->data << " ";
        preorder(T->lc);
        preorder(T->rc);
    }
}

void inorder(btptr T){

    if(T != NULL){

        inorder(T->lc);
        cout<< T->data << " ";
        inorder(T->rc);

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
    char ch;
    btptr BT = NULL;

    cin>> ch;
    if(ch != '.')
        insert(BT, ch);
    
    preorder(BT);
    cout<< endl;

    inorder(BT);
    cout<< endl;

    postorder(BT);
    cout<< endl;

    return 0;
}