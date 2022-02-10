#include <iostream>

using namespace std;

struct queue{
    int size;
    int f;
    int r;
    int elements[50];
};

void enqueue(queue &q, int c){
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

int dequeue(queue &q){
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

void bubble_sort(int *A, int n){
    queue q;
    q.r = q.f = -1;
    q.size = n;

    for(int i=0;i<n;i++)
        enqueue(q,A[i]);
}