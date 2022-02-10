#include <iostream>

using namespace std;

struct Dequeue{
    int size;
    int f;
    int r;
    int elements[50];
};

void enqueue_rear(Dequeue &q, int c){
    if((q.r+1)%q.size == q.f)
        cout<< "Queue is full"<<endl;

    else{
        if(q.f == -1){
            q.f=0;  q.r=0;
        }
        else{
            q.r = (q.r+1)%q.size;
        }
        q.elements[q.r] = c;
    }
}

void enqueue_front(Dequeue &q, int c){
    if( ( q.size - 1 + (q.f) % q.size ) % q.size == q.r )
        cout<< "Queue is full"<<endl;

    else{
        if(q.f == -1){
            q.f = q.r = q.size-1;
        }
        else{
            q.f = ( q.size - 1 + (q.f) % q.size ) % q.size;
        }
        q.elements[q.f] = c;
    }
}

int dequeue_front(Dequeue &q){
    if(q.f == -1){
        cout<< "Queue is empty"<<endl;
        return -1;
    }

    else{
        int c = q.elements[q.f];

        if(q.f == q.r){
             q.f = q.r = -1;
        }
        else
            q.f = (q.f+1)%q.size;

        return c;
    }
}

int dequeue_rear(Dequeue &q){
    if(q.f == -1){
        cout<< "Queue is empty"<<endl;
        return -1;
    }
    else{
        int c = q.elements[q.r];

        if(q.f == q.r){
             q.f = q.r = -1;
        }
        else
            q.r = ( q.size - 1 + (q.r) % q.size ) % q.size;
            //q.r = q.size - (q.r+1)%q.size;

        return c;
    }
}

int main(){
    Dequeue dq;
    dq.r = dq.f = -1;
    dq.size = 10;
    
    int n;
    do{
        cout<< "0: enqueue_front; 1: enqueue_rear; 2: dequeue_front; 3: dequeue_rear; 4:exit ";
        cin>>n;

        if(n == 0){
            int x;
            cin>>x;
            enqueue_front(dq,x);
        }
        else if(n == 1){
            int x;
            cin>>x;
            enqueue_rear(dq,x);
        }
        else if(n == 2){
            cout<< dequeue_front(dq)<<endl;
        }
        else if(n == 3){
            cout<< dequeue_rear(dq)<<endl;
        }
    }while(n != 4);

    return 0;

}