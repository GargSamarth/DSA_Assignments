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

int max(bstptr T){

    if(T != NULL){
        if(T->rchild != NULL)
            return max(T->rchild);
        else
            return T->data;
    }
    else
        return -1;
}

int min(bstptr T){

    if(T != NULL){

        if(T->lchild != NULL)
            return min(T->lchild);
        else
            return T->data;
    }
    else
        return -1;
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

//printing ------------

void inorder(bstptr T){

    if(T != NULL){

        inorder(T->lchild);
        cout<< T->data << " ";
        inorder(T->rchild);

    }
    
    else
        return;
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

// end of all type of print functions

void range(bstptr T, int n){

    bstptr temp = find(T, n);

    if(temp->rchild != NULL && temp->lchild != NULL){
        int max_val = min(temp->rchild);
        int min_val = temp->lchild->data;
        cout<< "From " << min_val + 1 << " to " << max_val - 1 << endl;
    }

    else if(temp->rchild == NULL && temp->lchild != NULL){
        int min_val = temp->lchild->data;
    }

    else if(temp->rchild != NULL && temp->lchild == NULL){

    }

    else{

    }

}

void bst_not_satisfied(bstptr T){

    if(T != NULL){

        if(T->lchild != NULL){

            if(T->lchild->data < T->data){
                bst_not_satisfied(T->lchild);
                return;
            }

            else{
                cout<< "BST not satisfied at "<< T->data << endl;
                return;
            }
                
        }

        //else if
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
    inorder(BT);
    cout<< endl;
    queue q;
    q.r = q.f = -1;
    q.size = 20;
    enqueue(q,BT);
    cout<< endl;

    return 0;
}