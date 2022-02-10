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
            q.f = (q.f+1)%q.size;

        return s;
    }
}

void sort(queue &q,int n){
    queue q1,q2;
    q1.f = q1.r = -1;
    q2.f = q2.r = -1;
    q1.size = q2.size = n;

    int temp,min;

    while(q.f != -1){

        temp = dequeue(q);

        if(q.f == 0){
            min = temp;
            enqueue(q1,temp);
        }

        else if(q.f>0 || q.f == -1){
            if(temp < min){
                min = temp;
            }

            enqueue(q1,temp);
        }

        if(q.f == -1){
            enqueue(q2,min);

            while(q1.f != -1){
                int temp1 = dequeue(q1);
                if(temp1 != min)
                    enqueue(q,temp1);
                else
                    continue;
            }
            min = 58962;
        }
    }

    while(q2.f != -1){
        enqueue(q,dequeue(q2));
    }
    
}

int main(){
    queue q;
    q.f = q.r = -1;
    int n;
    cin>>n;

    q.size = n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        enqueue(q,x);
    }
    sort(q,n);

    for(int i=0;i<n;i++){
        cout<< dequeue(q) << " ";
    }
    cout<< endl;

    return 0;
}