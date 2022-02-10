#include <iostream>

using namespace std;

struct CLL{

    int data;
    CLL *next;
    int tag;

};

//Type define
typedef CLL *lptr;

void insert(lptr C, int n){
    lptr temp = C;
    lptr T = new CLL;

    if(temp->next == NULL){
        T->next = C;
        T->data = n;
        C->next = T;
        T->tag = 1;
    }

    else{

        lptr temp2 = C;
        while(temp->next != C)
            temp = temp->next;

        T->next = C;
        T->data = n;
        temp->next = T;
        T->tag = 1;

    }
}

void apply(lptr C, int n, int count){
    lptr temp = C;

    do{

        if(temp->data == n){
            temp->tag = count;
        }

        temp = temp->next;

    }while(temp != C);
}

void edit_tag(lptr L){

    lptr C = L;
    

    do{
        int count = 0;
        lptr temp = C;

        do{
            if(temp->data == C->data)
                count++;

            temp = temp->next;

        }while(temp != C);

        apply(L,C->data,count);
        C = C->next;

    }while(C != L);
    
}

void circular_print(lptr C){

    edit_tag(C);
    lptr L = C;
    do{

        if(C->tag > 1){

            int repeate = C->tag;
            lptr temp = C;

            while(repeate--){

                cout<< temp->data << " ";
                
                do{

                    temp = temp->next;
                    cout<< temp->data << " ";
                    
                }while(temp->data != C->data);

                temp->tag = 1;
                cout<< endl;
            }
        }

        C = C->next;
    }while(C != L);
}

void circular_print2(lptr C, int count, int repeate, lptr temp, int flag){
    
    if(count > 0){

        if(C->tag > 1){

            if(flag == 1){
                circular_print2(C, count, C->tag, C, 2);
            }

            if(repeate > 0){

                if(flag == 2){
                    cout<< temp->data << " ";
                    temp = temp->next;
                }

                if(temp->data != C->data){

                        cout<< temp->data << " ";
                    
                    circular_print2(C, count, repeate, temp->next,3);
                }
                cout<< temp->data << " ";
                cout<< endl;
                temp->tag = 1;
                circular_print2(C, count,repeate-1, temp,2);
            }
            circular_print2(C->next, count, repeate, temp,1);
        }
        circular_print2(C, count-1, repeate, temp,1);
    }
}

int main(){
    lptr CL = new CLL;
    CL->next = NULL;
    CL->tag = 1;

    int n;
    cin>>n;
    CL->data = n;

    cin>>n;

    while(n != -1){
        insert(CL,n);
        cin>>n;
    }
    edit_tag(CL);
    circular_print2(CL,11,0,NULL,1);
    cout<< endl;

    return 0;
}