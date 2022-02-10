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

void construct(int a[],int n,int &pos,bstptr T,int min,int max)
{
	if(pos==n || a[pos]<min || a[pos]>max)
	return ;

	bstptr T1;

	if(a[pos]<T->data)
	{
		T1=new (bstnode);
		T1->data=a[pos++];
		T1->lchild=NULL;
		T1->rchild=NULL;
		T->lchild=T1;
		construct(a,n,pos,T->lchild,min,T->data-1);        
	}

	if(a[pos] > T->data)
	{
		T1=new (bstnode);
		T1->data=a[pos++];
		T1->lchild=NULL;
		T1->rchild=NULL;
		T->rchild=T1;
		construct(a,n,pos,T->rchild,T->data+1,max);
	}
}

void preorder(bstptr T){

    if(T != NULL){
        cout<< T->data << " ";
        preorder(T->lchild);
        preorder(T->rchild);
    }
}


void bst_not_satisfied(bstptr T, int min, int max, queue &q){
    
    if(T != NULL){
        if(T->data > max || T->data < min){
            enqueue(q, T);
            cout<< min << "  <  " << T->data << "  <  " << max << "  ,  ";
        }
        bst_not_satisfied(T->lchild, min, T->data, q);
        bst_not_satisfied(T->rchild, T->data , max, q);
    }
    else{
        return;
    }
}

void dead_ends(bstptr T, int min, int max, queue &q){
    
    if(T != NULL){
        if((max-min) == 1){
            cout<< T->data << endl;
            enqueue(q, T);
        }
        else{
            cout<< "min - "<< min << " max - " << max << endl;
        }
        dead_ends(T->lchild, min, T->data-1, q);
        dead_ends(T->rchild, T->data+1 , max, q);
    }
}

void swap(int &one, int &two){
    int temp = one;
    one = two;
    two = temp;
}

void swap_two(bstptr T, int min, int max, bstptr &one, bstptr &two){
    
    if(T != NULL){
        if(T->data > max || T->data < min){
            if(one == NULL)
                one = T;
            else{
                two = T;
                swap(one->data, two->data);
                return;
            }
        }
        swap_two(T->lchild, min, T->data, one,two);
        swap_two(T->rchild, T->data , max, one,two);
    }
    else{
        return;
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

    queue q1;
    q1.f = q1.r = -1;
    q1.size = 20;
    bst_not_satisfied(BT, -9654,9645,q1);
    cout<< endl;

    while(q1.f != -1)
        cout<< dequeue(q1)->data << " ";
    cout<< endl;

    q.f = q.r = -1;
    dead_ends(BT,-9654,9645,q);
    cout<< endl;

    while(q.f != -1)
        cout<< dequeue(q)->data << " ";
    cout<< endl;

    bstptr one = NULL, two = NULL;
    swap_two(BT,-9654,9654,one,two);
    cout<< endl;
    preorder(BT);
    cout<< endl;

}