#include <iostream>

using namespace std;

union U{
    int x;
    char ch;
    float ft;
};

struct queue{
    int f;
    int r;
    int size;
    U elements[50];
};

void enqueue(queue &q, U a, int tag){
    if((q.r+1)%q.size == q.f)
        cout<< "Queue is full"<<endl;

    else{
        if(q.f == -1){
            q.f=0;  q.r=0;
        }
        else{
            q.r = (q.r+1)%q.size;
        }

        if(tag == 1)
            q.elements[q.r].x = a.x;
        else if(tag == 2)
            q.elements[q.r].ch = a.ch;
        else if(tag == 3)
            q.elements[q.r].ft = a.ft;
    }
}

U dequeue(queue &q){
    U t;
    if(q.f == -1){
        cout<< "Queue is empty"<<endl;
        return t;
    }
    else{
        t = q.elements[q.f];

        if(q.f == q.r){
             q.f = q.r = -1;
        }
        else
            q.f = (q.f+1)%q.size;

        return t;
    }
}

int main(){

}