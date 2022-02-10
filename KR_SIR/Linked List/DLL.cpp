#include <iostream>

using namespace std;

struct node{
    node *left;
    int data;
    node *right;
};

//defining node * to lptr
typedef node *lptr;

void insert(lptr P, int k){
    while(P->right != NULL)
        P = P->right;
    lptr T = new node;
    T->data = k;
    T->right = NULL;
    P->right = T;
    T->left = P;
}

void print(lptr P){
    if(P != NULL){
        cout<< P->data << " ";
        print(P->right);
    }
    return;
}

void add_front(lptr &P, int k){

    lptr T = new node;
    T->data = k;
    T->right = P;
    P->left = T;
    T->left = NULL;
    P = T;

}

void add_end(lptr P, int k){

    while(P->right != NULL)
        P = P->right;
    
    lptr T = new node;
    T->data = k;
    T->right = NULL;
    P->right = T;
    T->left = P;

}

int delete_front(lptr &P){
    lptr T = P;
    P = P->right;
    int k = T->data;
    T->right = NULL;
    P->left = NULL;
    delete T;

    return k;
}

int delete_end(lptr P){
    while(P->right->right != NULL)
        P = P->right;
    
    int k = P->right->data;
    P->right->left = NULL;
    P->right = NULL;

    return k;
}

void add_after(lptr P, int x, int k){
    while(P->data != x)
        P = P->right;

    lptr T = new node;
    T->data = k;
    T->right = P->right;
    P->right = T;
    T->left = P;
    T->right->left = T;
}

void add_before(lptr &P, int x, int k){
    if(P->data == x){
        lptr T = new node;
        T->data = k;
        T->right = P;
        P->left = T;
        T->left = NULL;
        P = T;
    }
    else{
        lptr T1 = P;
        while(T1->right->data != x)
            T1 = T1->right;
        
        lptr T = new node;
        T->data = k;
        T->right = T1->right;
        T1->right = T;
        T->left = T1;
        T->right->left = T;
    }
}

void delete_k(lptr &P, int k){

    lptr T3 = P;
    int flag = 0;

        lptr T2;
        
        while(T3->data != k && T3 != NULL){
            flag = 1;
            T2 = T3;
            T3 = T3->right;
        }

        if(flag == 1){
            T2->right = T3->right;
            T3->right->left = T2;
        }
        else{
            flag = 0;
            P = P->right;
            P->left = NULL;
        }
        T3->left = NULL;
        T3->right = NULL;
        delete T3;
}

int node_counter(lptr P){
    int count = 0;

    while(P != NULL){
        count++;
        P = P->right;
    }
    return count;
}

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int partition(lptr P, int l, int h ){
    int i = l+1, j = h-1;
    lptr T = P;
    i--;
    while(i--)
        T = T->right;

    lptr pivot = T;
    T = T->right;

    i = l+1;

    lptr last = P;

    while(j--)
        last = last->right;

    j = h-1;

    while(i < j){

        while(T->data < pivot->data){
            T = T->right;
            i++;
        }

        while(last->data > pivot->data){         
            last = last->left;
            j--;
        }

        if(i<j)
            swap(T->data,last->data);
    }

    if(pivot->data > last->data)
        swap(pivot->data,last->data);

    return j;
}

void QuickSort(lptr &P, int l, int h){
    int j;

    if(l < h){
        j = partition(P,l,h);
        QuickSort(P,l,j);
        QuickSort(P,j+1,h);
    }
}

int main(){
    lptr L;
    int n;
    cin>>n;
    L = new node;
    L->data = n;
    L->right = L->left = NULL;

    cin>>n;

    while(n > 0){
        insert(L,n);
        cin>>n;
    }
    
    print(L);
    cout<< endl;
    int k;

    cin>>k;
    add_front(L,k);
    print(L);
    cout<< endl;

    cin>>k;
    add_end(L,k);
    print(L);
    cout<< endl;

    int x,y;
    cin>>x>>y;
    add_before(L,y,x);
    print(L);
    cout<< endl;

    cin>>x>>y;
    add_after(L,y,x);
    print(L);
    cout<< endl;

    delete_front(L);
    print(L);
    cout<< endl;

    delete_end(L);
    print(L);
    cout<< endl;

    cin>>k;
    delete_k(L,k);
    print(L);
    cout<< endl;

    lptr P = L;
    QuickSort(L,0,node_counter(P));
    print(L);
    cout<< endl;

    return 0;
}