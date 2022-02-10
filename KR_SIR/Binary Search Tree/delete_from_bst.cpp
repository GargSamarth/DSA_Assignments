#include <iostream>

using namespace std;

struct bstnode {
    bstnode *lchild;
    int data;
    bstnode *rchild;
};

//define 
typedef bstnode *bstptr;

struct queue{
    int size;
    int f;
    int r;
    bstptr elements[50];
};

struct stack{
    int size;
    int top;
    bstptr A[50];
};

void push(stack &s, bstptr x){
    if(s.top == s.size-1)
        cout<< "Stack is full"<<endl;
    else
        s.A[++s.top] = x;
}

bstptr pop(stack &s){
    if( s.top == -1){
        cout<< "Stack is empty" << endl;
        return NULL;
    }
    else
        return s.A[s.top--];
}

void enqueue(queue &q, bstptr x){
    if((q.r+1)%q.size == q.f)
        cout<< "Queue is full"<<endl;

    else{   
        if(q.f == -1){
            q.f=0;  q.r=0;
        }
        else{
            q.r = (q.r+1)%q.size;
        }
        q.elements[q.r] = x;
    }
}

bstptr dequeue(queue &q){
    if(q.f == -1){
        cout<< "Queue is empty"<<endl;
        return NULL;
    }

    else{

        bstptr temp = q.elements[q.f];

        if(q.f == q.r){
             q.f = q.r = -1;
        }
        else
            q.f = (q.f+1)%q.size;

        return temp;
    }
}

void insert(bstptr &T, int k){

    if(T == NULL){
        T = new bstnode;
        T->data = k;
        T->lchild = NULL;
        T->rchild = NULL;
    }

    else{

        if(k < T->data)
            insert(T->lchild, k);

        else
            insert(T->rchild, k);
    }

}

bstptr find(bstptr T, int n){

    if(T != NULL){

        if(T->data == n){
            bstptr temp = T;
            return temp;
        }

        else if(T->data > n)
            return find(T->lchild, n);
        
        else
            return find(T->rchild,n);

    }

    else{

        bstptr temp = new bstnode;
        temp->data = -1;
        temp->rchild = NULL;
        temp->lchild = NULL;

        return temp;
    }

}

void delete_node(bstptr T){
    bstptr temp = T;
    while(temp->rchild != NULL){
        temp = temp->rchild;
    }
    if(temp->rchild == NULL && temp->lchild == NULL){

    }
    else{
        
    }

    while(i < (n-1)/2){
        
        if(HP->H[i] > HP->H[2*i + 1] && HP->H[i] > HP->H[2*i + 2]){
            int now = min_of_two(HP,2*i+1,2*i+2);
            swap(HP->H[i],HP->H[now]);
            i = now;
        }
        else if(HP->H[i] < HP->H[2*i + 1] && HP->H[i] > HP->H[2*i + 2]){
            swap(HP->H[i],HP->H[2*i + 2]);
            i = 2*i + 2;
        }
        else if(HP->H[i] > HP->H[2*i + 1] && HP->H[i] < HP->H[2*i + 2]){
            swap(HP->H[i],HP->H[2*i + 1]);
            i = 2*i + 1;
        }
        else    break;
    }
}

void delete_from_bst(bstptr T, int n){

}

void preorder(bstptr T){

    if(T != NULL){
        cout<< T->data << " ";
        preorder(T->lchild);
        preorder(T->rchild);
    }
}

void postorder(bstptr T){

    if(T != NULL){
        postorder(T->lchild);
        postorder(T->rchild);
        cout<< T->data << " ";
    }
}

int main(){
    bstptr BT = NULL;
    int n;

    cin>>n;

    while(n != -1){
        insert(BT, n);
        cin>>n;
    }

    queue q;
    q.r = q.f = -1;
    q.size = 20;
    enqueue(q,BT);
    cout<< endl;

    return 0;
}