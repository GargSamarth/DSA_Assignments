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

// void insert(lptr P, int k){
//     if(P->next != NULL)
//         insert(P->next,k);
//     else{
//         lptr T = new node;
//         T->data = k;
//         T->next = NULL;
//         P->next = T;
//     }
// }

void print(lptr P){
    if(P != NULL){
        cout<< P->data << " ";
        print(P->next);
    }
    return;
}

int find(lptr P, int k){
    while( P != NULL){

        if(P->data == k)
            return 1;
        P = P->next;
    }
    return 0;
}

void add_front(lptr &P, int k){
    lptr T = new node;
    T->data = k;
    T->next = P;
    P = T;
}

void add_back(lptr P, int k){
    while(P->next != NULL)
        P = P->next;
    
    lptr T = new node;
    T->data = k;
    T->next = NULL;
    P->next = T;
}

int remove_front(lptr &P){
    lptr T = P;
    //T = P;
    P = P->next;
    int k = T->data;
    T->next = NULL;
    delete T;
    return k;
}

int remove_back(lptr P){
    while(P->next->next != NULL)
        P = P->next;
    
    int k = P->next->data;
    P->next = NULL;
    return k;
}

void insert_after(lptr P, int k){
    while(P->data != k)
        P = P->next;
    lptr T = new node;
    T->data = k;
    T->next = P->next;
    P->next = T;
}

void insert_before(lptr P, int k){
    while(P->next->data != k)
        P = P->next;
    
    lptr T = new node;
    T->data = k;
    T->next = P->next;
    P->next = T;
}

void rev_print(lptr P){
    if(P != NULL){
        rev_print(P->next);
        cout<< P->data<< " ";
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

int min_node(lptr P){
    lptr T = new node;
    T = P;
    int min = T->data;

    while(T != NULL){
        if(min > T->data)
            min = T->data;
        T = T->next;
    } 
    return min;
}

int max_node(lptr P){
    lptr T = new node;
    T = P;
    int max = T->data;

    while(T != NULL){
        if(max < T->data)
            max = T->data;
        T = T->next;
    } 
    return max;
}

void print_odd(lptr P){
    while(P != NULL){
        if(P->data %2 != 0)
         cout<< P->data << " ";
        P = P->next;
    }
    cout<< endl;
}

void print_even(lptr P){

    while(P != NULL){
        if(P->data %2 == 0)
         cout<< P->data << " ";
        P = P->next;
    }
    cout<< endl;
}

int middle_node_data(lptr P){
    int num = node_counter(P);
    num = num/2;

    while(num--){
        P = P->next;
    }
    return P->data;
}


void remove_repeated_elements(lptr P){
    lptr T = new node;

    while(P->next != NULL){
        T = P;
        while(T->next != NULL){
            if(T->next->data = P->data){
                lptr T1 = new node;
                T1 = T->next;
                T->next = T1->next;
                T1->next = NULL;
                delete T1;
            }
            else{
                if(T->next != NULL)
                    T = T->next;
            }
        }
        if(P->next != NULL)
            P = P->next;
    }
}

void delete_k(lptr &P, int k){

    lptr T = new node;
    T = P;
    int flag = 0;
    while(T != NULL){

    lptr T2 = new node;
    lptr T3 = new node;
    T3 = T;
    
    while(T3->data != k && T3 != NULL){
        flag = 1;
        T2 = T3;
        T3 = T3->next;
    }

    if(flag == 1){
        T2->next = T3->next;
    }
    else{
        flag = 0;
        P = P->next;
    }
    T = T3->next;
    T3->next = NULL;
    }
      
}

void delete_min(lptr &P){
    
    lptr T = new node;
    T = P;
    lptr T2 = new node;
    int flag = 0;
    int k = min_node(T);
    while(T->data != k){
        flag = 1;
        T2 = T;
        T = T->next;
    }

    if(flag == 1){
        T2->next = T->next;
    }
    else{
        P = P->next;
    }
    T->next = NULL;
    delete T;    
}

void delete_max(lptr &P){
    lptr T = new node;
    T = P;
    lptr T2 = new node;
    int flag = 0;
    int k = max_node(T);
    while(T->data != k){
        flag = 1;
        T2 = T;
        T = T->next;
    }

    if(flag == 1){
        T2->next = T->next;
    }
    else{
        P = P->next;
    }
    T->next = NULL;
    delete T;    
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
    cout<< endl;
    print(L);
    cout<< endl;
    cin>>n;
    add_front(L,n);
    print(L);
    cout<< endl<< remove_front(L) << endl;
    print(L);
    cout<< endl;

    return 0;
}