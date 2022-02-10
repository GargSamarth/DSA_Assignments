#include <iostream>

using namespace std;

struct CLL{
    char data;
    CLL *next;
};

typedef CLL *lptr;

void create(lptr &CL){

    int A[15] = {1, 2, 3, 4, 10, 11, 13, 14, 15, 17, 20, 21, 25, 28, 29};
    lptr C = new CLL;
    C->data = 'A';
    C->next = C;
    CL = C;

    int j = 1;
    for(int i=1;i<30;i++){

        lptr T = new CLL;
        if(j != 15 && A[j] == i+1){
             T->data = 'A';
             j++;
        }
        else
            T->data = 'B';
        
        lptr temp = C;

        while(temp->next != C)
            temp = temp->next;

        temp->next = T;
        T->next = C;
    }
}

void print(lptr CL){

    lptr temp = CL;
    do{
        cout<< temp->data;
        temp = temp->next;
    }while(CL != temp);
    cout<< endl;
}

int main(){
    lptr CL;
    create(CL);
    print(CL);
    return 0;
}