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


void remove_repeated_elements(lptr P){

    if(P->next != NULL){
        if(P->data == P->next->data){
            lptr T = new node;
            T = P;
            T = T->next;
            P->next = T->next;
            T->next = NULL;
            delete T;

            remove_repeated_elements(P);
        }
        else
            remove_repeated_elements(P->next);
    }
    return;
}

void u_remove_repeated_elements(lptr P){

    while(P->next != NULL){

        lptr T1;
        T1 = P;

        while(T1->next != NULL){
            if(P->data == T1->next->data){
                lptr T = new node;
                T = T1;
                T = T->next;
                T1->next = T->next;
                T->next = NULL;
                delete T;
            }
            else
                T1 = T1->next;
        }
            P = P->next;
    }
    
    return;
}

int palindrome(lptr P){

    lptr last = new node;
    lptr T = new node;
    T = P;
    int count = node_counter(T);

    int temp = 0, temp1 = count/2;
    int flag = 0;

    while(temp1--){

        temp = count-1;

        last = P;

        while(temp--)
            last = last->next;
        
        if(last->data != P->data){
            flag = 1;
            break;
        }

        count-=2;
        P = P->next;
    }

    if(flag == 1)
        return 0;
    else
        return 1;

}

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void kth_swap(lptr P, int k){

    lptr T;
    T = P;
    int count = node_counter(T);
    int first = k, last = count - k;
    int temp = 0, temp1 = count/2;
    int flag = 0;

    first--;
    while(first--){
        P = P->next;
    }

    while(last--)
        T = T->next;

    swap(P->data, T->data);
}

void reverse_a_ll(lptr &P){

    lptr T1 = new node;
    lptr T2 = new node;
    lptr T = new node;
    T = P;

    int count = node_counter(T) - 1;
    
    int temp = count;
    T = P;

    while(temp--)
        T = T->next;

    while(count >= 0){

        temp = count;
        T1 = NULL;
        T2 = P;

        while(temp--){
            T1 = T2;
            T2 = T2->next;
        }
        T2->next = T1;

        count--;
    }

    P = T;
}

void u_even_odd_segregation(lptr &P){
    lptr ptr = new node;
    lptr T = new node;
    T = P;
    
    if(P->data%2 == 0)
        ptr = P;

    while(T != NULL){

        if(T->data % 2 == 0 && T != NULL)
            T = T->next;
        
        else if(T->data % 2 != 0 && T != NULL){

            lptr first = new node;
            first = T;
            lptr move = new node;
            

            while(T != NULL && T->data %2 != 0){
                move = T;
                T = T->next;
            }

            if(T != NULL){
                move->next = T->next;
                T->next = first;

                if(P != first)
                    P->next = T;
                else if(P == first)
                    ptr = T;
                
                P = T;
            }
        }
    
    }
    P = ptr;

}

bool discovered(lptr P, int k){
    while(P!=NULL){
        if(P->data == k)
            return true;
        P = P->next;
    }
    return false;
}

void delete_last_occurence(lptr P){

    lptr T1 = new node;
    lptr storage = new node;

    while(P->next != NULL){

        T1 = P;
        lptr T = new node;
        int flag = 0;

        while(T1->next != NULL){

            if(P->data == T1->next->data){
                flag = 1;
                T = T1;
            }
                T1 = T1->next;
        }

        if(flag == 1){
            T1 = T;
            
            T = T->next;
            
            T1->next = T->next;
            insert(storage,T->data);
            T->next = NULL;
            delete T;
        }

        P = P->next;

        if(discovered(storage, P->data)){
            while(discovered(storage, P->data) && P->next != NULL)
                P = P->next;
        }
    }

    return;      
}

void insertion_sort(lptr &P){
    
    lptr T1 = new node;
    lptr first = new node;
    lptr move = new node;
    lptr last = new node;

    first = last = move = P;

    while(last->next != NULL){
        T1 = last;
        T1 = T1->next;

        if(T1->data < last->data){
            int flag = 0;
            lptr T = new node;
            while(T1->data > move->data){
                flag = 1;
                T = move;
                move = move->next;
            }
            last->next = T1->next;
            T1->next = move;

            if(flag == 0)
                first = T1;
            else if(flag == 1){
                T->next = T1;
            }
        }

        else{
            last = last->next;
        }
        move = first;

    }
    P = first;
}

