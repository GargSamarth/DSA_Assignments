#include <iostream>

using namespace std;

struct btnode{
    btnode *rc;
    char data;
    btnode *lc;
};

typedef btnode *btptr;

int find_arr(char *ch, char k, int n){
    for(int i=0;i<n;i++)
        if(ch[i] == k)
            return i;
        
    return -1;
}

void preorder(btptr T){
    if(T != NULL){
        cout<< T->data;
        preorder(T->lc);
        preorder(T->rc);
    }
    
    else
        cout<< ".";
}

void move_cstm(btptr &T, char ch, int n, char *ch1){

    if(T != NULL){

        if(find_arr(ch1, ch, n) < find_arr(ch1, T->data, n))
            move_cstm(T->lc,ch,n,ch1);   
            
        else
            move_cstm(T->rc,ch,n,ch1);
    }

    else{
        T = new btnode;
        T->data = ch;
        T->lc = T->rc = NULL;
    }
}

void create(btptr &T, char *ch1, char *ch2, int n, int i){

    if(i<n){
        char ch = ch2[i];
        move_cstm(T,ch,n,ch1);
        create(T,ch1,ch2,n,i+1);
    }
}

int main() {
    char *ch1 = new char[9];
    char *ch2 = new char[9];
    
    for(int i=0;i<9;i++)
        cin>>ch1[i];
    
    for(int i=0;i<9;i++)
        cin>>ch2[i];
    
    btptr BT = NULL;
    create(BT,ch1,ch2,9,0);

    preorder(BT);
    cout<< endl;

    return 0;
}

// B M F D A J H R K
// A M B D F J R H K 
