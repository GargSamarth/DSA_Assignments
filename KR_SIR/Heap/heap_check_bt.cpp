#include <iostream>

using namespace std;

struct Heap{
    int H[30],size;
};

typedef Heap *hptr;

struct btnode{
    btnode *rc;
    int data,num;
    btnode *lc;
};

typedef btnode *btptr;

struct queue{
    int size,f,r;
    btptr elements[50];
};
void enqueue(queue &q, btptr x){
    if((q.r+1)%q.size == q.f) cout<< "Queue is full"<<endl;
    else{   
        if(q.f == -1){
            q.f=0;  q.r=0;
        }
        else q.r = (q.r+1)%q.size;
        q.elements[q.r] = x;}
}
btptr dequeue(queue &q){
    if(q.f == -1){
        cout<< "Queue is empty"<<endl;
        return NULL;}
    else{
        btptr temp = q.elements[q.f];
        if(q.f == q.r) q.f = q.r = -1;
        else q.f = (q.f+1)%q.size;
        return temp;}
}
void insert(btptr &T, int k){
    if(T == NULL){
        T = new btnode;
        T->data = k;
        T->num = -1;
        T->lc = T->rc = NULL;
    } cin>>k;
    if(k != 0){
        insert(T->lc,k);
        k = 0;
    } 
    if(k == 0){
        cin>>k;
        if(k != 0) insert(T->rc, k);
    }
}

void level_order(queue q){

    btptr dot = new btnode;
    dot->data = -1;
    dot->lc = dot->rc = NULL;
    int A[30], s=0,flag =0,count = 0;
    A[s++] = 0;

    while(q.f != -1){

        enqueue(q,dot);
        btptr temp = dequeue(q);

        while(temp->data != -1){
            int r = A[s];
            cout<< temp->data<< " ";
            
            if(temp->lc != NULL){
                count++;
                if(temp->lc->data > temp->data && (2*r+1) == count){
                    enqueue(q,temp->lc);
                    A[s++]=2*r+1;
                }
                else{
                    flag = 1;
                    break;
                }
            }
            if(temp->rc != NULL){
                count++;
                if(temp->lc->data > temp->data && (2*r+2) == count){
                    enqueue(q,temp->rc);
                    A[s++]=2*r+2;
                }
                else{
                    flag = 1;
                    break;
                }
            }
            temp = dequeue(q);
        }
    }
}

void numbering(btptr T){
    if(T != NULL){
        int temp = T->num;
        if(T->lc != NULL)
            T->lc->num = temp*2 + 1;
        if(T->rc != NULL)
            T->rc->num = temp*2 + 2;
        numbering(T->lc);
        numbering(T->rc);
    }
}

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void construct_min(hptr &HP, int n){
        HP->H[HP->size++] = n;
        int i = HP->size-1;

        while(i > 0){
            if(HP->H[i] > HP->H[(i-1)/2]){
                break;
            }
            else{
                swap(HP->H[i],HP->H[(i-1)/2]);
            }
            i = (i-1)/2;
        }
}

void check_completed(btptr T, bool &ans, int &flag){
    if(T != NULL){
        if(T->lc != NULL){
            if(T->rc == NULL){
                ans = false;
                return;
            }
        }
        else{
            flag = 1;
        }
        check_completed(T->lc, ans,flag);
        check_completed(T->rc, ans,flag);
    }
}

bool check_heap_bt(btptr T){
    if(T != NULL){
        if(T->lc != NULL && T->data < T->lc->data){
            if(T->rc != NULL && T->data < T->rc->data)
                return check_heap_bt(T->lc);
            else
                return false;
        }
        else
            return false;
        check_heap_bt(T->lc);
        check_heap_bt(T->rc);
    }
    else return true; 
}

bool ck(btptr T){
    if(check_heap_bt(T)){

    }
}

void print(hptr HP){
    int n = HP->size;
    int i = 0;

    while(i < n){
        cout<< HP->H[i++] << " ";
    }
}

int main(){

    int ch;
    btptr BT = NULL;
    cout<< "Enter the BT to be check for a heap or not (remember 0 is the NULL condition): "<< endl;

    cin>> ch;
    if(ch != 0)
        insert(BT, ch);
    

    return 0;
}