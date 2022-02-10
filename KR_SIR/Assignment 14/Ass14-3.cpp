#include <iostream>

using namespace std;

int elements[100];

struct queue{
    int size;
    int f;
    int r;
    int k;
    //int elements[50];
};

void enqueue(queue &q, int c, int i){
    if((q.r+1) % ((100/q.k)*(i-1) + q.size) == q.f)
        cout<< "Queue is full"<<endl;

    else{
        if(q.f == -1){
            q.f=(100/q.k)*(i-1);  q.r=(100/q.k)*(i-1);
        }
        else{
            q.r = (q.r+1)%((100/q.k)*(i-1) + q.size);
        }
        elements[q.r] = c;
    }
}

int dequeue(queue &q, int i){
    if(q.f == -1 + (100/q.k)*(i-1)){
        cout<< "Queue is empty"<<endl;
        return -1;
    }
    else{
        int c = elements[q.f];

        if(q.f == q.r){
             q.f = q.r = (100/q.k)*(i-1) - 1;
        }
        else
            q.f = (q.f+1)%((100/q.k)*(i-1) + q.size);

        return c;
    }
}

int main(){

}