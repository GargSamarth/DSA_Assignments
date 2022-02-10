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

struct Mn{
    queue q;
    int sum;
    Mn *next;
};

typedef Mn *lptr;

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

void swap(int &a, int &b){

    int temp = a;  
    a = b;  
    b = temp;  
}  
  
void sort(lptr P)
{  
    int count = 5;

    while(count--){
        lptr T = P;

        while(T->next != NULL){
            if(T->sum > T->next->sum){
                swap(T->sum,T->next->sum);
                queue temp = T->q;
                T->q = T->next->q;
                T->next->q = temp;
            }
            T = T->next;
        }
    }
    
} 

void min_max_and_with_22(queue q, int n){

    bstptr t;
    queue dc;
    dc.r = dc.f = -1;
    dc.size = 20;

    stack print;
    print.top = -1;
    print.size = 20;

    lptr P = new Mn;
    P->next = NULL;

    do{
        t = dequeue(q);
        push(print,t);

        if(t->rchild != NULL && t->lchild != NULL){

            if(!check_discovered(dc, t->lchild)){
                enqueue(q,t->lchild);
            }

            else if(!check_discovered(dc, t->rchild)){
                enqueue(q,t->rchild);
            }

            else{
                bstptr find = pop(print);

                while(print.top != -1 && check_discovered(dc,find)){
                    find = pop(print);
                }
                

                if(!check_discovered(dc,find)){
                    enqueue(dc,find);
                    enqueue(q,find);
                }
            }
        }

        else if(t->rchild != NULL && t->lchild == NULL){

            if(!check_discovered(dc, t->rchild)){
                enqueue(q,t->rchild);
            }

            else{
                bstptr find = pop(print);

                while(print.top != -1 && check_discovered(dc,find)){
                    find = pop(print);
                }
                

                if(!check_discovered(dc,find)){
                    enqueue(dc,find);
                    enqueue(q,find);
                }
            }
        }

        else if(t->rchild == NULL && t->lchild != NULL){

            if(!check_discovered(dc, t->lchild)){
                enqueue(q,t->lchild);
            }

            else{
                bstptr find = pop(print);

                while(print.top != -1 && check_discovered(dc,find)){
                    find = pop(print);
                }
                

                if(!check_discovered(dc,find)){
                    enqueue(dc,find);
                    enqueue(q,find);
                }
            }
        }

        else{

            enqueue(dc,t);
            stack temp;
            temp.top = -1;
            temp.size = 20;

            while(print.top != -1)
                push(temp,pop(print));

            int sum_val = 0;
            lptr T = new Mn;
            T->next = NULL;
            T->q.r = T->q.f = -1;
            T->q.size = 10;

            while(temp.top != -1){
                bstptr temp1 = pop(temp);
                sum_val += temp1->data;
                cout<< temp1->data << " ";
                enqueue(T->q,temp1);
                push(print,temp1);
            }

            T->sum = sum_val;
            lptr temp2 = P;
            cout<< endl;

            while(temp2->next != NULL)
                temp2 = temp2->next;
            temp2->next = T;

            bstptr find = pop(print);

            while(print.top != -1 && check_discovered(dc,find))
                    find = pop(print);
                

            if(!check_discovered(dc,find)){
                enqueue(dc,find);
                enqueue(q,find);
            }
        }

    }while(q.f != -1);
    P = P->next;
    lptr LL = P;
    int i = LL->q.f;

    while(i != LL->q.r+1){
        cout<< LL->q.elements[i++]->data << " ";
    }
    cout<< endl;

    while(LL->next != NULL)
        LL = LL->next;

    i = LL->q.f;
    while(i != LL->q.r+1){
        cout<< LL->q.elements[i++]->data << " ";
    }
    cout<< endl;

    sort(P);
    LL = P;

    while(LL->next != NULL)
        LL = LL->next;

    i = LL->q.f;
    while(i != LL->q.r+1){
        cout<< LL->q.elements[i++]->data << " ";
    }
    cout<< endl;
    
    LL = P;

    i = LL->q.f;
    while(i != LL->q.r+1){
        cout<< LL->q.elements[i++]->data << " ";
    }
    cout<< endl;
    
    LL = P;
    while(LL->sum != n)
        LL = LL->next;

    i = LL->q.f;
    while(i != LL->q.r+1){
        cout<< LL->q.elements[i++]->data << " ";
    }
    cout<< endl;

    LL = P;
    int count = 0;

    while(LL != NULL){

        i = LL->q.f;
        while(i != LL->q.r+1){
            if(LL->q.elements[i++]->data % 2 == 0)
                count++;
        }
        LL->sum = count;
        LL = LL->next;
        count = 0;
    }

    sort(P);
    LL = P;

    while(LL->next != NULL)
        LL = LL->next;

    i = LL->q.f;
    while(i != LL->q.r+1){
        cout<< LL->q.elements[i++]->data << " ";
    }
    cout<< endl;
    
    LL = P;

    i = LL->q.f;
    while(i != LL->q.r+1){
        cout<< LL->q.elements[i++]->data << " ";
    }
    cout<< endl;
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
    q.size = 30;
    enqueue(q,BT);
    min_max_and_with_22(q,22);

    return 0;
}