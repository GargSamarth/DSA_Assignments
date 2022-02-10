#include <iostream>

using namespace std;

struct ftree{
    char data;
    ftree *child[10];
    int nofch;
};

typedef ftree *ftptr;

struct queue{
    int f,r,size;
    ftptr A[50];
};

void enqueue(queue &q, ftptr x){
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

ftptr dequeue(queue &q){
    if(q.f == -1){
        cout<< "Queue is empty"<<endl;
        return NULL;
    }
    else{
        ftptr temp = q.A[q.f];
        if(q.f == q.r){
             q.f = q.r = -1;
        }
        else
            q.f = (q.f+1)%q.size;
        return temp;
    }
}

void insert(ftptr &FT, char ch){
    if(FT == NULL){
        FT = new ftree;
        FT->data = ch;
        FT->nofch = 0;
    }
    cin>>ch;
    while(ch != '.'){
        insert(FT->child[FT->nofch++],ch);
        cin>>ch;
    }
    return;
}

int count_val(queue q){
    int count = 0;
    queue temp;
    temp.f = temp.r = -1;
    temp.size = 20;

    while(q.f != -1){
        enqueue(temp,dequeue(q));
        count++;
    }

    while(temp.f != -1)
        enqueue(q,dequeue(temp));
    
    return count;
}

bool discovered(queue DT, ftptr ck){
    queue temp;
    temp.f = temp.r = -1;
    temp.size = 10;

    while(DT.f != -1){
        ftptr l = dequeue(DT);
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

void click(ftptr FT){
    queue DT;
    DT.f = DT.r = -1;
    DT.size = 30;
    queue q;
    q.f = q.r = -1;
    q.size = 30;
    enqueue(q,FT);
    int count=0;

    while(count_val(q) != count_val(DT)){
        
        ftptr T = dequeue(q);
        count++;
        while(T != NULL){
            cout<< T->data << endl;
            enqueue(q,NULL);
            enqueue(q,T);
            int max = -1;
            for(int i=0;i< T->nofch ;i++){
                if(!discovered(DT,T->child[i]) && T->child[i]->nofch > max){
                    max = T->child[i]->nofch;
                    enqueue(DT,T->child[i]);
                    enqueue(q,T->child[i]);
                }
            }
            T = dequeue(q);
        }
        cout<< count << endl;
    }
    cout<< count << endl;
}

int main(){
    ftptr FT = NULL;
    char in;
    cin>>in;

    if(in != '.')
        insert(FT,in);

    click(FT);
    return 0;
}