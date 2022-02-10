#include <iostream>

using namespace std;

struct coordinates{
    int i;
    int j;
};

struct queue{
    int size;
    int f;
    int r;
    coordinates elements[50];
};

void enqueue(queue &q, coordinates c){
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

coordinates dequeue(queue &q){
    coordinates c;
    if(q.f == -1){
        cout<< "Queue is empty"<<endl;
        c.i = c.j= -1;
        return c;
    }
    else{
        c.i = q.elements[q.f].i;
        c.j = q.elements[q.f].j;

        if(q.f == q.r){
             q.f = q.r = -1;
        }
        else
            q.f = (q.f+1)%q.size;

        return c;
    }
}

bool is_positive(int n){
    if(n > 0)
        return true;
    else
        return false;
}

void make_positive(queue &q, int A[4][5], int &count){
    
    while(q.r != -1){
        coordinates c;
        c = dequeue(q);

        int flag = 0;
    if( c.i > 0 && A[c.i-1][c.j] < 0){
        A[c.i-1][c.j] = -A[c.i-1][c.j];
        flag = 1;
    }
    
    if( c.i < 3 && A[c.i+1][c.j] < 0){
        A[c.i+1][c.j] = -A[c.i+1][c.j];
        flag = 1;
    }

    if( c.j > 0 && A[c.i][c.j-1] < 0){
        A[c.i][c.j-1] = -A[c.i][c.j-1];
        flag = 1;
    }

    if( c.j < 4 && A[c.i][c.j-1] < 0){
        A[c.i][c.j-1] = -A[c.i][c.j-1];
        flag = 1;
    }
    
    if(flag == 1)
        count++;

    }
}

int main(){

    int A[4][5] = {
                    {-1, -9, 0, -1, 0},
                    {-8, -3, -2, 9, -7},
                    {2, 0, 0, -6, 0},
                    {0, -7, -3, 5, -4}
                };

    int count = 0;
    queue q;
    q.r = q.f = -1;
    q.size = 4*5;

    for(int i=0;i<4;i++){
        for(int j=0;j<5;j++){
            if(is_positive(A[i][j])){
                coordinates c;
                c.i = i;
                c.j = j;
                enqueue(q,c);
            }
        }
    }
    make_positive(q,A,count);

    cout<< count<<endl;
    return 0;
}
