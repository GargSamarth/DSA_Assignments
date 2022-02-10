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

void count(bstptr T, int &count_val){

    if(T != NULL){
        count_val++;
        count(T->lchild, count_val);
        count(T->rchild, count_val);
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

        return NULL;
    }

}

bool check_discovered(queue q, bstptr ck){

        queue temp;
        temp.f = temp.r = -1;
        temp.size = 10;

    while(q.f != -1){
        bstptr x = dequeue(q);
        enqueue(temp,x);

        if(ck->data == x->data){

            while(temp.f != -1)
                enqueue(q,dequeue(temp));

            return true;
        }

    }

    while(temp.f != -1)
        enqueue(q,dequeue(temp));

    return false;
}

void find_one(queue q, queue &dc, int &num){

    bstptr T1;

    stack print;
    print.top = -1;
    print.size = 20;

    do{
        T1 = dequeue(q);
        push(print,T1);

        if(T1->rchild != NULL && T1->lchild != NULL){

            if(!check_discovered(dc, T1->lchild)){
                enqueue(q,T1->lchild);
            }

            else if(!check_discovered(dc, T1->rchild)){
                enqueue(q,T1->rchild);
            }

            else{
                bstptr find = pop(print);
                num = find->data;
                
                if(!check_discovered(dc,find)){
                    enqueue(dc,find);
                    enqueue(q,find);
                }
                break;
            }
        }

        else if(T1->rchild != NULL && T1->lchild == NULL){

            if(!check_discovered(dc, T1->rchild)){
                enqueue(q,T1->rchild);
            }

            else{
                bstptr find = pop(print);
                num = find->data;
                
                if(!check_discovered(dc,find)){
                    enqueue(dc,find);
                    enqueue(q,find);
                }
                break;
            }
        }

        else if(T1->rchild == NULL && T1->lchild != NULL){

            if(!check_discovered(dc, T1->lchild)){
                enqueue(q,T1->lchild);
            }

            else{
                bstptr find = pop(print);
                num = find->data;
                
                if(!check_discovered(dc,find)){
                    enqueue(dc,find);
                    enqueue(q,find);
                }
                break;
            }
        }

        else{

            enqueue(dc,T1);

            bstptr find = pop(print);
                num = find->data;
                
                if(!check_discovered(dc,find)){
                    enqueue(dc,find);
                    enqueue(q,find);
                }
                break;
        }

    }while(q.f != -1);    
}

void sum_two_three(queue q1, queue q2, int count1, int count2, bstptr T1, bstptr T2){

    queue dc1;
    dc1.r = dc1.f = -1;
    dc1.size = 20;

    int num1 = 0, num2 = 0, temp = count2, temp2 = count1;

    while(temp2--){

        find_one(q1,dc1,num1);
        queue dc2;
        dc2.r = dc2.f = -1;
        dc2.size = 20;

        while(temp--){
            find_one(q2,dc2,num2);

            bstptr fd = find(T1,num1+num2);

            if(fd == NULL){
                fd = find(T2,num1+num2);
            }
            if(fd != NULL)
                cout<< " ( "<<num1<< " , " << num2 << " , " << fd->data << " ) ";
        }
        temp = count2;
    }
 
}

int main(){
    bstptr BT1 = NULL;
    int n;
    cin>>n;

    while(n != -1){
        insert(BT1, n);
        cin>>n;
    }

    bstptr BT2 = NULL;
    cin>>n;

    while(n != -1){
        insert(BT2, n);
        cin>>n;
    }

    queue q;
    q.r = q.f = -1;
    q.size = 30;
    enqueue(q,BT1);

    queue q1;
    q1.r = q1.f = -1;
    q1.size = 30;
    enqueue(q1,BT2);

    int count1 = 0;
    count(BT1,count1);
    int count2 = 0;
    count(BT2, count2);

    sum_two_three(q,q1,count1,count2,BT1,BT2);
    cout<< endl;

    return 0;
}