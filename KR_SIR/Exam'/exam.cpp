#include <iostream>

using namespace std;

struct node {
    int idata;
    node* next;
};

struct LL {
    node* data;
    LL* next;
};

struct order{
    order* next;
    int data;
    int frequency;
};

//defining node * to lptr and LL * to llptr

typedef node* lptr;
typedef LL* llptr;
typedef order* optr;

void insert_order(optr P, int data, int freq){
    
    while (P->next != NULL)
        P = P->next;

    optr T = new order;
    T->data = data;
    T->frequency = freq;
    T->next = NULL;
    P->next = T;
    
}

void optr_print(optr P){
    
    if (P != NULL) {
        cout << P->data << P->frequency << endl ;
        optr_print(P->next);
    }
    return;
}

void insert(lptr P, int k) {

    while (P->next != NULL)
        P = P->next;

    lptr T = new node;
    T->idata = k;
    T->next = NULL;
    P->next = T;
}

void print(lptr P) {
    if (P != NULL) {
        cout << P->idata << " " ;
        print(P->next);
    }
    return;
}

void insert_ll(llptr P, int n) {

    while (n--) {

        llptr T = new LL;

        lptr L;
        int n;
        cin >> n;

        L = new node;
        L->idata = n;
        L->next = NULL;

        cin >> n;

        while (n != -1) {
            insert(L, n);
            cin >> n;
        }

        T->data = L;
        T->next = NULL;
        llptr temp = P;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = T;
    }
}

void print_ll(llptr P) {
    if (P != NULL) {
        print(P->data);
        print_ll(P->next);
    }
    return;
}

void declare(lptr A[]) {
    for (int i = 0; i < 10; i++) {
        A[i] = new node;
        A[i]->next = NULL;
    }
}

void frequency(llptr P, optr L) {

    lptr check[5][10];

    int i = 0;

    llptr T = P;

    while (T!= NULL) {
        lptr temp = T->data;
        declare(check[i]);

        while (temp != NULL) {

            check[i][temp->idata - 1]->next = temp;
            temp = temp->next;

        }
        T = T->next;
        i++;
    }

    T = P;

    lptr temp = T->data;
    int count = 0;
    
    while(T != NULL){
        
        temp = T->data;
        while (temp != NULL) {

            for (int j = 0; j < i; j++) {
                if (check[j][temp->idata - 1]->next != NULL)
                    count++;
            }
    
            
                insert_order(L, temp->idata, count);
            
            temp = temp->next;
            count = 0;
        }
        T = T->next;
        
    }

  
}


int main() {
    llptr new_L;
    new_L = new LL;
    new_L->data = NULL;
    new_L->next = NULL;
    int n;
    cin>>n;
    

    insert_ll(new_L, n);
    new_L = new_L->next;

    optr L3 = new order;
    L3->next = NULL;
    frequency(new_L, L3);
    L3 = L3->next;
    optr_print(L3);

    cout << endl;


    return 0;
}