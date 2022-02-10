#include <iostream>

using namespace std;

union U
{
    int x;
    char ch;
};


struct node{
    U data;
    int tag;
    node *next;
};

//defining node * to lptr
typedef node *lptr;

void insert(lptr P, int tag, U in){

    lptr T = new node;
    
    if(tag == 0){
        while( P->next != NULL && P->next->tag != 1 )
            P = P->next;
        T->data.ch = in.ch;
        T->tag = 0;
        //cout<< T->data.ch << " = data, tag = " << tag<<endl;
        T->next = P->next; 
    }

    else{
        while(P->next != NULL)
            P = P->next;
        T->data.x = in.x;
        T->tag = 1;
        //cout<< T->data.x << " = data, tag = " << tag<<endl;
        T->next = NULL;
    }
    P->next = T;

}

void print(lptr P){

    if(P != NULL){

        if(P->tag == 0)
            cout<< P->data.ch << " ";

        else{
                cout<< P->data.x << " ";
        }

        print(P->next);
    }

    return;
}

int main(){
    lptr L = new node;
    //int *tags = new int[20];
    int n;
    char ch;
    cin>>L->tag;

    if(L->tag == 1){
        cin>>n;
        L->data.x = n;
    }

    else{
        cin>>ch;
        L->data.ch = ch;
    }

    L->next = NULL;

    int tag;
    cin>>tag;
    U t;

    if(tag == 1){
        cin>>n;
        t.x = n;
    }
    

    else{
        cin>>ch;
        t.ch = ch;
    }
    

    while(ch != '#'){
        insert(L,tag,t);

        cin>>tag;

        if(tag == 1){

            cin>>n;
            t.x = n;
        }

        else{
            cin>>ch;
            t.ch = ch;
        }
    }

    cout<< endl;
    print(L);
    cout<< endl;

    return 0;
}