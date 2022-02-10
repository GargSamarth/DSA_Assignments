#include <iostream>

using namespace std;

struct bstnode {
    bstnode *lchild;
    int d;
    int *data;
    int ino;
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

void insert(bstptr &T, int *k, int d, int i){

    if(T == NULL){
        T = new bstnode;
        T->data = new int[d];
        T->d = d;
        for(int j=0;j<d;j++)
            T->data[j] = k[j];

        T->lchild = NULL;
        T->rchild = NULL;
    }

    else{

        if(k[i] < T->data[i])
            insert(T->lchild, k,d,(i+1)%d);

        else
            insert(T->rchild, k,d,(i+1)%d);
    }

}

void preorder(bstptr T, int d){

    if(T != NULL){
        cout<<"(";
        for(int i=0;i<d;i++){
            cout<< T->data[i];
            if(i != (d-1))
                cout<< ",";
        }cout<< ")  ";

        preorder(T->lchild,d);
        preorder(T->rchild,d);
    }
}

void inorder_numbering(bstptr T, int &i){
    if(T != NULL){
        inorder_numbering(T->lchild,i);
        i++;
        T->ino = i;
        inorder_numbering(T->rchild,i);
    }
}

void full_tree(queue q, int d){

    bstptr dot = new bstnode;
    dot->data = new int[d];
    for(int z=0;z<d;z++)
        dot->data[z] = -1;
    dot->lchild = dot->rchild = NULL;
    enqueue(q,dot);

    int *stem = new int[10];
    int pos = 0;

    while(q.f != -1){
        
        bstptr temp = dequeue(q);
        int count = 0;

        while(temp->data[0] != -1){
            count = temp->ino - count;
            int temp1 = count;
            while(temp1--)
                cout<< " ";
            cout<<"(";
            for(int l=0;l<d;l++){
                cout<< temp->data[l];
                if(l != d-1)
                    cout<< ",";
            }
            cout<<") ";
            
            if(temp->lchild != NULL){
                enqueue(q,temp->lchild);
                stem[pos++] = 1;
                stem[pos++] = temp->lchild->ino;
            }
            else
                stem[pos++] = 0;

            if(temp->rchild != NULL){
                enqueue(q,temp->rchild);
                stem[pos++] = 2;
                stem[pos++] = temp->rchild->ino;
            }
            else
                stem[pos++] = 0;

            temp = dequeue(q);
        }
        cout<< endl;
        int count1 = 0;

        for(int i=0;i<pos;i++){

            if(stem[i] == 1){
                count1 = stem[i+1] - count1 + 2*d + 1;
                int t = count1;
                while(t--)
                    cout<< " ";
                cout<< "/";
                i++;
            }

            else if(stem[i] == 2){
                count1 = stem[i+1] - count1 + 2*d + 2;
                int t = count1;
                while(t--)
                    cout<< " ";
                cout<< "\\";
                i++;
            }
        }
        delete stem;
        int *stem = new int[10];
        pos = 0;

        cout<< endl;
        if(q.f != -1)
            enqueue(q,dot);
    }
}

int main(){
    bstptr BT = NULL;
    int *n,d,flag = 0;

    //d for Kd ------------
    cin>>d;
    n = new int[d];

    for(int j=0;j<d;j++)
        cin>>n[j];

    while(n[0] != -1){
        insert(BT,n,d,0);

        for(int j=0;j<d;j++){
            cin>>n[j];
            if(n[0] == -1){
                flag = 1;
                break;
            }
        }

        if(flag == 1)
            break;
    }

    int i=0;
    inorder_numbering(BT,i);

    preorder(BT,d);
    cout<< endl;

    cout<< "------------------------------------"<< endl;
    queue q;
    q.f = q.r = -1;
    q.size = 20;
    enqueue(q,BT);

    full_tree(q,d);
    cout<< endl;

    return 0;
}