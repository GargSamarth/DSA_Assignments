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

        return c;
    }
}

int main(){

    Dequeue dq;
    dq.f = dq.r = -1;
    dq.size = 30;

    int n;
    do{
        
        cout<< "Enter 0 for using queue, enter 1 for using stack, enter 8 for exiting: ";
        cin>>n;
        
        if(n == 0){
            cout<< "Enter 0 for enqueue, enter 1 for dequeue: ";
            int x;
            cin>>x;

            if(x == 0){
                int temp;
                cin>> temp;
                enqueue_rear(dq,temp);
            }
            else if(x == 1)
                cout<<dequeue_rear(dq)<<endl;
        }

        else if(n == 1){
            cout<< "Enter 0 for push, enter 1 for pop: ";
            int x;
            cin>>x;

            if(x == 0){
                int temp;
                cin>> temp;
                enqueue_front(dq,temp);
            }

            else if(x == 1)
                cout<< dequeue_front(dq)<<endl;
        }
    }while(n != 8);

    cout<<endl;
    return 0;
}