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

int remove_front(lptr &P){
    lptr T = P;
    //T = P;
    P = P->next;
    int k = T->data;
    T->next = NULL;
    delete T;
    return k;
}

void game(lptr P1, lptr P2, int sumA, int sumB){
    
    int flag = 0;
    srand(time(0));

    do{
        int random = -1;

        if(P1 != NULL && P2 != NULL)
            random = rand()%2;

        else if(P1 != NULL)
            random = 0;
        
        else
            random = 1;

        if(random == 0){
            if(P1 != NULL){
                sumA +=  remove_front(P1);
                flag = 1;
            }
            else
                cout<< "P1 empty"<< endl;
        }
        
        else if(random == 1){
            if(P2 != NULL){
                sumA+=remove_front(P2);
                flag = 2;
            }
            else
                cout<< "P2 empty"<< endl;
        }

        if(P1 != NULL && P2 != NULL){

            if(flag == 1)
                sumB+=remove_front(P1);
            

            else if(flag == 2)
                sumB+=remove_front(P2);
        }

        else{

            if(P1 != NULL){
                sumB+=remove_front(P1);
                flag = 1;
            }
            else if(P2 != NULL){
                sumB+=remove_front(P2);
                flag = 2;
            }
        }
    
    }while(P1 != NULL || P2 != NULL);

    if(sumA > sumB)
        cout<< "A WON" << endl;
    else if(sumB > sumA)
        cout<< "B Won" << endl;
    else
        cout<< "Draw" << endl;
}


int main(){

    lptr L;
    int n;
    cin>>n;
    L = new node;
    L->data = n;
    L->next = NULL;
    cin>>n;

    while(n > 0){
        insert(L,n);
        cin>>n;
    }

    //-----------------list 2 --------------------
    lptr L1;
    cin>>n;
    L1 = new node;
    L1->data = n;
    L1->next = NULL;
    cin>>n;

    while(n > 0){
        insert(L1,n);
        cin>>n;
    }

    game(L, L1, 0, 0);
    cout<< endl;

    return 0;
}