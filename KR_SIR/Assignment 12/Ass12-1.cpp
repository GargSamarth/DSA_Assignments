#include <iostream>

using namespace std;

struct queue{
    int size;
    int f;
    int r;
    int elements[50];
};

void enqueue(queue &q, int s){
    if((q.r+1)%q.size == q.f)
        cout<< "Queue is full"<<endl;

    else{
        if(q.f == -1){
            q.f=0;  q.r=0;
        }
        else{
            q.r = (q.r+1)%q.size;
        }
        q.elements[q.r] = s;
    }
}

int dequeue(queue &q){
    if(q.f == -1){
        cout<< "Queue is empty"<<endl;
        return 0;
    }
    else{
        int s = q.elements[q.f];

        if(q.f == q.r){
             q.f = q.r = -1;
        }
        else
            q.f++;

        return s;
    }
}

void push(queue &q, int x){

    if((q.r+1)%q.size == q.f)
        cout<< "Queue is full"<<endl;

    else{
        queue q2;
        q2.f = q2.r = -1;
        q2.size = q.size;
        if(q.f == -1){
            enqueue(q,x);
        }
        else{
            while(q.f != -1)
                enqueue(q2,dequeue(q));

            enqueue(q,x);

            while(q2.f != -1)
                enqueue(q,dequeue(q2));
        }
    }
}

int pop(queue &q){
    if(q.f == -1){
        cout<< "Queue is empty"<<endl;
        return 0;
    }
    else{
        return dequeue(q);
    }
}

int main(){
    queue q;
    q.r = q.f = -1;
    q.size = 50;
    int n;
    do{
        cout<< "Enter 0 for pushing, 1 for poping and 7 for exiting: ";
        cin>>n;

        if(n == 0){
            int x;
            cin>>x;
            push(q,x);
        }
        else if(n == 1)
            cout<< pop(q)<<endl;

    }while(n != 7);
    return 0;
}