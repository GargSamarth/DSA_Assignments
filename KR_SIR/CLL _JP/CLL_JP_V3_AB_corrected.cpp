#include <iostream>

using namespace std;

struct CLL{
    char data;
    CLL *next;
};

typedef CLL *lptr;

lptr insert(int n){

    lptr C = new CLL;
    C->data = 'A';
    C->next = C;

    for(int i=1;i<n;i++){

        lptr T = new CLL;
        T->data = 'A';

        lptr temp = C;

        while(temp->next != C)
            temp = temp->next;

        temp->next = T;
        T->next = C;
    }
    return C;
}

void print(lptr CL){

    lptr temp = CL;
    do{
        cout<< temp->data;
        temp = temp->next;
    }while(CL != temp);
    cout<< endl;
}

void correct_them(lptr C, int i, int m, int n){

    if(n > 0){

        if(i > 1){
            correct_them(C->next ,i-1,m,n);
            return;
        }
        else{
            if(C->data != 'B')
                C->data = 'B';
                
            else{
                correct_them(C->next, m, m, n);
                return;
            }
        }

        correct_them(C->next ,m,m,n-1);
    }
}



int main(){
    
    int n = 30;
    lptr CL = insert(n);
    lptr C = CL;
    int m = 9;
    correct_them(C,m,m,15);
    print(CL);
    cout<< endl;
    
    return 0;
}