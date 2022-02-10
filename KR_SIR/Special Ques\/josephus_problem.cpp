#include <iostream>

using namespace std;

struct CLL{
    int data;
    CLL *next;
};

typedef CLL *lptr;

void insert(lptr C, int n){

    lptr T = new CLL;

    T->data = n;
    lptr temp = C;

    while(temp->next != C)
        temp = temp->next;

    temp->next = T;
    T->next = C;
}

void remove_print(lptr C, lptr temp, int i, int m, int n){

    if(n > 1){

        if(i > 1){
            remove_print(C->next,C,i-1,m,n);
            return;
        }
        else{
            cout<< C->data << " ";
            temp->next = C->next;
            C->next = NULL;
            C = temp->next;
        }

        remove_print(C,C,m,m,n-1);
    }
    else
        return;
}

int main(){
    lptr CL = new CLL;
    CL->next = CL;
    int n, x,temp;
    cin>>n;
    temp = n;
    temp--;
    cin>>x;
    CL->data = x;

    while(temp--){
        cin>>x;
        insert(CL, x);
    }
    int m;
    cin>>m;
    remove_print(CL,CL,m,m,n);
    cout<< endl;
    
    return 0;
}