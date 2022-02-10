#include <iostream>

using namespace std;

struct gtnode{
    char data;
    int ino;
    gtnode *fc;
    gtnode *ns;
};

typedef gtnode* gtptr;

struct btnode{
    btnode *rc;
    char data;
    btnode *lc;
};

typedef btnode *btptr;

struct queue{
    int f,r,size=30;
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

int count_children(gtptr T){
    gtptr temp = T->fc;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->ns;
    }
    return count;
}

bool discovered(queue DT, gtptr ck){
    queue temp;
    temp.f = temp.r = -1;
    temp.size = 50;

    while(DT.f != -1){
        gtptr l = dequeue(DT);
        enqueue(temp,l);
        if(ck->data == l->data){
            while(temp.f != -1)
                enqueue(DT,dequeue(temp));
            return true;
        }
    }
    while(temp.f != -1)
        enqueue(DT,dequeue(temp));
    return false;
}

bool child_discovered(queue DT, gtptr ck){
    gtptr T = ck->fc;
    while(T != NULL){
        if(!discovered(DT,T))
            return false;
        T = T->ns;
    }
    return true;
}

int count_val(queue q){
    int count = 0;
    queue temp;
    temp.f = temp.r = -1;
    temp.size = 50;
    while(q.f != -1){
        enqueue(temp,dequeue(q));
        count++;
    }
    while(temp.f != -1)
        enqueue(q,dequeue(temp));
    return count;
}

void print_in_bt(queue q, queue ans,gtptr GT){
    int count=0;
    gtptr dot = new gtnode;
    dot->data = '*';
    dot->fc = dot->ns = NULL;
    queue DT;
    DT.f = DT.r = -1;
    DT.size = 30;
//A B F I . J . . S K . . H . . C . D L M . N . . P . Q . . E . . .
    while(count_val(DT) < 16){
        enqueue(q,GT);
        enqueue(ans,GT);

        while(q.f != -1){
            enqueue(q,dot);
            gtptr gt = dequeue(q);
            enqueue(ans,dot);

            while(gt->data != '*'){
                //cout<< gt->data << "gt->data"<<endl;

                if(gt->fc != NULL){
                    gtptr temp = gt->fc;

                    while(temp != NULL && count < 2){
                        if(!discovered(DT,temp)){
                            enqueue(q,temp);
                            enqueue(ans,temp);
                            count++;
                        }
                        if(temp->fc == NULL)
                            enqueue(DT,temp);
                        temp = temp->ns;
                    }
                }
                count = 0;
                gt = dequeue(q);
            }
        }
        while(ans.f != -1){
            gtptr pt = dequeue(ans);
            if(pt->fc!= NULL && child_discovered(DT,pt))
                enqueue(DT,pt);
            cout<< pt->data << " ";
        }
        cout<< endl;
    }
}

int main(){
    char ch;
    gtptr GT = NULL;
    cin>> ch;
    if(ch != '.')
        insert(GT, ch);

    queue q,ans;
    q.f = q.r = ans.f = ans.r = -1;
    q.size = ans.size = 30;
    print_in_bt(q,ans,GT);
    return 0;
}