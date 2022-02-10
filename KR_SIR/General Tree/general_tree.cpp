#include <iostream>

using namespace std;

struct gtnode{
    char data;
    int ino;
    gtnode *fc;
    gtnode *ns;
};

typedef gtnode* gtptr;

struct queue{
    int f,r,size;
    gtptr A[20];
};

void enqueue(queue &q, gtptr x){
    if((q.r+1)%q.size == q.f)
        cout<< "Queue is full"<<endl;
    else{   
        if(q.f == -1){
            q.f=0;  q.r=0;
        }
        else
            q.r = (q.r+1)%q.size;
        q.A[q.r] = x;
    }
}

gtptr dequeue(queue &q){
    if(q.f == -1){
        cout<< "Queue is empty"<<endl;
        return NULL;
    }
    else{
        gtptr temp = q.A[q.f];
        if(q.f == q.r){
             q.f = q.r = -1;
        }
        else
            q.f = (q.f+1)%q.size;
        return temp;
    }
}

void insert(gtptr &GT, char ch){
    if(GT == NULL){
        GT = new gtnode;
        GT->data = ch;
        GT->fc = GT->ns = NULL;
    }
    cin>>ch;
    if(ch != '.'){
        insert(GT->fc,ch);
        ch = '.';
    }  
    if(ch == '.'){
        cin>>ch;
        if(ch != '.')
            insert(GT->ns, ch);
    }
}

// Serialisation
void print_serial(gtptr GT){
    if(GT != NULL){
        cout<< GT->data;
        print_serial(GT->fc);
        print_serial(GT->ns);
    }
    else
        cout<< ".";
}

//With brackets
void print_brac(gtptr GT){
    if(GT != NULL){
        cout<< GT->data << " ";
        if(GT->fc != NULL)
            cout<< "( ";
        print_brac(GT->fc);
        if(GT->ns == NULL)
            cout<< ") ";
        print_brac(GT->ns);
    }
}

//print in level order
void print_level_order(queue q){
    gtptr dot = new gtnode;
    dot->data = '*';
    dot->fc = dot->ns = NULL;
    while(q.f != -1){
        enqueue(q,dot);
        gtptr gt = dequeue(q);
        while(gt->data != '*'){
            cout<< gt->data << " ";
            if(gt->fc != NULL){
                gtptr temp = gt->fc;
                while(temp != NULL){
                    enqueue(q,temp);
                    temp = temp->ns;
                }}
            gt = dequeue(q);}
        cout<< endl;}
}

//height of the tree
void height(gtptr GT, int count, int &max){
    if(GT != NULL){
        if(max < count)
            max = count;
        height(GT->ns,count,max);
        height(GT->fc,count+1,max);
    }
}

//Printing vertically
void print_vertical(gtptr GT, int count){
    if(GT != NULL){
        for(int i=0;i<count;i++)
            cout<< " ";
        cout<< GT->data << endl;
        print_vertical(GT->fc, count+1);
        print_vertical(GT->ns,count);
    }
}

//look like a tree
void inorder_numbering(gtptr T, int &i){
    if(T != NULL){
        inorder_numbering(T->fc,i);
        i++;
        T->ino = i;
        inorder_numbering(T->ns,i);
    }
}

void semi_tree(queue q){
    gtptr dot = new gtnode;
    dot->data = '*';
    dot->fc = dot->ns = NULL;
    enqueue(q,dot);
    while(q.f != -1){
        gtptr temp = dequeue(q);
        int count=0;
        while(temp->data != '*'){
            count = temp->ino - count - 1;
            int temp1 = count;
            while(temp1--)
                    cout<< " ";
            cout<< temp->data;
            if(temp->fc != NULL){
                gtptr temp1 = temp->fc;
                while(temp1 != NULL){
                    enqueue(q,temp1);
                    temp1 = temp1->ns;
                }
            }
            temp = dequeue(q);
        }
        cout<< endl << endl;
        if(q.f != -1)
            enqueue(q,dot);
    }
}

int main(){

    char ch;
    gtptr GT = NULL;

    cin>> ch;
    if(ch != '.')
        insert(GT, ch);
    cout<< "=====Serialisation====="<<endl;
    print_serial(GT);
    cout<< endl << "=====With Brackets====="<<endl;
    print_brac(GT);
    cout<< endl << "=====Level Order====="<<endl;
    queue q;
    q.f = q.r = -1;
    q.size = 10;
    enqueue(q,GT);
    print_level_order(q);
    int max=0;
    cout<< endl << "=====Height of the Tree====="<<endl;
    height(GT,0,max);
    cout<< "Height of the Tree is: "<< max<< endl;
    cout<< "=====Print Tree Vertically====="<<endl;
    print_vertical(GT,0);
    cout<< endl << "=====Look link a tree====="<<endl;
    int i = 0;
    inorder_numbering(GT,i);
    semi_tree(q);
    cout<< endl;

    return 0;
}