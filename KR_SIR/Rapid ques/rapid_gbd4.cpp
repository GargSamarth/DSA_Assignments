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

void level_insert(queue q){

    int ch;
    bstptr samp1 = new bstnode;
    samp1->data = 0;
    samp1->lchild = samp1->rchild = NULL;
    enqueue(q,samp1);

    while(q.f != -1){

        bstptr temp = dequeue(q);

        while(temp->data != 0){

            if(temp->lchild == NULL){
                cin>>ch;
                if(ch == -11)
                    break;

                if(ch != -1){
                    bstptr K = new bstnode;
                    K->lchild = K->rchild = NULL;
                    K->data = ch;
                    temp->lchild = K;
                    enqueue(q,K);
                }
            }

            if(temp->rchild == NULL){
                cin>>ch;
                if(ch == -11)
                    break;

                if(ch != -1){
                    bstptr K = new bstnode;
                    K->lchild = K->rchild = NULL;
                    K->data = ch;
                    temp->rchild = K;
                    enqueue(q,K);
                }
            }
            
            temp = dequeue(q);
        }
        if(ch == -11)
            break;
            
        if(q.f != -1){
            bstptr samp = new bstnode;
            samp->data = '*';
            samp->lchild = samp->rchild = NULL;
            enqueue(q,samp);
        }
    }
}

void preorder(bstptr T){

    if(T != NULL){
        cout<< T->data << " ";
        preorder(T->lchild);
        preorder(T->rchild);
    }
}

int main(){

    int ch;
    cin>>ch;

    bstptr BT = new bstnode;
    BT->data = ch;
    BT->lchild = BT->rchild = NULL;

    queue q;
    q.f = q.r = -1;
    q.size = 20;
    enqueue(q,BT);
    level_insert(q);
    preorder(BT);
    cout<< endl;

    return 0;
}