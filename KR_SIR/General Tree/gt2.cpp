
#include <iostream>

using namespace std;

struct gtnode{
    char data;
    int cno;
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

void insert2(gtptr &T, queue &q){
    int n;
    char ch;

    while(q.f != -1){
        gtptr GT = dequeue(q);

        for(int i=0;i<GT->cno;i++){
            cin>>ch>>n;
            gtptr temp = new gtnode;
            temp->data = ch;
            temp->cno = n;
            temp->fc = temp->ns = NULL;
            if(i == 0)
                GT->fc = temp;
            else{
                gtptr temp1 = GT->fc;
                while(temp1->ns != NULL)
                    temp1 = temp1->ns;
                    
                temp1->ns = temp;
            }
            enqueue(q,temp);
        }
    }
    //print_serial(T);
}



int main(){

    char ch;
    gtptr GT = new gtnode;
    int n;
    queue q;

    cin>> ch >> n;
    GT->cno = n;
    GT->data = ch;
    GT->fc = GT->ns = NULL;
    enqueue(q,GT);
    insert2(GT, q);
    cout<< endl;

    return 0;
}