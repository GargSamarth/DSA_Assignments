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

void triplet(lptr P, int sum){
    lptr X = P;
    lptr Y = P->right;
    lptr last = P;

    while(last->right != NULL)
        last = last->right;

        lptr Z = last;

    while(X->data < last->data){

            if((2*X->data + Y->data + Z->data) < sum){

                while((Z->data > Y->data) && (2*X->data + Y->data + Z->data) < sum)
                    Y = Y->right;

            }

            else if((2*X->data + Y->data + Z->data) > sum){

                while((Z->data > Y->data) && (2*X->data + Y->data + Z->data) > sum)
                    Z = Z->left;

            }

            if((2*X->data + Y->data + Z->data) == sum && (X->data != Y->data) && (Y->data != Z->data) && (X->data != Z->data))
                cout<< X->data << " " << Y->data << " " << Z->data << endl;

            if(Y->right == Z){
                X = X->right;   Y = P;     Z = last;}
            else{
                Y = Y->right;   Z = Z->left;}
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
    int sum;
    cin>>sum;
    triplet(L,sum);

    return 0;
}