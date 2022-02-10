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

void delete_nodes_in_ll_from_ll(lptr &P){
    lptr T = P;
    int count = node_counter(T), del = 0, allready_deleted=-1, flag = 0, pos = -1;
    T = P;
    
    while(T != NULL){

        if(count < T->data){
            T = T->next;
        }

        else{
            if(flag == 0)
                pos = T->data;
            else
                pos = allready_deleted;

            lptr temp1 = P;
            lptr temp2 = P;
            int lp = pos - del -1;

            while(lp--){
                temp2 = temp1;
                temp1 = temp1->next;
            }

            if(temp1 == T && temp1 == P){
                T = T->next;
                temp1->next = NULL;
                P = T;
                flag = 0;
            }
            else if(temp1 == T && temp1 != P){
                T = T->next;
                temp2->next = temp1->next;
                temp1->next = NULL;
                flag = 0;
            }
            else{
                temp2->next = temp1->next;
                temp1->next = NULL;
                if(temp1->data <= count){
                    allready_deleted = temp1->data;
                    flag = 1;
                }
                else{
                    flag = 0;
                    T = T->next;
                }
            }
            del++;
        }
    }
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
    delete_nodes_in_ll_from_ll(L);
    print(L);
    cout<< endl;
   

    return 0;
}