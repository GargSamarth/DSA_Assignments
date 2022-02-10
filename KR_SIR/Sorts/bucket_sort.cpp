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
        //cout<< "Queue is empty"<<endl;
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

int max_term(queue q){
    int max = dequeue(q);

    while(q.f != -1){
        int x = dequeue(q);
        if(x > max)
            max = x;
    }
    return max;    
}

int max_term2(int *A, int n){
    int max = A[0];

    for(int i=1;i<n;i++){
        if(A[i] > max)
            max = A[i];
    }
    return max;    
}

void count_sort(queue &q){

    int max = max_term(q)+1;
    int *fr = new int [max];

    for(int i=0 ; i<max ; i++)
        fr[i] = 0;

    queue q1;
    q1.f = q1.r = -1;
    q1.size = q.size;

    while(q.f != -1){
        int x = dequeue(q);
        fr[x]++;
        enqueue(q1,x);
    }
    
    for(int i=2 ; i<max ; i++){
        fr[i] = fr[i] + fr[i-1];
    }

    int n = q1.r+1;
    int *B = new int [n+1];
    int x;

    while(q1.f != -1){
        int temp = dequeue(q1);
        x = fr[temp];
        B[x] = temp;

        fr[temp] = fr[temp] - 1;
    }

    
    for(int i=1;i<n+1;i++)
        enqueue(q,B[i]);
    delete B;
}

int no_of_buckets(int *A, int n){
    n = max_term2(A , n);

    if(n%6 != 0)
        return (6 - n % 6 + n);
    else 
        return n;
}

void bucket_sort(int *A, int n){
    int buckets_size = (no_of_buckets(A,n)/6) + 1;

    queue *q = new queue [6];

    for(int i=0;i<6;i++){
        q[i].r = q[i].f = -1;
        q[i].size = 10;
    }

    for(int j=1;j<=6;j++){
        for(int i=0;i<n;i++)
            if( A[i] < j*buckets_size && A[i] >= (j-1)*buckets_size )
                enqueue(q[j-1] , A[i]);
    }

    for(int i=0;i<6;i++)
        count_sort(q[i]);

        int i = 0;
        for(int j=0;j<6;j++){
            while(q[j].f != -1)
                A[i++] = dequeue(q[j]);
        }
}

int main(){
    int n;
    cin>>n;

    int *A = new int [n];

    for(int i=0;i<n;i++)
        cin>>A[i];
    
    bucket_sort(A,n);

    for(int i=0;i<n;i++)
        cout<< A[i]<< " ";

    cout<< endl;

    return 0;
}