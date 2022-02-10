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

int node_counter(lptr P){
    int count=0;
    
    while(P != NULL){
        P = P->next;
        count++;
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
        T = T->next;

    int pivot = T->data;
    T = T->next;

    i = l+1;

    int temp;
    lptr last = P;
    while(j--)
    last = last->next;

    j = h-1;

    while(i < j){

        while(T->data < pivot){
            T = T->next;
            i++;
        }

        while(last != NULL && last->data > pivot){
            temp = j-1;
            last = P;
            while(last != NULL && temp>0){
                last = last->next;
                temp--;
            }
            j--;
        }

        if(i<j)
            swap(T->data,last->data);
    }

    if(P->data > last->data)
        swap(P->data , last->data);

    return j;
}

void sort(lptr &P,int l, int h){

    if(l < h){
        int j = partition(P,l,h);
        sort(P,l,j);
        sort(P,j+1,h);
    }
    else
        return;
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
    lptr T = L;
    int k = node_counter(T);
    cout<< endl;
    sort(L,0,k);
    print(L);

    return 0;
}