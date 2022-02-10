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
    gtptr A[100];
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
    temp.size = 100;

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

void click(queue q){
    int max=-1,count=0;
    gtptr dot = new gtnode;
    dot->data = '*';
    dot->fc = dot->ns = NULL;
    queue DT;
    DT.f = DT.r = -1;
    DT.size = 100;
    
    while(q.f != -1){
        enqueue(q,dot);
        gtptr gt = dequeue(q);
        
        gtptr max_ptr = NULL;
        count++;
        while(gt->data != '*'){
            enqueue(DT,gt);

            if(gt->fc != NULL){
                
                gtptr temp = gt->fc;
                while(temp != NULL){
                    if(!discovered(DT,temp) && count_children(temp) > max){
                        max = count_children(temp);
                        max_ptr = temp;
                    }
                    temp = temp->ns;
                }
                if(max_ptr != NULL){
                    enqueue(q,max_ptr);
                    enqueue(q,gt);
                }
            }
            max_ptr = NULL;
            max = -1;
            gt = dequeue(q);
        }
    }
    cout<< count-1 << endl;
}

int main(){

    char ch;
    gtptr GT = NULL;

    cin>> ch;
    if(ch != '.')
        insert(GT, ch);

    queue q;
    q.f = q.r = -1;
    q.size = 30;
    enqueue(q,GT);
    click(q);
    return 0;
}