#include <iostream>

using namespace std;

struct btnode{
    btnode *rc;
    int data;
    btnode *lc;
    int ino;
};

typedef btnode *btptr;

struct queue{
    int size;
    int f;
    int r;
    btptr elements[50];
};

struct stack{
    int size;
    int top;
    btptr A[50];
};

void push(stack &s, btptr x){
    if(s.top == s.size-1)
        cout<< "Stack is full"<<endl;
    else
        s.A[++s.top] = x;
}

btptr pop(stack &s){
    if( s.top == -1){
        cout<< "Stack is empty" << endl;
        return NULL;
    }
    else
        return s.A[s.top--];
}

void enqueue(queue &q, btptr x){
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

btptr dequeue(queue &q){
    if(q.f == -1){
        cout<< "Queue is empty"<<endl;
        return NULL;
    }

    else{

        btptr temp = q.elements[q.f];

        if(q.f == q.r){
             q.f = q.r = -1;
        }
        else
            q.f = (q.f+1)%q.size;

        return temp;
    }
}

void insert(btptr &T, int ch){

    if(T == NULL){
        T = new btnode;
        T->data = ch;
        T->lc = T->rc = NULL;
    }

    cin>>ch;

    if(ch != 0){
        insert(T->lc,ch);
        ch = 0;
    }
        
    if(ch == 0){
        cin>>ch;

        if(ch != 0)
            insert(T->rc, ch);
    }

}

void inorder_numbering(btptr T, int &i){
    if(T != NULL){
        inorder_numbering(T->lc,i);
        i++;
        T->ino = i;
        inorder_numbering(T->rc,i);
    }
}

void semi_tree(queue q, int &count_level){

    btptr dot = new btnode;
    dot->data = 0;
    dot->lc = dot->rc = NULL;
    enqueue(q,dot);

    while(q.f != -1){
        btptr temp = dequeue(q);
        count_level++;
        int count=0;

        while(temp->data != 0){
            count = temp->ino - count - 1;
            int temp1 = count;
            while(temp1--)
                    cout<< " ";
            cout<< temp->data;

            if(temp->lc != NULL)
                enqueue(q,temp->lc);
            if(temp->rc != NULL)
                enqueue(q,temp->rc);

            temp = dequeue(q);
        }

        cout<< endl << endl;

        if(q.f != -1)
            enqueue(q,dot);
    }
}

void full_tree(queue q, int count_level){

    btptr dot = new btnode;
    dot->data = 0;
    dot->lc = dot->rc = NULL;
    enqueue(q,dot);

    int *stem = new int[10];
    int pos = 0;

    while(q.f != -1){
        
        btptr temp = dequeue(q);
        int count = 0;

        while(temp->data != 0){
            count = temp->ino - count - 1;
            int temp1 = count;
            while(temp1--)
                    cout<< " ";
            cout<< temp->data;
            if(temp->lc != NULL){
                enqueue(q,temp->lc);
                stem[pos++] = 1;
                stem[pos++] = temp->lc->ino;
            }
            else
                stem[pos++] = 0;

            if(temp->rc != NULL){
                enqueue(q,temp->rc);
                stem[pos++] = 2;
                stem[pos++] = temp->rc->ino;
            }
            else
                stem[pos++] = 0;

            temp = dequeue(q);
        }
        cout<< endl;
        int count1 = 0;
        int level = count_level;
        count_level--;

        for(int i=0;i<pos;i++){

            if(stem[i] == 1){
                count1 = stem[i+1] - count1;
                int t = count1;
                while(t--)
                    cout<< " ";
                cout<< "/";
                i++;
            }

            else if(stem[i] == 2){
                count1 = stem[i+1] - count1-1;
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

void full_tree_better_version(queue q, int count_level){

    btptr dot = new btnode;
    dot->data = 0;
    dot->lc = dot->rc = NULL;
    enqueue(q,dot);

    int *stem = new int[10];
    int pos = 0;

    while(q.f != -1){
        
        btptr temp = dequeue(q);
        int count = 0;

        while(temp->data != 0){
            count = temp->ino - count - 1;
            int temp1 = count;
            while(temp1--)
                    cout<< " ";
            cout<< temp->data;
            if(temp->lc != NULL){
                enqueue(q,temp->lc);
                stem[pos++] = 1;
                stem[pos++] = temp->lc->ino;
            }
            else
                stem[pos++] = 0;

            if(temp->rc != NULL){
                enqueue(q,temp->rc);
                stem[pos++] = 2;
                stem[pos++] = temp->rc->ino;
            }
            else
                stem[pos++] = 0;

            temp = dequeue(q);
        }
        cout<< endl;
        int count1 = 0;
        int level = count_level;
        count_level--;

        for(int i=0;i<pos;i++){

            if(stem[i] == 1){
                count1 = stem[i+1] - count1;
                int t = count1;
                while(t--)
                    cout<< " ";
                cout<< "/";
                i++;
            }

            else if(stem[i] == 2){
                count1 = stem[i+1] - count1-1;
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

int main() {
    int ch;
    btptr BT = NULL;

    cin>> ch;
    if(ch != 0)
        insert(BT, ch);

    int i=0;
    inorder_numbering(BT,i);

    queue q;
    q.f = q.r = -1;
    q.size = 10;
    enqueue(q,BT);
    cout<< endl << " ---------------------------------- " << endl;
    int count_level = 0;
    semi_tree(q, count_level);

    cout<< " ---------------------------------- " << endl;

    q.f = q.r = -1;
    enqueue(q,BT);
    full_tree(q,count_level-1);
    
    return 0;
}