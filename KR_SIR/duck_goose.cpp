#include <iostream>

using namespace std;

struct CLL{
    int data;
    CLL *next;
};

typedef CLL *lptr;

void insert(lptr &CL, int n){

    lptr C = new CLL;
    C->data = 1;
    C->next = C;
    CL = C;

    for(int i=1;i<n;i++){

        lptr T = new CLL;
        T->data = i+1;

        lptr temp = C;

        while(temp->next != C)
            temp = temp->next;

        temp->next = T;
        T->next = C;
    }

}

void remove_print(lptr &C, lptr temp, int i, int m, int n){

    if(n > 0){

        if(i > 1){
            remove_print(C->next->next,C,i-1,m,n);
            return;
        }
        else{
            temp->next = C->next;
            C->next = NULL;
            C = temp->next;
        }

        remove_print(C,C,m,m,n-1);
    }
    else{
        cout<< C->data << endl;
        return;
    }
}

int main(){
    lptr CL;
    int n;
    cin>>n;

    insert(CL,n);

    int m = 2;
    remove_print(CL,CL,m,m,n/2-1);
    
    return 0;
}