int one_into_another(lptr P1, lptr P2){
    
    int count = node_counter(P2);
    lptr T1 = new node;
    lptr T2 = new node;
    T1 = P1;
    int flag = -1;
    lptr store = new node;

    while(T1 != NULL){
        flag = -1;
        T2 = P2;
        
        while(T1 != NULL && T2->data != T1->data){
            T1 = T1->next;
        }

        if(T1 != NULL && T2->data == T1->data){
            flag = 0;
            store = T1;
        }

        int temp = count;

        while(T1 != NULL && temp>0){

            if(T2->data != T1->data){
                flag = 1;
                break;
            }
            T1 = T1->next;
            T2 = T2->next;
            temp--;
        }

        if(flag == 1)
            T1 = store->next;
        
        else if(flag == 0 && temp == 0)
            return 1;

        else
            break;;
    }
    return 0;
}

void merge_list(lptr P1, lptr P2, lptr &P3){

    lptr L3 = new node;
    L3->next = NULL;
    while(P1 != NULL && P2 != NULL){
        insert(L3,P1->data);
        insert(L3,P2->data);
        P1 = P1->next;
        P2 = P2->next;
    }

    while(P1 != NULL){
        insert(L3,P1->data);
        P1 = P1->next;
    }

    while(P2 != NULL){
        insert(L3,P2->data);
        P2 = P2->next;
    }

    L3 = L3->next;
    P3 = L3;
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
    //cout<< endl;
    
    cout<< palindrome(L) << endl;
    delete L;

    cin>>n;
    L = new node;
    L->data = n;
    L->next = NULL;
    cin>>n;

    while(n > 0){
        insert(L,n);
        cin>>n;
    }

    remove_repeated_elements(L);
    print(L);
    cout<< endl;

    delete L;
    cin>>n;
    L = new node;
    L->data = n;
    L->next = NULL;
    cin>>n;

    while(n > 0){
        insert(L,n);
        cin>>n;
    }
   
    u_remove_repeated_elements(L);
    print(L);
    cout<< endl;

    delete L;
    cin>>n;
    L = new node;
    L->data = n;
    L->next = NULL;
    cin>>n;

    while(n > 0){
        insert(L,n);
        cin>>n;
    }

    delete_last_occurence(L);
    print(L);
    cout<< endl;
    
    delete L;
    cin>>n;
    L = new node;
    L->data = n;
    L->next = NULL;
    cin>>n;

    while(n > 0){
        insert(L,n);
        cin>>n;
    }

    u_even_odd_segregation(L);
    print(L);
    cout<< endl;

    delete L;
    cin>>n;
    L = new node;
    L->data = n;
    L->next = NULL;
    cin>>n;

    while(n > 0){
        insert(L,n);
        cin>>n;
    }

    insertion_sort(L);
    print(L);
    cout<< endl;

    delete L;
    cin>>n;
    L = new node;
    L->data = n;
    L->next = NULL;
    cin>>n;

    while(n > 0){
        insert(L,n);
        cin>>n;
    }

    reverse_a_ll(L);
    print(L);
    cout<< endl;

    delete L;
    cin>>n;
    L = new node;
    L->data = n;
    L->next = NULL;
    cin>>n;

    while(n > 0){
        insert(L,n);
        cin>>n;
    }

    int k;
    cin>>k;
    kth_swap(L,k);
    print(L);
    cout<< endl;

    delete L;
    cin>>n;
    L = new node;
    L->data = n;
    L->next = NULL;
    cin>>n;

    while(n > 0){
        insert(L,n);
        cin>>n;
    }

    lptr L2 = new node;
    cin>>n;
    L2 = new node;
    L2->data = n;
    L2->next = NULL;
    cin>>n;

    while(n > 0){
        insert(L2,n);
        cin>>n;
    }

    cout<< one_into_another(L,L2)<<endl;

    delete L;   delete L2;
    cin>>n;
    L = new node;
    L->data = n;
    L->next = NULL;
    cin>>n;

    while(n > 0){
        insert(L,n);
        cin>>n;
    }

    cin>>n;
    L2 = new node;
    L2->data = n;
    L2->next = NULL;
    cin>>n;

    while(n > 0){
        insert(L2,n);
        cin>>n;
    }

    lptr L3 = new node;
    merge_list(L,L2,L3);
    print(L3);
    cout<< endl;

    return 0;
}