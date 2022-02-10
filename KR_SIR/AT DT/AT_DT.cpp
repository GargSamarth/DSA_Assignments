#include <iostream>

using namespace std;

struct btnode{
    btnode *rc;
    int data,AT,DT,VD;
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
        T->AT = T->DT = T->VD = -1;
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

void assign_AT_DT(btptr T, int &count){
    if(T != NULL){
        if(T->AT == -1)
            T->AT = count++;
        assign_AT_DT(T->lc,count);
        assign_AT_DT(T->rc,count);
        if(T->DT == -1)
            T->DT = count++;
    }
}

void assign_HD_VD(btptr T, int count, int *Hash){
    if(T != NULL){
        if(T->VD == -1)
            T->VD = count;
        Hash[5+count]+=T->data;
        assign_HD_VD(T->lc,count-1,Hash);
        assign_HD_VD(T->rc,count+1,Hash);
    }
}

void leaf_nodes(btptr T){
    if(T != NULL){
        if((T->DT - T->AT) == 1)
            cout<< T->data << " ";
        leaf_nodes(T->lc);
        leaf_nodes(T->rc);
    }
}

void cousins(btptr T){

}

void lenght_of_subtree(btptr T){
    if(T != NULL){
        cout<< "Length of the subtree from "<< T->data <<" is: "<< (T->DT - T->AT - 1)/2 + 1 << endl;
        lenght_of_subtree(T->lc);
        lenght_of_subtree(T->rc);
    }
}

int main(){

    int ch;
    btptr BT = NULL;

    cin>> ch;
    if(ch != 0)
        insert(BT, ch);
    int count = 0;
    assign_AT_DT(BT,count);
    lenght_of_subtree(BT);
    cout<< endl;

    int *Hash = new int[20];
    assign_HD_VD(BT,0,Hash);

    cout<< " Vertical sum:- "<< endl;
    for(int i=0;i<20;i++){
        if(Hash[i] != 0)
            cout<< Hash[i] << " ";
    }
    cout<< endl;
    return 0;
}