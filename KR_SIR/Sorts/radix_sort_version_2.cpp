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

int max_term2(int *A, int n){
    int max = A[0];

    for(int i=1;i<n;i++){
        if(A[i] > max)
            max = A[i];
    }
    return max;    
}


void bucket_sort(int *A, int n, int num, int denom){
    int buckets_size = 1;

    queue *q = new queue [10];

    for(int i=0;i<10;i++){
        q[i].r = q[i].f = -1;
        q[i].size = 10;
    }

    for(int j=1;j<=10;j++){
        for(int i=0;i<n;i++)
            if( (A[i]/denom)%num < j*buckets_size && (A[i]/denom)%num >= (j-1)*buckets_size )
                enqueue(q[j-1] , A[i]);
    }

        int i = 0;
        for(int j=0;j<10;j++){
            while(q[j].f != -1){
                A[i++] = dequeue(q[j]);
                //cout<<A[i-1]<<"--------A[i]"<<endl;
            }
        }
}

int *radix_sort(int *A, int n){

    int *B =new int [n];
    int max = max_term2(A,n)*10;
    int denom = 1, num = 10;

    while(max>0){
        bucket_sort(A,n,num,denom);
        denom*=10;
        max = max/10;
    }
    // for(int i=0;i<n;i++)
    //     B[i] = A[n-1-i];

    return A;
}

int main(){
    int n;
    cin>>n;

    int *A = new int [n+1];

    for(int i=0;i<n;i++)
        cin>> A[i];

    //int *B = new int [n];
    A = radix_sort(A,n);

    for(int i=0 ; i<n; i++)
        cout<< A[i] << " ";

    cout<< endl;

    return 0;

}